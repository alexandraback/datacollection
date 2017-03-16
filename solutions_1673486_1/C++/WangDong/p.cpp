#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<map>
#include<iostream>

using namespace std;

const int maxn = 100010;

int T;
int n, m;
double a[maxn];
double p[maxn];

void init()
{
	scanf("%d%d", &n, &m);
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	for (int i=0; i<n; i++) scanf("%lf", &a[i]);
}

double e1, p1;
double e2;
double ret;
void work()
{
	e2 = m + 2;
	double p1 = 1;
	for (int i=0; i<n; i++) p1 = p1 * a[i];
	e1 = p1 * (m-n+1)+(1-p1)*(m-n+2+m);
	p[0] = a[0];
	for (int i=1; i<n; i++) p[i] = a[i] * p[i-1];
	ret = m + m + 2;
	ret = min(e1, e2);

	for (int i=1; i<=n; i++)
	{
		double e3 = 0;
		if (i<n) e3 += (1-p[n-i-1])*(i+m-n+i+1+m+1);
		double nk = 1, mk1, mk2;
		if (i<n) nk = p[n-i-1];
		mk1 = 1;
		mk2 = 0;
		e3+=nk*mk1*(i+m-n+i+1)+nk*mk2*(i+m-n+i+1+m+1);
		ret = min(e3, ret);
	}
}

int main()
{
	freopen("C:/Users/yaoyao/Downloads/A-large.in", "r", stdin);
	freopen("D:/workspace/Topcoder/Algorithm/Algorithm/out.txt", "w", stdout);
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		init();
		work();
		printf("Case #%d: %6lf\n", i, ret);
	}
}