#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=202;
bool a[maxn][maxn];
int t,tt,n,m;

bool check(){
  int i,j,k;
    for (k=1;k<=n;k++)
      for (i=1;i<=n;i++)
      if (i!=k)
        for (j=1;j<=n;j++)
        if (j!=k)
        if (a[i][k] && a[k][j]){
          if (a[i][j]) return 1;
          a[i][j]=a[i][k] && a[k][j];
        }
    return 0;
}

int main(){
  int i,j,k;
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  scanf("%d",&t);
  for (tt=1;tt<=t;tt++){
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++){
      scanf("%d",&m);
      for (j=1;j<=m;j++){
        scanf("%d",&k);
        a[k][i]=1;
      }
    }
    printf("Case #%d: ",tt);
    if (check()) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
