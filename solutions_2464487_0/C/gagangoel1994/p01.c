#include <stdio.h>
#define check 1
int main()
{
  if(check)
    {
      freopen("A-small-attempt1.in","r",stdin);
      freopen("a.in","w",stdout);
    }
  int T,r,t;
  int i,j,a,b,count;
  scanf("%d",&T);
  for (i=0;i<T;i++)
    {
      count=0;
      scanf("%d%d",&r,&t);
      while (t>0)
	{
	  a=(r+1)*(r+1)-r*r;
	  if(a<=t)
	    {
	      count++;
	      t=t-a;
	      r=r+2;
	    }
	  else
	    {
	      t=0;
	    }
	}
      printf("Case #%d: %d\n",i+1,count);
    }
  return 0;
}
