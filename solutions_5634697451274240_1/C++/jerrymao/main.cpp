#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

char buf[105];
int n;

int solve()
{
	scanf("%s", buf);
	n = strlen(buf);
	int ans = 0;
	for (int i = 1;i < n;i++) if (buf[i-1] != buf[i])
		ans++;
	if (buf[n-1] == '-') ans++;
	return ans;
}

int main()
{
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);
		milliseconds start_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		printf("Case #%d: %d\n", _, solve());

		milliseconds end_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long long time_used = end_ti.count() - start_ti.count();
		fprintf(stderr, " done\t% 6lldms\n", time_used); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}
