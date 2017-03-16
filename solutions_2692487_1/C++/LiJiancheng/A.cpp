#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=102;
int a[maxn];
int t,tt,m,n,ans;

void dfs(int m,int k,int s){
  if (k==n){
    ans=min(ans,s);
    return ;
  }
  if (a[k]<m) dfs(m+a[k],k+1,s);
  else {
    if (2*m-1>m){
      int mm=m,ss=s;
      while (mm<=a[k]) mm+=mm-1,ss++;
      dfs(mm+a[k],k+1,ss);
    }
    dfs(m,k+1,s+1);
  }
}

int main(){
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf("%d",&t);
  for (tt=1;tt<=t;tt++){
    scanf("%d%d",&m,&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    ans=1<<30;
    dfs(m,0,0);
    printf("Case #%d: %d\n",tt,ans);
  }
  return 0;
}
