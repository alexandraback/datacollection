#include<stdio.h>
int j[205];
int main()
{
  int t,test=1,n,x,i;
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d",&n);
      x=0;
      for(i=0;i<n;i++)
	{
	  scanf("%d",&j[i]);
	  x+=j[i];
	}
      printf("Case #%d: ",test);
      for(i=0;i<n;i++)
	if(200*x>=n*100*j[i])
	  printf("%f ",200/(float)n-(100*j[i])/(float)x);
	else
	  printf("0.0 ");
      printf("\n");
      test++;
    }
  return 0;
}
