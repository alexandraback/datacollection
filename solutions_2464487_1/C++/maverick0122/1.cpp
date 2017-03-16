#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

double r,t;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	for(int cnt=1;cnt<=T;cnt++)
	{
		scanf("%lf%lf",&r,&t);
		double b,x;
		b=2*r-1;
		x = (sqrt(b*b+8*t)-b)/4.0;
		double n = floor(x);
		while(t >= (2*(n+1)+b)*(n+1)) n++;
		while(t < (2*n+b)*n) n--;
		printf("Case #%d: %.0lf\n",cnt,n);
	}
} 
