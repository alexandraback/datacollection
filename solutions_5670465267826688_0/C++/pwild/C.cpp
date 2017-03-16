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

struct quat {
	bool sign; ll a;
};

bool operator==(const quat &p, const quat &q) {
	return p.sign == q.sign && p.a == q.a;
}

quat operator*(const quat &p, const quat &q) {
	quat res;
	res.sign = p.sign == q.sign;
	if (!p.a || !q.a) {
		res.a = p.a + q.a;
	} else if (p.a == q.a) {
		res.sign = !res.sign;
		res.a = 0;
	} else if (p.a%3 + 1 == q.a) {
		res.a = q.a%3 + 1;
	} else {
		res.sign = !res.sign;
		res.a = p.a%3 + 1;
	}
	return res;
}
//quat q[8] = {{true,0},{true,1},{true,2},{true,3},{false,0},{false,1},{false,2},{false,3}};

const quat one = {true,0}, ii = {true,1}, jj = {true,2}, kk = {true,3};
const quat ijk[] = {ii,jj,kk};

bool go() {
	ll l, x; cin >> l >> x;
	string t; cin >> t;
	
	quat prod = one;
	FOR(i,0,l) prod = prod * ijk[t[i]-'i'];
	
	quat prodx = one;
	FOR(i,0,x % 4) prodx = prodx * prod;

	if (prodx.sign || prodx.a != 0) return false;

	string s;
	FOR(i,0,min(10LL,x)) s += t;
	l = sz(s);
	
	quat cur = one;
	ll done = 0;
	FOR(i,0,l) {
		if (done >= 2) break;
		cur = cur * ijk[s[i]-'i'];
		if (cur == ijk[done]) {
			done++;
			cur = one;
		}
	}

	return done >= 2;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
/*
	FOR(i,0,8) FOR(j,0,8) {
		quat p = q[i] * q[j];
		cout << (p.sign ? "+" : "-") << char('h'+ p.a) << " ";
		if (j == 7) cout << endl;
	}
*/
	ll TC; cin >> TC;
	FOR(tc,1,TC+1) {

		cout << "Case #" << tc << ": ";
		if (go()) cout << "YES"; else cout << "NO";
		cout << endl;
	}

}

