#include<stdio.h>
#include<math.h>

int solve(int r, int t)
{
	int next = r+1;
	int result = 0;
	while(t>0)
	{
		int newarea = next*next;
		int area = (next-1)*(next-1);
		int used = newarea - area;
		t -= used;
		if(t<0)
			break;
		else
			result++;
		area = newarea;
		next+=2;		
	}
	return result;
}

double solve2(long long r, long long t)
{
	double a = 2.0;
	double b = (r+1)*(r+1) - r*r - 2;
	double c = -t;
	double res = (-b + sqrt(b*b-4*a*c)) / (2*a);
	return res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T;
	long long r,t;
	scanf("%d",&T);
	for(int c=1;c<=T;c++)
	{
		scanf("%lld %lld",&r,&t);
		printf("Case #%d: %lld\n",c,(long long)solve2(r,t));
	}
}