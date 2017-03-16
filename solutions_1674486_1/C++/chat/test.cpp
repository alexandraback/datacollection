#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool isfound(vector<int>* v,int d){
    int len,i;
    len=v->size();
    
    for(i=0;i<len;i++) 
        if((*v)[i]==d)
            return true;
    return false;
}

void run(){
    int N,m;
    vector<int>* A;

    
    cin>>N;
    A=new vector<int>[N];
    int i,j;
    int x;
    for(i=0;i<N;i++){
        cin>>m;
        for(j=0;j<m;j++){
            cin>>x;
            A[i].push_back(x-1);
        }
    }
    
    //cout<<"h1";
    int k;
    queue<int> q;
    for(i=0;i<N;i++){
        
        vector<int> A1(A[i]);
        while(!q.empty()) q.pop();
        
        for(j=0;j<A1.size();j++)
            q.push(A1[j]);
        
        while(!q.empty()){
            k=q.front();
            q.pop();
            //cout<<k;
            for(j=0;j<A[k].size();j++){
                if(isfound(&A1,A[k][j])){
                    cout<<"Yes";
                    return;
                }else{
                    A1.push_back(A[k][j]);
                    q.push(A[k][j]);
                }
            }
            
        }
        //cout<<endl;
    }
    cout<<"No";
}

int main(){
    int n,i;
    
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<"Case #"<<i<<": ";
        run();
        cout<<endl;
    }
    
    return 0;
}
