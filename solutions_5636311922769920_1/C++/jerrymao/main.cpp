#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

vector<int> solve()
{
	vector<int> ans;
	int k, c, s; scanf("%d%d%d", &k, &c, &s);
	int need = (k+c-1)/c;
	if (need > s) return ans;
	for (int z = 0;z < need;z++)
	{
		int lo = z*c, hi = lo+c;
		long long idx = lo;
		for (int i = lo+1;i < hi && i < k;i++)
			idx = idx*k + i;
		for (int i = k;i < hi;i++) // any extras
			idx = idx*(k+1);
		ans.push_back(idx+1);
	}
	return ans;
}

int main()
{
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);
		milliseconds start_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		printf("Case #%d:", _);
		vector<int> u = solve();
		if (u.size()) for (int v: u) printf(" %d", v);
		else printf(" IMPOSSIBLE");
		printf("\n");

		milliseconds end_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long long time_used = end_ti.count() - start_ti.count();
		fprintf(stderr, " done\t% 6lldms\n", time_used); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}
