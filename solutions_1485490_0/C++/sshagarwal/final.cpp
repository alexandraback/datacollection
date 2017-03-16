#include <iostream>
#include <cstring>

using namespace std;
 
int t,n,m;
long long int tp[2][115],cant[2][115],bst[115][115],rez;

inline void back(int i,int j,long long int myway) {
    rez=max(rez,myway);
    if(myway<bst[i][j]) return;
    bst[i][j]=myway;
    
    if(i>n || j>m) return;
    if(tp[0][i]==tp[1][j]) {
        long long int cc=min(cant[0][i],cant[1][j]);
        if(cant[0][i]<cant[1][j]) {
            cant[1][j]-=cc;
            back(i+1,j,myway+cc);
            cant[1][j]+=cc;
        }
        else if(cant[0][i]==cant[1][j]) back(i+1,j+1,myway+cc);
        else {
            cant[0][i]-=cc;
            back(i,j+1,myway+cc);
            cant[0][i]+=cc;
        }
    }
    back(i+1,j,myway);
    back(i,j+1,myway);
}
 
int main()
{
    
    cin>>t;
    for(int k=1; k<=t; k++) {
        cin>>n>>m;
        memset(bst,0,sizeof(bst));
        memset(bst,0,sizeof(bst));
        for(int i=1; i<=n; ++i) cin>>cant[0][i]>>tp[0][i];
        for(int i=1; i<=m; ++i) cin>>cant[1][i]>>tp[1][i];
        rez=0;
        back(1,1,0);
        
        cout<<"Case #"<<k<<": "<<rez<<'\n';
       
    }
    return 0;
}
