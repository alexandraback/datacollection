#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
long long x,y;
int mat[100][100];
void solve(){
    memset(mat,0,sizeof mat);
    if(y>(1<<(x-2))){
        cout<<"Impossible"<<endl;
        return;
    }
    cout<<"Possible"<<endl;
    int i,j;
    if(y==(1<<(x-2))){
        for(i=2;i<=x;i++)
            mat[1][i]=1;
    }
    else{
        for(i=x-1;i>=1;i--){
            mat[1][i]=(y&1);
            y>>=1;
        }
    }
    for(i=2;i<=x;i++)
        for(j=i+1;j<=x;j++)
            mat[i][j]=1;
    for(i=1;i<=x;i++,cout<<endl)
        for(j=1;j<=x;j++)
            cout<<mat[i][j];
}
int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int i,t;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>x>>y;
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
