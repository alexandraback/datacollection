#include<stdio.h>
int calcCircles(unsigned long long start, unsigned long long capacity)
{
  unsigned long long i=start,j,k,isqr,jsqr;
  int ret=0;
  while(capacity > 0)
    {
      j=i+1;
      if((j*j - i*i) <= capacity)
	{
	  capacity -= ((j*j)-(i*i));
	  ret++;
	}
      else
	break;
      i+=2;
    }
  return ret;
}
void main()
{
  int testCases,i,j,val;
  unsigned long long start,cap;
  scanf("%d",&testCases);
  for(i=1;i<=testCases;++i)
    {
      scanf("%llu%llu",&start,&cap);
      val = calcCircles(start,cap);
      printf("Case #%d: %d\n",i,val); 
    }
}
