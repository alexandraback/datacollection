#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define N 52
string w[N];
vector<int> a[N];
bool v[N];
bool mark[N][N];
bool h[N][N][N];
int p[N];
int t,tt,n,m;
string ans;

void dfs(int k,int s,string cur){
  if (s==n){
    if (ans=="") ans=cur;
    else ans=min(ans,cur);
    return ;
  }
  //cout<<k<<"  "<<s<<"  "<<cur<<endl;
  for (int i=0;i<a[k].size();++i){
    int j=a[k][i];
    if (!mark[k][j]){
      if (!v[j]){
        v[j]=1;
        mark[k][j]=1;
        p[j]=k;
        dfs(j,s+1,cur+w[j]);
        v[j]=0;
        mark[k][j]=0;
      }
      else if (j==p[k] && !h[k][j][s]){
        h[k][j][s]=1;
        dfs(j,s,cur);
        h[k][j][s]=0;
      }
    }
  }
}

int main(){
  int i,j;
  freopen("1.txt","r",stdin);
  freopen("2.txt","w",stdout);
  scanf("%d",&t);
  for (tt=1;tt<=t;++tt){
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i) cin>>w[i];
    memset(a,0,sizeof(a));
    while (m--){
      scanf("%d%d",&i,&j);
      a[i].push_back(j);
      a[j].push_back(i);
    }
    ans="";
    for (i=1;i<=n;++i){
      v[i]=1;
      dfs(i,1,w[i]);
      v[i]=0;
    }
    printf("Case #%d: ",tt);
    cout<<ans<<endl;
  }
  return 0;
}