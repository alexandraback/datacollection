#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=102;
int a[maxn][maxn];
bool flag;
int t,tt,n,m;

bool check(int x,int y){
  int i;
  for (i=0;i<n;i++)
    if (a[i][y]>a[x][y]) break;
  if (i==n) return 0;
  for (i=0;i<m;i++)
    if (a[x][i]>a[x][y]) break;
  if (i==m) return 0;
  return 1;
}

int main(){
  int i,j;
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  scanf("%d",&t);
  for (tt=1;tt<=t;tt++){
    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++)
      for (j=0;j<m;j++) scanf("%d",&a[i][j]);
    flag=1;
    for (i=0;i<n;i++)
      for (j=0;j<m;j++)
        if (check(i,j)){
          flag=0;
          break;
        }
    if (flag) printf("Case #%d: YES\n",tt);
    else printf("Case #%d: NO\n",tt);
  }
  return 0;
}
