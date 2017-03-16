#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int K, C, S;

	scanf("%d %d %d", &K, &C, &S);

	for (int i = 0; i < K; i++) printf("%d%c", i + 1, " \n"[i + 1 == K]);
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++){
		printf("Case #%d: ", i + 1);
		solve();
	}

	return (0);
}