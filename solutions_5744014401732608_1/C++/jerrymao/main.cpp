#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int sol[64][64];

void solve()
{
	int b; long long m;
	scanf("%d%lld", &b, &m);
	if (m > (1ll<<(b-2)))
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	for (int i = 0;i < b;i++) for (int j = 0;j < b;j++)
		sol[i][j] = (i<j);
	if (m != (1ll<<(b-2)))
	{
		for (int i = 0;i < b;i++)
			sol[0][i] = 0;
		for (int i = b-2;i > 0;i--) if (m&(1<<(b-2-i)))
			sol[0][i] = 1;
	}
	printf("POSSIBLE\n");
	for (int i = 0;i < b;i++)
	{
		for (int j = 0;j < b;j++)
			printf("%d", sol[i][j]);
		printf("\n");
	}
}

int main()
{
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);
		milliseconds start_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		printf("Case #%d: ", _);
		solve();

		milliseconds end_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long long time_used = end_ti.count() - start_ti.count();
		fprintf(stderr, " done\t% 6lldms\n", time_used); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}
