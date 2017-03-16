#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1001;
int a[maxn],f[maxn];
int tt,t,n,m;

bool check(int k){
  int q[4],n=0;
  for (;k;k/=10) q[n++]=k%10;
  for (int i=0;i<n/2;i++)
    if (q[i]!=q[n-i-1]) return 0;
  return 1;
}

int main(){
  int i,j;
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  scanf("%d",&t);
  for (i=1;i*i<maxn;i++)
    if (check(i) && check(i*i)) f[i*i]=++m;
  for (i=1;i<maxn;i++)
    if (!f[i]) f[i]=f[i-1];
  for (tt=1;tt<=t;tt++){
    scanf("%d%d",&n,&m);
    printf("Case #%d: %d\n",tt,f[m]-f[n-1]);
  }
  return 0;
}
