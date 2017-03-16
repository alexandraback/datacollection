#include<stdio.h>
#include<math.h>
int fair[10000005],dig[100];
int palin(long long int num)
{
  int i=0,j;
  while(num>0)
    {
      dig[i++]=num%10;
      num/=10;
    }
  i--;
  j=0;
  while(i>j && dig[i]==dig[j])
    {
      i--;j++;
    }
  if(i<=j)
    return 1;
  return 0;
}
int main()
{
  int t,count;
  long long int i,a,b;
  scanf("%d",&t);
  count=0;
  fair[0]=0;
  for(i=1;i<=1e7;i++)
    {
      if(palin(i) && palin(i*i))
	count++;
      fair[i]=count;
    }
  for(i=1;i<=t;i++)
    {
      scanf("%lld %lld",&a,&b);
      printf("Case #%lld: %d\n",i,fair[(int)floor(sqrt(b))]-fair[(int)floor(sqrt(a-1))]);
    }
  return 0;
}
