#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int T, n, t;
double a[1010], b[1010];
set<double> s;
set<double>::iterator it;
int main()
{
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf", &a[i]);
		}
		s.clear();
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf", &b[i]);
			s.insert(b[i]);
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		/*for (int i = 1; i <= n; i++)
		{
			printf("%.3lf ", a[i]);
		}
		puts("");
		for (int i = 1; i <= n; i++)
		{
			printf("%.3lf ", b[i]);
		}
		puts("");*/
		int j = 0, k = 0;
		for (int i = 1, l = 1, r = n; i <= n; i++)
		{
			if (a[i] < b[l]) r--; else l++, j++;
			it = s.upper_bound(a[i]);
			if (it != s.end()) s.erase(it); else k++;
		}
		printf("Case #%d: %d %d\n", ++t, j, k);
	}
}