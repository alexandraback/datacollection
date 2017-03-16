#include <cstdio>
#include <cmath>

double t[2000];
double x[2000];

bool doubleEqual(double a, double b)
{
	return fabs(a-b)<1e-9;
}

bool doubleLess(double a, double b)
{
	return !doubleEqual(a,b) && a<b;
}

double D;
int N,A;
double a;

bool nice(double c)
{
	double p = 0, v = 0;
	int j;
	for (j=1; j<N; ++j)
	{
		if (!doubleLess(x[j],D))
			break;
		double np = p+v*(t[j]-c)+a*(t[j]-c)*(t[j]-c)/2;
		if (doubleLess(x[j],np))
			return false;
	}
	if (N == 1)
		j = 0;
	double l=0, r=10000000, m;
	while(l+1e-9<r)
	{
		m = (l+r)*0.5;
		if (p+(v+a*m*0.5)*m>D)
			r = m;
		else
			l = m;
	}
	double o = (D-x[j-1])/(x[j]-x[j-1])*(t[j]-t[j-1]);
	//printf("j=%d l=%lf o=%lf c=%lf p=%lf v=%lf ",j,l,o,c,p,v);
	o += t[j-1];
	l += c;
	if (doubleLess(l,o))
		return false;
	return true;
}

void solve1()
{
	double l = 0, r = t[N-1], m;
	while (l+1e-8<r)
	{
		m = (l+r)*0.5;
		if (nice(m))
			r = m;
		else
			l = m;
	}
	double z = l;
	l = 0, r = 10000000000;
	while (l+1e-8<r)
	{
		m = (l+r)*0.5;
		if (a*m*m/2 > D)
			r = m;
		else
			l = m;
	}
	printf("%.20lf\n",z+l);
}

void solve()
{
	scanf("%lf%d%d",&D,&N,&A);
	for (int i=0; i<N; ++i)
		scanf("%lf%lf",t+i,x+i);
	for (int i=0; i<A; ++i)
	{
		scanf("%lf",&a);
		solve1();
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for (int i=0; i<t; ++i)
	{
		printf("Case #%d:\n", i+1);
		solve();
	}
	return 0;
}