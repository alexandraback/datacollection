#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define mp make_pair
#define mt make_tuple

char A[1010];
int n, n_test;

void solve ()
{
	int res = 0, s = 0;
	for (int i = 0; i <= n; ++i)
	{
		if (res + s < i) res = i - s;
		s += A[i] - '0';
	}

	printf("%d\n", res);
}

int main ()
{
	freopen("A.inp", "r", stdin);
	freopen("A.out", "w", stdout);

	scanf("%d", &n_test);
	for (int i = 1; i <= n_test; ++i)
	{
		printf("Case #%d: ", i);
		scanf("%d %s", &n, A);
		solve ();
	}

	return 0;
}