#include<cstdio>
#include<string>
#include<set>
#include<vector>
#include<utility>
using namespace std;
vector<string> lset, rset;
int lcnt[1000], rcnt[1000];
vector<int> g[1000];
char ina[33], inb[33];

int solve(int l, int i = 0)
{
	if (l == lset.size()) return 0;
	if (lcnt[l] <= 1) return solve(l + 1);
	int ans, tmp;
	ans = solve(l + 1);
	for (int r = i; r < g[l].size(); r++)
	{
		if (rcnt[g[l][r]]>1)
		{
			lcnt[l]--;
			rcnt[g[l][r]]--;
			tmp = 1 + solve(l, i + 1);
			if (tmp > ans) ans = tmp;
			lcnt[l]++;
			rcnt[g[l][r]]++;
		}
	}
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, n;
	scanf("%d", &T);
	lset.reserve(1000);
	rset.reserve(1000);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d",&n);
		int l = 0, r = 0, li, ri;
		for (int i = 0; i < n; i++)
		{
			scanf("%s%s", ina, inb);
			string a = ina, b = inb;
			auto ita = find(lset.begin(), lset.end(), a);
			if (ita == lset.end())
			{
				lset.push_back(a);
				li = l;
				lcnt[l++]++;

			}
			else
			{
				li = distance(lset.begin(), ita);
				lcnt[li]++;
			}
			auto itb = find(rset.begin(), rset.end(), b);
			if (itb == rset.end())
			{
				rset.push_back(b);
				ri = r;
				rcnt[r++]++;
			}
			else
			{
				ri = distance(rset.begin(), itb);
				rcnt[ri]++;
			}
			g[li].push_back(ri);
		}
		printf("Case #%d: %d\n", t, solve(0));
		lset.clear();
		rset.clear();
		for (int i = 0; i < n; i++)
		{
			lcnt[i] = 0;
			rcnt[i] = 0;
			g[i].clear();
		}
	}
}