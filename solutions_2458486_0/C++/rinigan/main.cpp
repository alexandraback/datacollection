#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <complex>
#include <ctime>
#include <stack>
#include <thread>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef vector< vector<ll> > VVI;
typedef pair<ll, ll> PII;
typedef vector<PII> VPII;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(ll i = x; i <= y; ++i)
#define RFOR(i, x, y) for(int i = x; i >= y; --i)
#define SZ(a) (ll)(a).size()
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a)) 
#define CLEAR(x) memset(x,0,sizeof x);
#define COPY(FROM, TO) memcpy(TO, FROM, sizeof TO);
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define pb push_back
#define sqr(x) (x)*(x)
#define X first
#define Y second
#define y1 Y1
#define y2 Y2
const long double pi=acos(-1.0);
const long double eps = 1e-9;


int T;
int k, n;
int start[1000];
int tp[1000];
vector<int> inside[1000];
int d[2000000];

bool valid(int mask, multiset<int> ms)
{
	if (d[mask] == 1) return false;
	if (d[mask] == 2) return true;

	if (mask == (1 << n) - 1) return true;
	REP(next, n)
		if ((mask & (1 << next)) == 0)
			if (ms.find(tp[next]) != ms.end())
			{
				multiset<int> ms_next = ms;
				ms_next.erase(ms_next.find(tp[next]));
				for (int v : inside[next])
				{
					ms_next.insert(v);
				}

				int mask_next = (mask | (1 << next));
				if (valid(mask_next, ms_next))
				{
					d[mask] = 2;
					return true;
				}
			}
	d[mask] = 1;
	return false;
}

vector<int> solve()
{
	multiset<int> ms;
	REP(i, k) ms.insert(start[i]);
	if (!valid(0, ms)) return vector<int>();

	vector<int> res;
	int mask = 0;

	REP(i, n)
	{
		REP(cur, n)
			if ((mask & (1 << cur)) == 0)
				if (ms.find(tp[cur]) != ms.end())
				{
					int mask_next = (mask | (1 << cur));
					multiset<int> ms_next = ms;
					ms_next.erase(ms_next.find(tp[cur]));
					for (int v : inside[cur])
					{
						ms_next.insert(v);
					}
					if (valid(mask_next, ms_next))
					{
						res.pb(cur + 1);
						mask = mask_next;
						ms = ms_next;
						break;
					}
				}
	}
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	FOR(TEST, 1, T)
	{
		CLEAR(d);
		REP(i, 1000) inside[i].clear();

		scanf("%d%d", &k, &n);
		REP(i, k) scanf("%d", &start[i]);

		REP(i, n)
		{
			int kk;
			scanf("%d %d", &tp[i], &kk);
			REP(j, kk)
			{
				int u;
				scanf("%d", &u);
				inside[i].pb(u);
			}
		}

		vector<int> v = solve();
		printf("Case #%d: ", TEST);
		if (v.empty()) printf("IMPOSSIBLE");
		REP(i, v.size()) printf(" %d" + (i == 0), v[i]);
		printf("\n");
	}
}