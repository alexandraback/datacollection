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
long m;
int S[40010];
int n, n_test;

inline int id (char x)
{
	if (x == 'i') return 2;
	if (x == 'j') return 3;
	return 4;
}

inline int exist_in_S (int i,int j,int k)
{
	return find(S + i, S + j + 1, k) != S + j + 1;
}

void solve ()
{
	int stage = 0;
	S[0] = 1;

	for (int i = 1; i <= n * min(4LL, m); ++i)
	{
		S[i] = M[abs(S[i - 1])][id(A[(i - 1) % n + 1])];
		if (S[i - 1] < 0) S[i] = -S[i];

		if (stage == 0 && S[i] == 2) ++stage;
		if (stage == 1 && S[i] == 4) ++stage;
	}

	if (S[n] == 1 || (S[n] == -1 && m % 2 == 0) || (abs(S[n]) != 1 && m % 4 != 2)) puts("NO");
	else
	if (m <= 4) puts((stage == 2) ? "YES" : "NO");
	else
	if (m <= 8)
		if (stage == 2 || (stage == 1 && exist_in_S(1, n * (m - 4), 4))) puts("YES");
		else
			puts("NO");
	else
		if (exist_in_S(1, n << 2, 2) && exist_in_S(1, n << 2, 4)) puts("YES");
		else
			puts("NO");
}

int main ()
{
	freopen("C.inp", "r", stdin);
	freopen("C.out", "w", stdout);

	scanf("%d", &n_test);
	for (int i = 1; i <= n_test; ++i)
	{
		printf("Case #%d: ", i);
		scanf("%d%lld%s", &n, &m, A + 1);
		solve ();
	}

	return 0;
}