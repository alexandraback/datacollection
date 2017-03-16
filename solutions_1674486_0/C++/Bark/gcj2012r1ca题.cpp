// gcj2012r1ca题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
int a[105][105];
int b[105][105];
int main()
{
	freopen("in.txt","r",stdin);
    freopen("out5.txt","w",stdout);
  int t,n,i,j,k,tt,m,t1;
  scanf("%d",&t);
  for(tt=1;tt<=t;tt++)
  {
	  printf("Case #%d: ",tt);
	  memset(a,0,sizeof(a));
	  memset(b,0,sizeof(b));
      scanf("%d",&n);
	  for(i=1;i<=n;i++)
	  {
		  scanf("%d",&m);
		  for(j=1;j<=m;j++)
		  {
          scanf("%d",&t1);
		  a[i][t1]=1;
		  }
	  }
	  int tag=0;
      for(k=1;k<=n&&!tag;k++)
		  for(i=1;i<=n&&!tag;i++)
			  for(j=1;j<=n&&!tag;j++)
			  {
				  if(i==j||i==k||k==j)
					  continue;
				  if(a[i][k]&&a[k][j])
				  {
					  a[i][j]++;
					  if(a[i][j]>=2)
					  {
						  tag=1;
						  break;
					  }
				  }
			  }
			  
			/*  for(i=1;i<=n;i++)
			  for(j=1;j<=n;j++)
			  {
				  if(a[i][j]>=2)
				  {
					  tag=1;
					  break;
				  }
			  }*/
	  if(tag)
		  printf("Yes\n");
	  else
		  printf("No\n");
  }
  return 0;
}
