#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define mp make_pair
#define mt make_tuple

const int M[][5] = {{0, 0, 0, 0, 0},
					{0, 1, 2, 3, 4},
					{0, 2, -1, 4, -3},
					{0, 3, -4, -1, 2},
					{0, 4, 3, -2, -1}};

char A[10010];
int n, m, n_test;

inline int id (char x)
{
	if (x == 'i') return 2;
	if (x == 'j') return 3;
	return 4;
}

void enter ()
{
	scanf("%d%d%s", &n, &m, A + 1);
	for (int i = n + 1; i <= n * m; ++i)
		A[i] = A[(i - 1) % n + 1];

	n *= m;
}

void solve ()
{
	int stage = 0, k = 1;
	for (int i = 1; i <= n; ++i)
	{
		int t = M[abs(k)][id(A[i])];
		if (k < 0) t = -t;

		if (stage == 0 && t == 2) ++stage;
		if (stage == 1 && t == 4) ++stage;
		k = t;
	}

	puts((stage == 2 && k == -1) ? "YES" : "NO");
}

int main ()
{
	freopen("C.inp", "r", stdin);
	freopen("C.out", "w", stdout);

	scanf("%d", &n_test);
	for (int i = 1; i <= n_test; ++i)
	{
		printf("Case #%d: ", i);
		enter ();
		solve ();
	}

	return 0;
}