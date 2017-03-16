#include <cstdio>
#include <vector>

#define PI 3.14159

using namespace std;

int n;
long long r,t, sum,x,res, circle;

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
		while(true)
		{
			circle = (pow(r+x+1, 2)-pow(r+x, 2));
			//printf("circle: %lld sum:%lld x:%lld t:%lld\n", circle, sum, x, t);
			if(circle+sum>t)
				break;
			else
				sum+=circle;

			x+=2;
			res++;
		}

		printf("Case #%d: %lld\n", i+1, res);
	}

	return 0;
}