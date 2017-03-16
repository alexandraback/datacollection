#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll maxn=100000000000000LL;
ll f[50],n,m;
int tt,t,s;

bool check(ll k){
  int q[15],n=0;
  for (;k;k/=10) q[n++]=k%10;
  for (int i=0;i<n/2;i++)
    if (q[i]!=q[n-i-1]) return 0;
  return 1;
}

int main(){
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  for (ll i=1;i*i<maxn;i++)
    if (check(i) && check(i*i)) f[s++]=i*i;
  scanf("%d",&t);
  for (tt=1;tt<=t;tt++){
    scanf("%lld%lld",&n,&m);
    int i=lower_bound(f,f+s,n)-f; 
    int j=lower_bound(f,f+s,m)-f;
    if (f[j]==m) j++;
    printf("Case #%d: %d\n",tt,j-i);
  }
  return 0;
}
