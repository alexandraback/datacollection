#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void solve()
{
	int n; scanf("%d", &n);
	if (n == 0)
	{
		printf("INSOMNIA\n");
		return;
	}
	bool seen[10] = {}; int num = 0;
	char buf[256];
	for (int i = n;;i+=n)
	{
		sprintf(buf, "%d", i);
		for (int j = 0;buf[j];j++)
			if (!seen[buf[j]-'0'])
			{
				seen[buf[j]-'0'] = true;
				num++;
			}
		if (num == 10)
		{
			printf("%d\n", i);
			return;
		}
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
