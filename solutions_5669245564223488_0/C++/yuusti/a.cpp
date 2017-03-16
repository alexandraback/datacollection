#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <iterator>
#include <bitset>
#include <random>
#include <assert.h>

#ifdef _MSC_VER
#include <agents.h>
#endif

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> P;

struct mint {
	typedef long long ll;
	ll val;
	static const ll mod = 1e9 + 7;
	mint() :val(0){};
	mint(ll val) :val(((val%mod + mod) % mod)){}
	operator ll&(){ return val; }
	operator const ll&() const { return val; }
	mint& operator +=(ll rhs){ val += val + rhs < mod ? rhs : rhs - mod; return *this; }
	mint& operator -=(ll rhs){ val -= val < rhs ? rhs - mod : rhs; return *this; }
	mint& operator *=(ll rhs){ val = val * rhs % mod; return *this; }
	mint& operator /=(ll rhs){ val = val * inv(rhs) % mod; return *this; }
	mint operator +(ll rhs) const { return val + rhs < mod ? val + rhs : val + rhs - mod; }
	mint operator -(ll rhs) const { return val < rhs ? val - rhs + mod : val - rhs; }
	mint operator *(ll rhs) const { return val*rhs % mod; }
	mint operator /(ll rhs) const { return val*inv(rhs) % mod; }
	mint operator -() const { return val ? mod - val : 0; }
	bool operator==(mint rhs){ return val == rhs.val; }
	bool operator!=(mint rhs){ return val != rhs.val; }
	static mint pow(mint x, long long n){
		mint res = 1;
		while (n){ if (n & 1)res *= x; x *= x; n >>= 1; }
		return res;
	}
	static mint inv(mint x){
		return pow(x, mint::mod - 2);
	}
};

std::ostream& operator<<(std::ostream& os, const mint& m){
	return (os << m.val);
}

struct state{
	int head, tail, cont;
};

state get_state(string &s){
	state res = {0, 0, 0};
	int last = -1;
	for (auto c : s){
		int x = c - 'a';
		if (last >= 0 && last != x && res.cont&(1 << x)) return {-1, -1, -1};
		last = x;
		res.cont |= 1 << x;
	}
	res.head = *s.begin() - 'a';
	res.tail = *s.rbegin() - 'a';
	return res;
}

vector<state> v;

int nxt[26];
int vis[26];
int cnt[26];

int dfs(int v){
	if (vis[v]) return 0;
	vis[v] = 1;
	if (nxt[v] < 0) return 1;
	return dfs(nxt[v]);
}

// a->b or b->a
int is_ng(state a, state b){
	int c = 0;
	if (a.tail == b.head) c = 1 << a.tail;
	if (a.cont&b.cont&~c) return 1;
	return 0;
}

mint f(int n){
	if (!n) return 1;
	return (mint)n*f(n - 1);
}

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t){
		printf("Case #%d: ", t);

		v.clear();
		int n;
		cin >> n;
		bool ng = false;
		rep(i, n){
			string s;
			cin >> s;
			v.push_back(get_state(s));
			// 単体で矛盾していないかチェック
			if (v.back().cont < 0) ng = true;
		}

		// 2個で接続できないのがないかチェック
		rep(i, n) FOR(j, i + 1, n){
			if (is_ng(v[i], v[j]) && is_ng(v[j], v[i])) ng = true;
		}

		MEMSET(nxt, -1);
		rep(i, n){
			int x = v[i].head, y = v[i].tail;
			if (x == y) continue;
			if (nxt[x] >= 0) ng = true;
			nxt[x] = y;
		}

		// 全体がつながるかをチェック
		rep(i, 26){
			MEMSET(vis, 0);
			ng |= !dfs(i);
		}

		mint group = 0;
		MEMSET(vis, 0);
		rep(i, 26){
			bool ok = false;
			rep(j, n) if (v[j].head == i) ok = true;
			if(ok && dfs(i)) group += mint(1);
		}

		MEMSET(cnt, 0);
		rep(i, n){
			if (v[i].head == v[i].tail) ++cnt[v[i].head];
		}

		if (ng){
			cout << 0 << endl;
			continue;
		}
		mint ans = f(group);
		rep(i, 26){
			ans *= f(cnt[i]);
		}

		cout << ans << endl;
	}



	return 0;
}