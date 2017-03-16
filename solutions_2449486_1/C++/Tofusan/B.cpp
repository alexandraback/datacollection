#include <stdio.h>
#include <stdlib.h>

int t;
int rows,cols;
int mr[101];
int mc[101];
int A[101][101];
void init()
{
 for(int i=1;i<=cols;i++)
 {
  mc[i]=0;
 }
 for(int i=1;i<=rows;i++)
 {
  mr[i]=0;
 }
}
int mins(int a,int b)
{
 if(a<b){return a;}
 return b;
}
bool solve()
{
int tmp;
 for(int i=1;i<=rows;i++)
 {
  for(int j=1;j<=cols;j++)
  {
   tmp=mins(mc[j],mr[i]);
   if(tmp!=A[i][j]){return false;}
  }
 }
 return true;
}
main()
{
 freopen("B-large.in","r",stdin);
 freopen("B-large.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%d%d",&rows,&cols);
  init();
  for(int i=1;i<=rows;i++)
  {
   for(int j=1;j<=cols;j++)
   {
    scanf("%d",&A[i][j]);
    if(A[i][j]>mr[i]){mr[i]=A[i][j];}
    if(A[i][j]>mc[j]){mc[j]=A[i][j];}
   }
  }
  printf("Case #%d: ",tests);
  if(solve()){printf("YES\n");}
  else{printf("NO\n");}
 }
 return 0;
}
