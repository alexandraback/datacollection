//gskhirtladze

#include <iostream>
#include <stdio.h>

using namespace std;

int ans_r[100000][17];
int ans_l[100000][17];
int ind_r[100000][17];
int ind_l[100000][17];
int need[100000];
int al[100000];
int n,x,y,m,i,k;
long long res;

main()
 {
  scanf("%d",&n);
  for (i=0;i<n;i++)
   scanf("%d",&ans_l[i][0]),ans_r[i][0]=ans_l[i][0],ind_r[i][0]=ind_l[i][0]=i;
  for (k=1;k<=16;k++)
   for (i=0;i<n;i++)
    {
     ans_l[i][k]=max(ans_l[i][k-1],ans_l[min(n-1,i+(1<<(k-1)))][k-1]);
     ans_r[i][k]=max(ans_r[i][k-1],ans_r[max(0,i-(1<<(k-1)))][k-1]);
     if (ans_l[i][k-1] > ans_l[min(n-1,i+(1<<(k-1)))][k-1])
      {
       ans_l[i][k]=ans_l[i][k-1];
       ind_l[i][k]=ind_l[i][k-1];
      } else
      {
       ans_l[i][k]=ans_l[min(n-1,i+(1<<(k-1)))][k-1];
       ind_l[i][k]=ind_l[min(n-1,i+(1<<(k-1)))][k-1];
      }
     if (ans_r[i][k-1] > ans_r[max(0,i-(1<<(k-1)))][k-1])
      {
       ans_r[i][k]=ans_r[i][k-1];
       ind_r[i][k]=ind_r[i][k-1];
      } else
      {
       ans_r[i][k]=ans_r[max(0,i-(1<<(k-1)))][k-1];
       ind_r[i][k]=ind_r[max(0,i-(1<<(k-1)))][k-1];
      }
    }
  for (i=0;i<n;i++)
   for (k=0;k<=16;k++)
    if (2*(1<<k) > i+1) { need[i]=k; break; }
  scanf("%d%d%d",&m,&x,&y);
  for (i=1;i<=m;i++)
   {
    (x>=y)?
         ((ans_l[y][need[x-y]]>ans_r[x][need[x-y]])?(al[ind_l[y][need[x-y]]]++):(al[ind_r[x][need[x-y]]]++)):
         ((ans_l[x][need[y-x]]>ans_r[y][need[y-x]])?(al[ind_l[x][need[y-x]]]++):(al[ind_r[y][need[y-x]]]++));
    x=(x+8>=n)?(x+8-n):(x+7);
	y=(y+11>=n)?(y+11-n):(y+11);
   }
   return 0;
  cout<<res<<endl;
 }
