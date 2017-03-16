#include<stdio.h>
int a[105][105],des[105][105];
int main()
{
  int t,i,r,c,j,k,max;
  scanf("%d",&t);
  for(i=1;i<=t;i++)
    {
      scanf("%d %d",&r,&c);
      for(j=0;j<r;j++)
	for(k=0;k<c;k++)
	  {
	    a[j][k]=100;
	    scanf("%d",&des[j][k]);
	  }
      for(j=0;j<r;j++)
	{
	  max=0;
	  for(k=0;k<c;k++)
	    if(des[j][k]>max)
	      max=des[j][k];
	  for(k=0;k<c;k++)
	    {
	      if(a[j][k]>=max)
		a[j][k]=max;
	    }
	}
      for(j=0;j<c;j++)
	{
	  max=0;
	  for(k=0;k<r;k++)
	    if(des[k][j]>max)
	      max=des[k][j];
	  for(k=0;k<r;k++)
	    if(a[k][j]>=max)
	      a[k][j]=max;
	}
      printf("Case #%d: ",i);
      for(j=0;j<r;j++)
	{
	  for(k=0;k<c;k++)
	    if(a[j][k]!=des[j][k])
	      break;
	  if(k<c)
	    break;
	}
      if(j<r)
	printf("NO\n");
      else
	printf("YES\n");
    }
  return 0;
}
