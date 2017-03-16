#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long v[20000];
int nxt[20000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	int e, r, n;
	scanf("%d", &t);
	for(int T = 1; T <= t; ++T)
	{
		scanf("%d%d%d", &e, &r, &n);
		for(int i = 0; i < n; ++i) scanf("%lld", v + i);
		for(int i = 0; i < n; ++i)
		{
			nxt[i] = 1000000;
			for(int j = i + 1; j < n; ++j)
			{
				if(v[j] > v[i])
				{
					nxt[i] = j;
					break;
				}
			}
		}
		int curE = e;
		long long ans = 0;
		for(int i = 0; i < n; ++i)
		{
			int dst = nxt[i] - i;
			int touse;
			touse = curE + dst * r - e;
			touse = min(touse, curE);
			touse = max(0, touse);
			ans += touse * v[i];
			curE -= touse;
			curE += r;
		}
		printf("Case #%d: %lld\n", T, ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}