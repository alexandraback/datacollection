#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, M[1000], G[1000][10];
int C[1000];

bool check(int i)
{ // very inefficient !
	if (C[i])
		return true;
	C[i]++;
	bool r = false;
	for (int j = 0; j < M[i] && !r; ++j)
		r |= check(G[i][j]-1);
	return r;
}

main()
{
	scanf("%d\n", &T);

	for (int t = 1; t <= T; ++t) {
		scanf("%d\n", &N);
		for (int n = 0; n < N; ++n) {
			scanf("%d\n", &M[n]);
			for (int m = 0; m < M[n]; m++)
				scanf("%d\n", &G[n][m]);
		}

		bool diamond = false;

		for (int k = 0; k < N && !diamond; ++k) {
			for (int i = 0; i < N; ++i)
				C[i] = 0;
			diamond |= check(k);
		}
			

		printf("Case #%d: %s\n", t, diamond ? "Yes": "No");

	}
}
