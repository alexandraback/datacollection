#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
#include <iterator>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const ll K = 6;
typedef array<pii,K> poly;
set<poly> omino[K+1];
ll dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

poly normalize(poly p, ll k) {
	sort(begin(p),begin(p)+k);
	ll minx = 1000, miny = 1000;
	FOR(j,0,k) minx = min(minx,p[j].xx), miny = min(miny,p[j].yy);
	FOR(j,0,k) p[j].xx -= minx, p[j].yy -= miny;
	return p;
}

poly transform(poly p, ll k, ll t) {
	if (t & 1) FOR(j,0,k) p[j].xx = -p[j].xx;
	if (t & 2) FOR(j,0,k) p[j].yy = -p[j].yy;
	if (t & 4) FOR(j,0,k) swap(p[j].xx,p[j].yy);
	return normalize(p,k);
}

bool used[20][20];

void rec(poly p, ll k) {
	omino[k].insert(normalize(p,k));
	if (k == K) return;
	FOR(j,0,k) FOR(d,0,4) {
		ll nx = p[j].xx+dx[d], ny = p[j].yy+dy[d];
		if (used[nx][ny]) continue;
		used[nx][ny] = true;
		p[k] = {nx,ny};
		rec(p,k+1);
		used[nx][ny] = false;
	}
	p[k] = {0,0};
}

void gen() {
	memset(used,0,sizeof(used));
	poly p;
	p.fill({0,0});
	p[0] = {10,10};
	used[10][10] = true;
	rec(p,1);
	FOR(k,1,K+1) {
		set<poly> s;
		while (sz(omino[k])) {
			poly p = *begin(omino[k]);
			FOR(t,0,8) omino[k].erase(transform(p,k,t));
			s.insert(p);
		}
		omino[k] = s;
	}
}

ll dfs(ll x, ll y, ll m, ll n, vector<vb> & mark) {
	ll res = 1;
	mark[x][y] = true;
	FOR(d,0,4) {
		ll nx = x+dx[d], ny = y+dy[d];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n || mark[nx][ny]) continue;
		res += dfs(nx,ny,m,n,mark);
	}
	return res;
}

bool canFill(vector<vb> &mark, ll k) {
	ll m = sz(mark), n = sz(mark[0]);
	FOR(i,0,m) FOR(j,0,n) if (!mark[i][j]) {
		if (dfs(i,j,m,n,mark) % k) return false;
	}
	return true;
}

bool secondWins(ll k, ll H, ll W) {
	if (k >= 7) return false;
	for (const poly& q: omino[k]) {
		bool curPoly = false;
		FOR(t,0,8) {
			poly p = transform(q,k,t);
			ll h0 = 0, w0 = 0;
			FOR(j,0,k) h0 = max(h0,p[j].xx), w0 = max(w0,p[j].yy);
			
			FOR(h,0,H-h0) {
				FOR(w,0,W-w0) {
					vector<vb> mark(H,vb(W));
					FOR(j,0,k) mark[h+p[j].xx][w+p[j].yy] = true;
					if (canFill(mark,k)) {
						curPoly = true;
						break;
					}
				}
				if (curPoly) break;
			}
		}
		if (!curPoly) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	gen();
	//FOR(i,0,K+1) cout << sz(omino[i]) << endl;

	ll TC; cin >> TC;
	FOR(tc,1,TC+1) {
		ll x, r, c;
		cin >> x >> r >> c;
		cout << "Case #" << tc << ": " << (secondWins(x,r,c) ? "GABRIEL" : "RICHARD") << endl;
	}

}

