#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;
const int N=1111;
int T,C,nn,n,m,ans,i,j,x,y,f[N],b[N],g[N],v[N],nxt[N],ed;
map<string,int>A,B;
int ga(){
  string c;
  cin>>c;
  int&t=A[c];
  if(t)return t;
  return t=++n;
}
int gb(){
  string c;
  cin>>c;
  int&t=B[c];
  if(t)return t;
  return t=++m;
}
bool find(int x){
  for(int i=g[x];i;i=nxt[i])if(!b[v[i]]){
    b[v[i]]=1;
    if(!f[v[i]]||find(f[v[i]]))return f[v[i]]=x,1;
  }
  return 0;
}
int main(){
  cin>>T;
  while(T--){
    cin>>nn;
    ans=nn;
    while(nn--){
      x=ga();
      y=gb();
      v[++ed]=y;nxt[ed]=g[x];g[x]=ed;
    }
    ans-=n+m;
    for(j=1;j<=m;j++)f[j]=0;
    for(i=1;i<=n;i++){
      for(j=1;j<=m;j++)b[j]=0;
      if(find(i))ans++;
    }
    printf("Case #%d: %d\n",++C,ans);
    for(i=1;i<=n;i++)g[i]=0;
    n=m=ed=0;
    A.clear(),B.clear();
  }
  return 0;
}