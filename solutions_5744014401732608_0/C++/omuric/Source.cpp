#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <list>
#include <tuple>
#include <bitset>
#include <ciso646>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;

inline bool check(ll x, ll y, ll xMax, ll yMax) { return x >= 0 && y >= 0 && xMax > x && yMax > y; }
inline int toint(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string tostring(T x) { ostringstream sout; sout << x; return sout.str(); }
template<class T> inline T sqr(T x) { return x*x; }
template<class T> inline T mypow(T x, ll n) { T res = 1; while (n > 0) { if (n & 1)res = res * x;	x = x * x;	n >>= 1; }return res; }
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

#define For(i,a,b)	for(ll (i) = (a);i < (b);(i)++)
#define rep(i,n)	For(i,0,n)
#define rFor(i,a,b)	for(ll (i) = (a-1);i >= (b);(i)--)
#define rrep(i,n)	rFor(i,n,0)
#define each(i,n)	for(auto &i : n)
#define clr(a)		memset((a), 0 ,sizeof(a))
#define mclr(a)		memset((a), -1 ,sizeof(a))
#define all(a)		(a).begin(),(a).end()
#define sz(a)		(sizeof(a))
#define tostr(a)	tostring(a)
#define dump(val) 	cerr << #val " = " << val << endl;
#define Fill(a,v)	fill((int*)a,(int*)(a+(sz(a)/sz(*(a)))),v)

const ll dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 }, dy[8] = { 0, -1, 0, 1, -1, 1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = 1e17 + 9;

#define int ll
#define double ld

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int _ = 0; _ < T; _++) {
		cout << "Case #" << _ + 1 << ": ";
		int b, m;
		cin >> b >> m;
		vector<vector<int>> d(b, vector<int>(b, 0));
		bool ok = false;

		vector<int> memo(b, 0);
		vector<int> vis(b, 0);

		function<bool(int, int)> dfs = [&](int y, int x) {
			if (y == b - 1) {
				function<bool(int)> isClose = [&](int n) {
					vis[n] = 1;
					rep(i, b) {
						if (d[n][i]) {
							if (vis[i])return true;
							if (isClose(i)) return true;
						}
					}
					vis[n] = 0;
					return false;
				};
				vis = vector<int>(b, 0);
				if (isClose(0))return false;
				vis = vector<int>(b, 0);
				queue<int> q;
				q.push(0);
				memo = vector<int>(b, 0);
				memo[0] = 1;
				while (q.size()) {
					int now = q.front();
					q.pop();
					bool ok = true;
					rep(i, b) {
						if (d[i][now] && vis[i] == false) {
							ok = false;
						}
					}
					if (ok) {
						vis[now] = true;
						rep(i, b) {
							if (d[now][i]) {
								memo[i] += memo[now];
								if (memo[i] > m)return false;
								q.push(i);
							}
						}
					}
				}
				return ok = memo[b - 1] == m;
			}
			if (y == x || d[x][y]) {
				if (x == b - 1) {
					if (dfs(y + 1, 0))return true;
				}
				else {
					if (dfs(y, x + 1)) return true;
				}
			}else
			rep(i, 2) {
				d[y][x] = i;
				if (x == b - 1) {
					if (dfs(y + 1, 0))return true;
				}
				else {
					if (dfs(y, x + 1)) return true;
				}
				d[y][x] = 0;
			}
			return false;
		};
		dfs(0, 0);
		if (ok) {
			cout << "POSSIBLE" << endl;
			rep(y, b) {
				rep(x, b) {
					cout << d[y][x];
				}
				cout << endl;
			}
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}


	return 0;
}
