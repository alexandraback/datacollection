#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;

const double eps = 1e-6;

int n;
double a[1024];
double b[1024];
bool us[1024];

int soln(int k, bool d)
{
	double *c = b + k;
	int ln = n - k;
	
	memset(us, 0, sizeof(us));
	int res = 0;
	int sc, ec;
	sc = 0; ec = ln - 1;
	if (d)
	{
		set<double> ca;
		for (int i = 0; i < ln; ++i)
			ca.insert(a[i]);
		while (ca.size())
		{
			if (ca.upper_bound(c[sc]) == ca.end())
			{
				ca.erase(ca.begin());
				++sc;
			}
			else
			{
				set<double>::iterator it = ca.upper_bound(c[ec]);
				--ec;
				++res;
				ca.erase(it);
			}
		}
		return res;
	}
	
	for (int i = 0; i < ln; ++i)
	{
		if (a[i] > c[sc] + eps)
		{
			--ec;
			++res;
		}
		else
		{
			++sc;
		}
	}
	return res;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; ++t)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &a[i]);
		}
		sort(&a[0], &a[n], greater<double>());
		//~ printf("SA \n");
		//~ for (int i = 0; i < n; i++)
		//~ {
			//~ printf("%lf\n", a[i]);
		//~ }
		
		
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &b[i]);
		}
		sort(b, b + n, greater<double>());
		//~ printf("SB \n");
		//~ for (int i = 0; i < n; i++)
		//~ {
			//~ printf("%lf\n", b[i]);
		//~ }
		
		
		int mx = 0;
		for (int i = 0; i < n; ++i)
		{
			mx = max(mx, soln(i, 1));
		}
		printf("Case #%d: %d %d\n", t, mx, soln(0, 0));
	}
	return 0;
}
