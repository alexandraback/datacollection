#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int T;cin>>T;
  for(int t=0;t<T;t++){
    ll b,m,a[10000]; cin>>b>>m;
    a[0]=1; for(int i=1;i<100;i++)a[i]=a[i-1]*2;
    reverse(a,a+b-2);
    bool grid[1000][1000]; memset(grid,0,sizeof grid);
    for(int i=1;i<b-1;i++)grid[i][b-1]=1;
    for(int i=1;i<b-1;i++)for(int j=i+1;j<b-1;j++)grid[i][j]=1;
    for(int i=0;i<b-2;i++){
      if(m>=a[i])m-=a[i],grid[0][i+1]=1;
      if(m==0)break;
    }
    if(m==1)grid[0][b-1]=1,m--;
    cout<<"Case #"<<t+1<<": ";
    if(m==0){
      cout<<"POSSIBLE"<<endl;
      for(int i=0;i<b;i++){for(int j=0;j<b;j++)cout<<grid[i][j]; cout<<endl;}
    }else cout<<"IMPOSSIBLE"<<endl;
  }
}
