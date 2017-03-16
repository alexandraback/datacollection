#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=10002;
ll a[maxn];
int t,tt,e,r,n;
ll ans;

void dfs(int k,int ee,ll s){
  if (k==n){
    ans=max(ans,s);
    return ;
  }
  for (int i=0;i<=ee;i++) dfs(k+1,min(ee-i+r,e),s+i*a[k]);
}

int main(){
  int i;
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  scanf("%d",&t);
  for (tt=1;tt<=t;tt++){
    scanf("%d%d%d",&e,&r,&n);
    for (i=0;i<n;i++) scanf("%lld",&a[i]);
    ans=0;
    dfs(0,e,0);
    printf("Case #%d: %lld\n",tt,ans);
  }
  return 0;
}
