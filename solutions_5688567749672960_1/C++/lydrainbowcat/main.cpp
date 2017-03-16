#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<cmath>
using namespace std;
int T;
__int64 n;

__int64 calc(__int64 n)
{
	//cout << n << endl;
	if (n < 10) return n;
	int a[20], m = 0;
	for (__int64 i = n; i; i /= 10) a[++m] = i % 10;
	reverse(a + 1, a + m + 1);
	__int64 p = 0, q = 0;
	for (int i = 1; i <= (m + 1) / 2; i++)
	{
		a[m - i + 1] = i == 1;
	}
	for (int j = 1; j <= m; j++) p = p * 10 + a[j];
	for (int j = m; j; j--) q = q * 10 + a[j];
	if (n >= p && p > q) return calc(q) + n - p + 1;
	p = 1;
	for (int i = m / 2 + 1; i <= m; i++) p = p * 10;
	if (n%p <= 1) return calc(n - 1) + 1;
	p = 1;
	for (int i = 1; i < m; i++) p = p * 10;
	return calc(p - 1) + n - p + 1;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n;
		printf("Case #%d: %lld\n", t, calc(n));
	}
}