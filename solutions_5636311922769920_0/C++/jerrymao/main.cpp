#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

vector<int> solve()
{
	int k, c, s; scanf("%d%d%d", &k, &c, &s);
	vector<int> ans;
	for (int i = 1;i <= k;i++) ans.push_back(i);
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
