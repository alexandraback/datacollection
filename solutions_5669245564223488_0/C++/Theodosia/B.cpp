#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 110;

int n;
char str[N][N];
char first[N], last[N];
bool sch[26], can_first[N];

long long frac[N];
const int mod = 1000000007;

long long dfs (int x)
{
	if (x == -1) return 1;
	
	int shuffle = 0, next = -1;
	if (first[x] == last[x]) ++shuffle;
	sch[x] = true;
	for (int i = 0; i < n; i++) if (!sch[i])
	{
		if (first[i] == last[i] && last[x] == first[i])
			++shuffle, sch[i] = true;
		else if (first[i] != last[i] && last[x] == first[i])
			next = i;
	}
	return frac[shuffle] * dfs(next) % mod;
}

int main ()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	frac[0] = frac[1] = 1;
	for (int i = 2; i < N; i++) frac[i] = frac[i - 1] * i % mod;
	
	int T, kase = 0; for (scanf("%d", &T); T; --T)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
			int len = strlen(str[i]);
			first[i] = str[i][0];
			last[i] = str[i][len - 1];
			can_first[i] = true;
		}
		printf("Case #%d: ", ++kase);
		bool ok = true;
		for (int i = 0; ok && i < n; i++)
		{
			if (first[i] == last[i])
			{
				for (int j = 1; ok && str[i][j]; ++j)
				{
					if (str[i][j] != first[i])
						ok = false;
				}
			}
			else
			{
				memset(sch, 0, sizeof sch);
				sch[first[i] - 'a'] = true;
				for (int j = 1; ok && str[i][j]; ++j)
				{
					if (str[i][j] != str[i][j - 1])
					{
						if (sch[str[i][j] - 'a'])
							ok = false;
						sch[str[i][j] - 'a'] = true;
					}
				}
				for (int j = 0; ok && j < n; j++) if (j != i)
				{
					if (first[i] == first[j] && first[j] != last[j])
						ok = false;
					if (last[i] == last[j] && first[j] != last[j])
						ok = false;
					if (last[j] == first[i])
						can_first[i] = false;
					if (first[j] == last[i])
						can_first[j] = false;
					
					for (int k = 0; ok && str[j][k]; ++k)
					{
						if (str[j][k] != first[i] && str[j][k] != last[i] && sch[str[j][k] - 'a'])
							ok = false;
					}
				}
			}
		}
		if (!ok) printf("0\n");
		else
		{
			long long ans = 1, block = 0;
			memset(sch, 0, sizeof sch);
			
			for (int i = 0; i < n; i++) if (can_first[i] && !sch[i])
			{
				++block;
				ans = ans * dfs(i) % mod;
				// printf("ANS -> %lld\n", ans);
			}
			
			for (int i = 0; ok && i < n; i++) if (!sch[i])
			{
				ok = false;
			}
			if (!ok) printf("0\n");
			else printf("%lld\n", ans * frac[block] % mod);
		}
	}
	return 0;
}
