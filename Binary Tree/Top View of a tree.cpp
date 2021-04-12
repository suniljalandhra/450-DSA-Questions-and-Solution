// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        vector<int> res = topView(root);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void fillmap(struct Node* root,int d,int l,map<int,pair<int,int>> &m){
    if(!root)return;
    if(m.count(d)==0)m[d] = make_pair(root->data,l);
    else if(m[d].second > l)m[d]=make_pair(root->data,l);
    fillmap(root->left,d-1,l+1,m);
    fillmap(root->right,d+1,l+1,m);
}
vector<int> topView(struct Node *root)
{
    //Your code here
    vector<int> result;
    map<int,pair<int,int>> m;
    fillmap(root,0,0,m);
    for(auto it=m.begin();it!=m.end();it++){
        result.push_back(it->second.first);
    }
  return result;

}
