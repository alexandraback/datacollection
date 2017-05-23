#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int A[126000];
int MEMO[2507];
int N;

inline void init()
{
	int i;

	scanf("%d", &N);

	memset(MEMO, 0, sizeof(MEMO));

	for (i = 0; i < (2 * N - 1) * N; i++)
	{
		scanf("%d", &A[i]);
		MEMO[A[i]]++;
	}
}

inline void solve()
{
	int i;

	vector<int> V;

	for (i = 0; i < (2 * N - 1) * N; i++)
		if (MEMO[A[i]] % 2)
			V.push_back(A[i]);

	sort(V.begin(), V.end());
	
	printf("%d ", V[0]);

	for (i = 1; i < V.size(); i++)
		if (V[i] != V[i - 1])
			printf("%d ", V[i]);

	printf("\n");
}

int main()
{
	int T, i;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		init();

		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}