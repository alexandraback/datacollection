#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void solve()
{
	int x, y, z, l; scanf("%d%d%d%d", &x, &y, &z, &l);
	vector<tuple<int, int, int> > ans;
	int e = min(z, l);
	for (int i = 1;i <= x;i++) for (int j = 1;j <= y;j++) for (int k = 0;k < e;k++)
		ans.emplace_back(i, j, (i+j+k-2)%z+1);
	printf("%d\n", ans.size());
	for (auto u: ans)
		printf("%d %d %d\n", get<0>(u), get<1>(u), get<2>(u));
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
