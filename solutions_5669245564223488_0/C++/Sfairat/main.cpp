#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>

using namespace std;

template<typename T> T mabs(const T &a){ return a<0 ? -a : a; }
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

struct Vert
{
	int fromEdge;
	int toEdge;
	vector<int> edges;
	bool was;
	Vert()
	{
		fromEdge = toEdge = -1;
		was = 0;
	}
} verts[1050];

bool dfs(int cur, int prev)
{
	Vert &cv = verts[cur];

	if (cv.was)
		return false;
	bool res = 1;
	if (cv.edges.size() != 2)
		res = 1;
	cv.was = 1;

	rep(i, 0, cv.edges.size())
	{
		int to = cv.edges[i];
		if (to == prev)
			continue;
		res &= dfs(to, cur);
	}
	return res;
}

const ll MOD = 1000000007;

int test2(vector<vector<int>> &vi)
{
	vector<int> permutation;

	rep(i, 0, vi.size())
	{
		permutation.push_back(i);
	}
	int res = 0;

	do
	{
		bool had[30];

		memset(had, 0, sizeof(had));
		vector<int> tr;
		rep(i, 0, vi.size())
		{
			vector<int> &cv = vi[permutation[i]];
			rep(j, 0, cv.size())
			{
				tr.push_back(cv[j]);
			}
		}

		bool bad = 0;
		rep(i, 0, tr.size())
		{
			if (had[tr[i]])
			{
				if (tr[i] != tr[i - 1])
				{
					bad = 1;
					break;
				}
			}
			had[tr[i]] = 1;
		}
		if (!bad)
			res++;
	} while (next_permutation(all(permutation)));
	return res;
}

void test(int ti)
{
	printf("Case #%d: ", ti);

	rep(i, 0, 26)
	{
		verts[i] = Vert();
	}

	int n;
	scanf("%d", &n);
	using vi = vector<int>;
	vector<vi> words;

	int last[30], first[30], mid[30], single[30];
	bool has[30];
	memset(has, 0, sizeof(has));
	memset(last, 0, sizeof(last));
	memset(first, 0, sizeof(first));
	memset(mid, 0, sizeof(mid));
	memset(single, 0, sizeof(single));

	rep(i, 0, n)
	{
		char buf[250];
		scanf("%s", buf);

		int len = strlen(buf);
		vi cw;
		bool curSingle = 0;
		int newLen = 0;
		rep(i, 0, len)
		{
			if (buf[i] != buf[newLen])
			{
				newLen++; 
				buf[newLen] = buf[i];
			}
			has[buf[i] - 'a'] = 1;
		}

		len = newLen + 1;

		if (len == 1)
			curSingle = 1;

		if (curSingle)
		{
			int cs = buf[0] - 'a';
			cw.push_back(cs);
			single[cs]++;
			words.push_back(cw);
			continue;
		}
		rep(i, 0, len)
		{
			int cs = buf[i] - 'a';
			cw.push_back(cs);
			if (i == 0)
				first[cs]++;
			else if (i == len - 1)
				last[cs]++;
			else
				mid[cs]++;
		}
		words.push_back(cw);
	}

	bool imp = 0;
	rep(i, 0, 26)
	{
		if (last[i] + mid[i] > 1)
			imp = 1;
		if (first[i] + mid[i] > 1)
			imp = 1;
		if (single[i] > 0 && mid[i] > 0)
			imp = 1;
	}

	rep(i, 0, n)
	{
		vi &cw = words[i];
		if (cw.size() == 1)
			continue;

		rep(j, 0, cw.size())
		{
			if (j != 0)
			{
				if (verts[cw[j]].fromEdge != -1)
					imp = 1;
				verts[cw[j]].fromEdge = cw[j - 1];
				verts[cw[j]].edges.push_back(cw[j - 1]);
			}
			if (j != cw.size() - 1)
			{
				if (verts[cw[j]].toEdge != -1)
					imp = 1;
				verts[cw[j]].toEdge = cw[j + 1];
				verts[cw[j]].edges.push_back(cw[j + 1]);
			}
		}
	}

	int tc = 0;
	ll comps = 0;
	ll res = 1;
	rep(i, 0, 26)
	{
		ll fact = 1;
		rep(j, 0, single[i])
		{
			fact *= (j + 1);
			fact %= MOD;
		}
		res *= fact;
		res %= MOD;
		if (!has[i])
			continue;
		if (verts[i].was)
			continue;
		bool can = dfs(i, -1);
		if (can == false)
			imp = 1;
		comps++;
	}

	rep(i, 0, comps)
	{
		res = res * (i + 1);
		res %= MOD;
	}
	if (imp)
	{
		res = 0;
	}
	//fprintf(stderr, "%d\n", ti);
	//int tr = test2(words);
	//if (tr != res)
	//	printf("BIDA %d %d %d\n", ti, tr, res);
	printf("%lld\n", res);
}

//on ww jq ww qw

void run()
{
	int tc;
	scanf("%d", &tc);

	rep(i, 0, tc)
	{
		test(i + 1);
	}
}

//#define prob "fence"

int main()
{
#ifdef LOCAL_DEBUG
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	time_t st = clock();
#else 
#ifdef prob
	freopen(prob".in", "r", stdin);
	freopen(prob".out", "w", stdout);
#endif
#endif

	run();

#ifdef LOCAL_DEBUG
	fprintf(stderr, "\n=============\n");
	fprintf(stderr, "Time: %.2lf sec\n", (clock() - st) / double(CLOCKS_PER_SEC));
#endif

	return 0;
}