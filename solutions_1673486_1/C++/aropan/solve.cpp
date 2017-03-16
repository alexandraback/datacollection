#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100007;
double a[MAXN];

int main()
{
    freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
    	int n, m;
    	cin >> n >> m;
    	a[0] = 1;
    	for (int i = 1; i <= n; i++)
    	{
    		cin >> a[i];
    		a[i] *= a[i - 1];
    	}

    	double ans = m + 2;
    	for (int i = 0; i <= n; i++)
    	{
//    		printf("%.3lf\n", a[i]);
    		double x = a[i] * (m - i + 1) + (1 - a[i]) * (m - i + 1 + m + 1) + n - i;
//			printf("%.3lf\n", x);
    		ans = min(ans, x);
    	}
    	printf("Case #%d: %.7lf\n", t, ans);
    }
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
