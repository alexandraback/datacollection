#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;

int n;

char s[100];
int palin(int x)
{
	sprintf(s, "%d", x);
	int n = strlen(s);
	for(int i = 0; i < n; i++) if (s[i] != s[n - i - 1]) return false;
	return true;
}

int good(int x)
{
	if (!palin(x)) return 0;
	for(int i = 0; i <= x; i++) if (i * i == x && palin(i)) return true;
	return false;
}

long long a[100] = { 0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004};

int main()
{
	/*for(int i = 1; i <= 10000000; i++)
	if (palin(i))
	{
		long long i2 = (long long)i * i;
		if (!palin(i2)) continue;
		a[n++] = i2;
	}

	printf("n = %d\n", n);

	for(int i = 0; i < n; i++) printf("%d,", a[i]);*/
	n = 27;

	int nt;
	scanf("%d", &nt);

	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		int A, B;
		scanf("%d %d", &A, &B);
		if (A > B) swap(A, B);

		int res = lower_bound(a, a + n, B + 1) - lower_bound(a, a + n, A);

		printf("%d\n", res);
	}
	return 0;
}