#include <bits/stdc++.h>

using namespace std;

#define FOR(i,n) for(int i = 0 ;i < (n); i++) 
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ax+by=gcd(a,b)となるx,yを求める(|x| <= b , |y| <= a)
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
// ay≡gcd(a,m)(mod m) ---> return y; //mod_powの方が速い場合がある
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

Pii dfs(vector<vector<int>>& e,int p, int v) {
	Pii ret(0, v);
	for (auto to : e[v]) if (to != p) {
		Pii tmp = dfs(e, v, to);
		tmp.first++;
		if (ret.first < tmp.first) ret = tmp;
	}
	return ret;
}
int diameter(vector<vector<int>>& e, int v) {
	Pii x = dfs(e, -1, v);
	Pii y = dfs(e, -1, x.second);
	return y.first;
}

class UnionFind {
private:
	int n;
	vector<int> a;
public:
	UnionFind(int n) : n(n), a(n, -1) {}
	int find(int x) { return a[x] < 0 ? x : (a[x] = find(a[x])); }
	bool same(int x, int y) { return find(x) == find(y); }
	bool same(Pii& p) { return same(p.first, p.second); }
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (a[x] > a[y]) swap(x, y);
		a[x] += a[y];
		a[y] = x;
		n--;
		return true;
	}
	bool unite(Pii& p) { return unite(p.first, p.second); }
	int size() const { return n; }
	int size(int x) { return -a[find(x)]; }
};

pair<bool,int> solve(vector<Pii>& es) {
	set<int> cmp_;
	for (auto& kv : es) {
		cmp_.insert(kv.first); cmp_.insert(kv.second);
	}
	vector<int> cmp(cmp_.begin(), cmp_.end());
	vector<int> e(sz(cmp));
	for (auto& kv : es) {
		int a, b; tie(a, b) = kv;
		a = lower_bound(cmp.begin(), cmp.end(), a) - cmp.begin();
		b = lower_bound(cmp.begin(), cmp.end(), b) - cmp.begin();
		e[a] = b;
	}
	const int n = sz(cmp);
	int cur = 0;
	FOR(i, n) cur = e[cur];
	int loop = 0;
	{
		int s = cur;
		do { s = e[s]; loop++; }
		while (s != cur);
	}
	if (loop != 2) return make_pair(false, loop);

	// loop = 2
	map<int, int> mp;
	int top1 = cur, top2 = e[cur];
	FOR(i, n) {
		int s = i;
		int cnt = 0;
		while (s != top1 && s != top2) {
			s = e[s];
			cnt++;
		}
		mp[s] = max(mp[s], cnt);
	}
	return make_pair(true, mp[top1] + mp[top2] + 2);
}

int main() {
	int t; cin >> t;
	FOR(i, t) {
		int n; cin >> n;
		vector<Pii> es;
		UnionFind uf(n);
		FOR(i, n) {
			int to; cin >> to;
			to--;
			es.emplace_back(i, to);
			uf.unite(i, to);
		}
		map<int, vector<Pii>> mp;
		for (auto kv : es) {
			mp[uf.find(kv.first)].push_back(kv);
		}
		int ans = 0;
		int sum = 0;
		for (auto& v : mp) {
			auto tmp = solve(v.second);
			if (tmp.first) {
				sum += tmp.second;
			} else {
				ans = max(ans, tmp.second);
			}
		}
		ans = max(ans, sum);

		printf("Case #%d: %d\n", i + 1, ans);
	}
}
