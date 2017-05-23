#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int t;
int n;
double a[Maxn], b[Maxn];

bool Check(int off)
{
	for (int i = 0; off + i < n; i++)
		if (a[off + i] < b[i]) return false;
	return true;
}

int getRes1()
{
	for (int lose = 0; lose <= n; lose++)
		if (Check(lose)) return n - lose;
}

int getRes2()
{
	int j = 0;
	int lose = 0;
	for (int i = 0; i < n; i++) {
		while (j < n && b[j] < a[i]) j++;
		if (j == n) break;
		lose++; j++;
	}
	return n - lose;
}

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf", &a[i]);
		for (int i = 0; i < n; i++)
			scanf("%lf", &b[i]);
		sort(a, a + n); sort(b, b + n);
		printf("Case #%d: %d %d\n", tc, getRes1(), getRes2());
	}
	return 0;
}