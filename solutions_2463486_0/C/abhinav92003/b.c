#include<stdio.h>
long long res[10000000]={0},re=0;
long long int rev(long long int num)
{
	long long result=0;
	while(num)
	{
		result=(result<<3) + (result<<1) + (num%10);
		num/=10;
	}
	return result;
}
int main()
{
	int t;
	int i=1;
	long long sq,a,b;
	while(i<=10000000)
	{
		if(rev(i)==i)
		{
			sq=(long long)i*i;
			if(rev(sq)==sq)
			{
				res[re++]=sq;
			//	printf("%lld %d %lld\n",re,i,sq);
			}
		}
		i++;
	}
//	printf("sq is %lld",(long long)i*i);
	/*i=0;
	while(i<re)
		printf("%lld\n",res[i++]);
	printf("re is %lld   ",re);*/
	int T;
	scanf(" %d",&T);
    t=1;
	while(t<=T)
	{
		scanf(" %lld %lld",&a,&b);
		i=0;
		while(res[i]<a)
			i++;
		int count=0;
		while(res[i]<=b && i<re)
		{
			count++;
			i++;
		}
		printf("Case #%d: %d\n",t,count);
		t++;
	}
	return 0;
}
