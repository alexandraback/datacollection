#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

string ans;
int ex, ey;

void solve()
{
	ans = "";
	char ca, cb;
	if (ex < 0)
		ca = 'E', cb = 'W';
	else
		ca = 'W', cb = 'E';
	int dis = abs(ex);
	for (int i = 0; i < dis; i++)
	{
		ans.push_back(ca);
		ans.push_back(cb);
	}

	if (ey < 0)
		ca = 'N', cb = 'S';
	else
		ca = 'S', cb = 'N';
	dis = abs(ey);
	for (int i = 0; i < dis; i++)
	{
		ans.push_back(ca);
		ans.push_back(cb);
	}
}

int main()
{
	int totCas;
	scanf("%d", &totCas);
	for (int cas = 1; cas <= totCas; cas++)
	{
		scanf("%d%d", &ex, &ey);
		solve();
		printf("Case #%d: %s\n", cas, ans.c_str());
	}
	return 0;
}

