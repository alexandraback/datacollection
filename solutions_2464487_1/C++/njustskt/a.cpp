#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
LL R,T,ans,temp;
LL bin(LL low,LL high,LL ans,LL a)
{
	if(low == high)
		return low;
	LL mid = (low + high)/2;
	LL t;
	if(mid * a <0)
	{
		return bin(low,mid,ans,a);	
	}
	else
	{
		t = mid*mid*2 + (mid *a);
		if(t < 0)
			return bin(low,mid,ans,a);
		else
		{
			if(t == ans)
				return mid;
			if(t < ans)
			{
				t = (mid+1)*(mid+1)*2+((mid+1)*a);
				if(t>ans)
					return mid;
				return bin(mid+1,high,ans,a);
			}
			else
			{
				return bin(low,mid,ans,a);
			}
		}
	}
}
int main()
{
	int t,d = 1,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&R,&T);
		R = 2*R - 1;
		temp = (LL)sqrt((double)T/2.0);
		ans = bin(1,temp,T,R);
		printf("Case #%d: %lld\n",d++,ans);
	}
	return 0;
}
