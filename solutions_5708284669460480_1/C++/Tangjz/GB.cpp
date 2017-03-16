#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 123, mod = 1000000007;
const double eps = 1e-8;
int T, kk, ll, ss, nxt[maxn], cnt[maxn], g[maxn][maxn][maxn];
double f[maxn][maxn][maxn];
char s[maxn], t[maxn];
int main()
{
	scanf("%d", &T);
	for(int Case = 1; Case <= T; ++Case)
	{
		memset(nxt, 0, sizeof nxt);
		memset(cnt, 0, sizeof cnt);
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		scanf("%d%d%d%s%s", &kk, &ll, &ss, t, s);
		for(int i = 0; i < kk; ++i)
			++cnt[(int)t[i] - 'A'];
		for(int i = 0; i < ll; ++i)
			s[i] -= 'A';
		for(int i = 1; i < ll; ++i)
		{
			int j = nxt[i];
			while(j && s[j] != s[i])
				j = nxt[j];
			if(s[i] == s[j])
				++j;
			nxt[i + 1] = j;
		}
		f[0][0][0] = 1;
		g[0][0][0] = 1;
		for(int i = 0; i < ss; ++i)
		{
			for(int j = 0; j < ll; ++j)
				for(int k = 0; k <= ss; ++k)
					if(g[i][j][k])
						for(int l = 0; l < 26; ++l)
							if(cnt[l])
							{
								double p = cnt[l] / (double)kk;
								int jj = j;
								while(jj && l != s[jj])
									jj = nxt[jj];
								if(l == s[jj])
									++jj;
								f[i + 1][jj][k] += f[i][j][k] * p;
								g[i + 1][jj][k] = 1;
							}
			for(int k = 0; k < ss; ++k)
			{
				f[i + 1][nxt[ll]][k + 1] += f[i + 1][ll][k];
				g[i + 1][nxt[ll]][k + 1] |= g[i + 1][ll][k];
			}
		}
		int lim = 0;
		double vari = 0;
		for(int i = 0; i <= ss; ++i)
			for(int j = 0; j < ll; ++j)
				if(g[ss][j][i])
				{
					vari += i * f[ss][j][i];
					lim = i;
				}
		printf("Case #%d: %.8f\n", Case, lim - vari);
	}
	return 0;
}
