#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;
int a, b, t, l, ans;

int calc(int n, int l, int e)
{
	set<int> s;
	int m = n;
	for (int i = 1; i <= l; i++)
	{
		m = m % 10 * e + m / 10;
		if (m > n && m <= b)
			s.insert(m);
	}
	return s.size();
}

int main()
{
	scanf("%d", &t);
	int ca = 0;
	while (t--)
	{
		ca++;
		ans = 0;
		scanf("%d%d", &a, &b);
		printf("Case #%d: ", ca);
		int e = 1, l = 1;
		for (int n = a; n <= b; n++)
		{
			while (n >= e * 10)
			{
				e *= 10;
				l++;
			}
			ans += calc(n, l, e);
		}
		printf("%d\n", ans);
	}
	return 0;
}
