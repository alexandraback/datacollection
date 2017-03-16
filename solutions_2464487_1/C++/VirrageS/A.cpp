#include <cstdio>
#include <vector>

#define PI 3.14159

using namespace std;

int n;
long long r,t, sum,x,res, circle;
long long start,end,mid;

long long pow(long long a, long long b)
{
	if(b==1)
		return a;
	
	return a*pow(a, b-1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		sum=res=x=0;
		scanf("%lld %lld", &r, &t);
		start=1;
		end=1000000000;
		while(start<=end)
		{
			mid=(start+end)/2;
			if(2*t/mid>(4*r+4*mid-3) && 2*t/(mid+1)<=(4*r+4*(mid+1)-3))
				break;

			if(2*t/mid>(4*r+4*mid-3))
				start=mid+1;
			else
				end=mid-1;
		}
		/*while(true)
		{
			circle = 2*(x+r)+1;
			//printf("circle: %lld sum:%lld x:%lld t:%lld\n", circle, sum, x, t);
			if(circle+sum>t)
				break;
			else
				sum+=circle;

			x+=2;
			res++;
		}*/

		printf("Case #%d: %lld\n", i+1, mid);
	}

	return 0;
}