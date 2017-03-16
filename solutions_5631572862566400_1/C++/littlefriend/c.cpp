#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1005;
vector<int> vc[N];
bool check[N];
int tm[N];
int bff[N];

int getans(int k, int ban)
{
	int ret = 0;
	for (int i = 0; i < vc[k].size(); ++i)
	{
		if (vc[k][i] != ban)
		{
			ret = max(ret, getans(vc[k][i], k)+1);
		}
	}
	return ret;
}
int main(int argc, char** argv)
{
	if (argc > 1)
	{
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		int n;
		printf("Case #%d: ", i+1);
		scanf("%d", &n);
		for (int j = 1; j <= n; ++j)
		{
			vector<int>().swap(vc[j]);
			check[j] = false;
			tm[j] = 0;
		}
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", bff+j);
			vc[bff[j]].push_back(j);
		}
		int ans = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (j == bff[bff[j]] && !check[j])
			{
				check[j] = true;
				check[bff[j]] = true;
				ans += 2 + getans(j, bff[j]) + getans(bff[j], j);
			}
		}
		int cnt = 1;
		for (int j = 1; j <= n; ++j)
		{
			int org = cnt;
			int k;
			for (k = j; !tm[k]; k = bff[k]) tm[k] = cnt++;
			if (tm[k] >= org)
				ans = max(cnt-tm[k], ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}