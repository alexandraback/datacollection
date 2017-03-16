#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5;
char a[maxn][maxn];
int t,tt;
bool flag;

int check(){
  int i,j;
  for (i=0;i<4;i++)
     if (a[i][i]=='O' || a[i][i]=='.') break;
  if (i==4) return 1;
  for (i=0;i<4;i++)
     if (a[i][3-i]=='O' || a[i][3-i]=='.') break;
  if (i==4) return 1;
  for (i=0;i<4;i++)
     if (a[i][i]=='X' || a[i][i]=='.') break;
  if (i==4) return 2;
  for (i=0;i<4;i++)
     if (a[i][3-i]=='X' || a[i][3-i]=='.') break;
  if (i==4) return 2;
  for (i=0;i<4;i++){
    for (j=0;j<4;j++)
      if (a[i][j]=='O' || a[i][j]=='.') break;
    if (j==4) return 1;
    for (j=0;j<4;j++)
      if (a[j][i]=='O' || a[j][i]=='.') break;
    if (j==4) return 1;
    for (j=0;j<4;j++)
      if (a[i][j]=='X' || a[i][j]=='.') break;
    if (j==4) return 2;
    for (j=0;j<4;j++)
      if (a[j][i]=='X' || a[j][i]=='.') break;
    if (j==4) return 2;
  }
  return 0;
}

int main(){
  int i,j;
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf("%d",&t);
  for (tt=1;tt<=t;tt++){
    flag=0;
    for (i=0;i<4;i++){
      scanf("%s",a[i]);
      for (j=0;j<4;j++)
        if (a[i][j]=='.') flag=1;
    }
    i=check();
    if (i==1) printf("Case #%d: X won\n",tt);
    else if (i==2) printf("Case #%d: O won\n",tt);
    else if (flag) printf("Case #%d: Game has not completed\n",tt);
    else printf("Case #%d: Draw\n",tt);
  }
  return 0;
}
