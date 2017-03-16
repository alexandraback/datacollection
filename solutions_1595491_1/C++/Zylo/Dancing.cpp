#include<stdio.h>


int main()
{
  int T,s,p,t,caso,i,max,n;
  int a,b,c;
  scanf("%d",&T);
  for(caso=1;caso<=T;caso++)
  {
    scanf("%d",&n);
    scanf("%d",&s);
    scanf("%d",&p);
    
    max=0;
    for(i=0;i<n;i++)
    {
      scanf("%d",&t);
      a=p;
      b=(t-a)/2;
      c=(t-a+1)/2;
     
      if(c>=a&&(a+b+c)==t)
	max++;
      else
      {
	if(a-b<2&&(a+b+c)==t)
	  max++;
	else
	{
	  if(a-b==2&&s&&(a+b+c)==t)
	  {
	    max++;
	    s--;
	  }
	}
      }
      
      
    }
    
    printf("Case #%d: %d\n",caso,max);
  }
  return 0;
}