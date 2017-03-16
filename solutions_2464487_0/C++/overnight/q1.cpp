#include "stdio.h"
#include "algorithm"
#include "vector"
#include "math.h"
int main(int argc, char const *argv[])
{
	int t;
	int i=1;
	scanf("%d",&t);
	while(t--)
	{
		long long int r,t1;
		scanf("%lld",&r);
		scanf("%lld",&t1);
		int count =0;
		long long  int sum =0;
		r++;
		while(sum<t1)
		{
			sum+=(r*r)- (r-1)*(r-1);
			r+=2;
			count++;
		}
		if(sum>t1)count--;
		if(count<0) count=0;
		printf("Case #%d: %d\n",i,count );
		i++;
	}
	return 0;
}