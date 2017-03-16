#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 

const double INF=1E9;
double c, f, x;

void work()
{
	scanf("%lf%lf%lf", &c, &f, &x);
	double i=2;
	double now=0, last=INF;
	while (now + x / i < last)
	{
		last=now + x / i;
		now=now+c/i;
		i=i+f; 
	}
	double ans=last;
	printf("%.7lf\n", ans);
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int i=1; i<=cas; ++i)
	{
		printf("Case #%d: ", i);
		work();
	}
	return 0;
}
