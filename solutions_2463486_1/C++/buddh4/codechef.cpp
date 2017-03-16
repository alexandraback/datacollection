#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <cstdarg>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

template<typename T> int size(T& a){ return (int) a.size(); }
template<typename T> T sqr(T a){ return a * a; }

#pragma comment(linker, "/STACK:256000000")

#define _(a, b) memset((a), (b), sizeof(a))
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define REPD(i, a, b) for(int i = (b) - 1; i >= a; --i)

struct Long {
	static const int MAXN = 150;
	int d[MAXN];
	int len;
	Long() : len(0) {
		_(d, 0);
	}
	Long(ll a) {
		len = 0;
		while(a > 0) {
			d[len++] = a % 10;
			a /= 10;
		}
	}
	Long(string s) {
		len = size(s);
		REPD(i, 0, size(s)) {
			d[size(s) - i - 1] = s[i] - '0';
		}
	}
	ll value() {
		ll ret = 0;
		REPD(i, 0, len) {
			ret *= 10;
			ret += d[i];
		}
		return ret;
	}
	bool operator <= (const Long & o) const {
		if(len != o.len) return len < o.len;
		REPD(i, 0, len) {
			if(d[i] != o.d[i]) return d[i] < o.d[i];
		}
		return true;
	}
	bool operator >= (const Long & o) const {
		return o <= *this;
	}
	Long square() {
		Long ret;
		ret.len = len * 2;
		REP(i, 0, len) REP(j, 0, len) {
			ret.d[i + j] += d[i] * d[j];
		}
		for(int i = 0; i < ret.len || ret.d[i] > 0; i++) {
			if(ret.d[i] > 10) {
				ret.d[i + 1] += ret.d[i] / 10;
				ret.d[i] %= 10;
			}
		}
		while(ret.d[ret.len] > 0) ret.len++;
		while(ret.d[ret.len - 1] == 0) ret.len--;

		return ret;
	}
	void print() {
		REPD(i, 0, len) printf("%d", d[i]);
	}
};

Long cur;
int ans;

Long L, R;

void check() {
	Long cur2 = cur.square();
/*
		printf("cur = ");
		cur.print();
		printf(" cur2 = ");
		cur2.print();
		printf("\n");
*/

	if(L <= cur2 && cur2 <= R) {
		ans++;
	}
}

void go(int pos, int curSum) {
	if(pos > cur.len / 2) {
		check();
		return;
	}
	if(cur.len % 2 == 0 && pos >= cur.len / 2) {
		check();
		return;
	}	

	int mult = 2;
	if(cur.len % 2 == 1 && pos == cur.len / 2) {
		mult = 1;
	}

	// 0
	if(pos > 0) {
		cur.d[pos] = cur.d[cur.len - pos - 1] = 0;
		go(pos + 1, curSum);
		cur.d[pos] = cur.d[cur.len - pos - 1] = 0;
	}
	// 1
	if(curSum + mult < 10) {
		cur.d[pos] = cur.d[cur.len - pos - 1] = 1;
		go(pos + 1, curSum + mult);
		cur.d[pos] = cur.d[cur.len - pos - 1] = 0;
	}
	// 2
	if(curSum + mult * 4 < 10) {
		cur.d[pos] = cur.d[cur.len - pos - 1] = 2;
		go(pos + 1, curSum + mult * 4);
		cur.d[pos] = cur.d[cur.len - pos - 1] = 0;
	}
	// 3
	if(pos == 0 && mult == 1) {
		cur.d[pos] = cur.d[cur.len - pos - 1] = 3;
		go(pos + 1, curSum + mult * 9);
		cur.d[pos] = cur.d[cur.len - pos - 1] = 0;
	}
}
/*
bool palin(int a) {
	vi v;
	while(a) {
		v.pb(a % 10);
		a /= 10;
	}
	for(int i = 0, j = size(v) - 1; i < j; i++, j--) {
		if(v[i] != v[j]) return false;
	}
	return true;
}

int brute(int l, int r) {
	int cur = 1;
	int ret = 0;
	while(true) {
		int cur2 = cur * cur;
		if(cur2 > r) break;

		if(palin(cur) && palin(cur2) && cur2 >= l) ret++;
		cur++;
	}
	return ret;
}

int value(string s) {
	int ret = 0;
	REP(i, 0, size(s)) {
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}
*/
void solve() {
	ans = 0;
	string l, r;
	cin >> l >> r;

	L = Long(l);
	R = Long(r);

	REP(len, 1, (R.len + 1) / 2 + 1) {
		cur.len = len;
		_(cur.d, 0);
		go(0, 0);
	}
/*
	int bruteL = value(l),
		bruteR = value(r);

	assert(bruteL == L.value());
	assert(bruteR == R.value());

	int bruteAns = brute(bruteL, bruteR);

	if(bruteAns != ans) {
		printf("FAIL %d %d BRUTE = %d\n", bruteL, bruteR, bruteAns);
	}
*/
	printf("%d\n", ans);
}

int main() {                     
#ifdef shindo
	
	if(false) {
		freopen("input.txt", "w", stdout);
		puts("1000");
		REP(i, 0, 1000) {
			printf("1 1");
			REP(j, 0, 100) printf("0");
			printf("\n");
		}
	}

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

	int T;
	scanf("%d\n", &T);
	REP(i, 0, T) {
		printf("Case #%d: ", i + 1);
		solve();
	}

	
/*	
#ifdef shindo
	printf("\n-------------\n\n\nWalltime = %.3lf\n", clock() * 1e-3);
#endif
*/
}