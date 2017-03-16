#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long

ll A;
int n;
ll a[1000000];

void load()
{
	cin >> A >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
}
void solve(int test_number)
{
	cout << "Case #" << test_number << ": ";
	sort(a, a + n);
	int i = 0;
	ll s = A;
	for (i = 0; i < n; i++)
	{
		if (s <= a[i]) break;
		s += a[i];
	}
	ll result = -1, cur = 0;
	for (; i <= n; )
	{
		if (result == -1 || result > cur + (n - i))
			result = cur + n - i;
		if (i == n) break;
		if (s == 1) break;
		s += s - 1;
		cur++;
		while (i < n && a[i] < s)
		{
			s += a[i];
			i++;
		}
	}
	cout << result << "\n";
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		load();
		solve(i + 1);
	}
}