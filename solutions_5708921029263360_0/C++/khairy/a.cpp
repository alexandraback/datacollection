#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo (1<<30)
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mt make_tuple // you can ignore
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int vis[1001], jp[1001], js[1001], ps[1001];

int main() {
	freopen("test.in", "rt", stdin);
  freopen("o.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	FOR (cs, 1, t + 1)
	{
		int J, P, S, K;
		scanf("%d%d%d%d", &J, &P, &S, &K);
		vector<pair<int, pi>> res;
		int a[11], b[11], c[11];
		int mx = 0;
		FOR (i , 0 , J)
			a[i] = i;
		FOR (i , 0 , P)
			b[i] = i;
		FOR (i , 0 , S)
			c[i] = i;
		do {
			do {
				do {
					mem (vis, 0), mem(jp, 0), mem(js, 0), mem(ps, 0);
					vector<pair<int, pi>> r;
					FOR (jj , 0 , J)
					{
						FOR (pp , 0 , P)
						{
							FOR (ss , 0 , S)
							{
								int j = a[jj], p = b[pp], s = c[ss];
								int x = j + p * 10 + s * 100;
								int a = j + p * 10;
								int b = j + s * 10;
								int c = p + s * 10;
								if (vis[x] || jp[a] == K || js[b] == K
										|| ps[c] == K) {
									continue;
								}
								r.pb( { j + 1, { p + 1, s + 1 } });
								vis[x] = 1;
								jp[a]++, js[b]++, ps[c]++;
							}
						}
					}
					if (sz(r) > mx)
						res = r, mx = sz(r);
				} while (next_permutation(c, c + S));
			} while (next_permutation(b, b + P));
		} while (next_permutation(a, a + J));
		printf("Case #%d: %d\n", cs, sz(res));
		FOR (i , 0 , sz(res))
		{
			printf("%d %d %d\n", res[i].first, res[i].second.first,
					res[i].second.second);
		}
	}
	return 0;
}
