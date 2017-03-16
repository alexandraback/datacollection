#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define mp make_pair
#define mt make_tuple

int n, n_test;

void solve ()
{
	priority_queue<int> T;

	for (int i = 1; i <= n; ++i)
	{
		int k; scanf("%d", &k);
		T.push(k);
	}

	int res = T.top();
	for (int i = 1; T.top() > 1; ++i)
	{
		int k = T.top();
		T.pop();
		T.push(k >> 1);
		T.push((k >> 1) + (k & 1));

		res = min(res, T.top() + i);
	}

	printf("%d\n", res);
}

int main ()
{
	freopen("B.inp", "r", stdin);
	freopen("B.out", "w", stdout);

	scanf("%d", &n_test);
	for (int i = 1; i <= n_test; ++i)
	{
		printf("Case #%d: ", i);
		scanf("%d", &n);
		solve ();
	}

	return 0;
}