#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cctype>

#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, m, n) for (int i=m; i<=n; i++)
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

ll best = LLONG_MAX;
ll best_a;
ll best_b;
string res_a;
string res_b;

ll prevod(string s) {
	ll res = 0;
	REP(i, s.size()) {
		res = res*10 + s[i]-'0';
	}
	return res;
}

ll abso(ll x) {
	if (x<0) return -x;
	return x;
}

void is_best(int res, int va, int vb, string a, string b) {
	if (res < best || (res==best && va<best_a) || (res==best && va==best_a && vb<best_b)) {
		best = res;
		best_a = va;
		best_b = vb;
		res_a = a;
		res_b = b;
	}
}

pair<string,string> zkus(string A, string B, int k, int aa, int bb) {
	string a;
	string b;
	REP(i, k) {
		if (A[i] == '?' && B[i]=='?') {
			a.push_back('0');
			b.push_back('0');
		}
		else if (A[i]=='?') {
			a.push_back(B[i]);
			b.push_back(B[i]);
		}
		else if (B[i]=='?') {
			a.push_back(A[i]);
			b.push_back(A[i]);
		}
		else {
			a.push_back(A[i]);
			b.push_back(B[i]);
		}
	}
	a.push_back('0'+aa);
	b.push_back('0'+bb);
	FOR(i, k+1, A.size()-1) {
		a.push_back((A[i]=='?')?'0':A[i]);
		b.push_back((B[i]=='?')?'9':B[i]);
	}
	return make_pair(a,b);
}

void solve() {
	best = LLONG_MAX;
	string A, B;
	cin >> A >> B;
	REP(k, A.size()) FOR (aa, 0, 9) FOR (bb, 0, 9) {
		if (A[k]!='?' && A[k]!='0'+aa) continue;
		if (B[k]!='?' && B[k]!='0'+bb) continue;
		pair<string,string> r = zkus(A,B,k,aa,bb);
		int val_a = prevod(r.first);
		int val_b = prevod(r.second);
		int res = abso(val_b - val_a);
		is_best(res, val_a, val_b, r.first, r.second);

		r = zkus(B,A,k,bb,aa);
		val_a = prevod(r.second);
		val_b = prevod(r.first);
		res = abso(val_b - val_a);
		is_best(res, val_a, val_b, r.second, r.first);
	}
	cout << res_a << " " << res_b << endl;
}

int main() {
	int t; scanf("%d", &t);
	REP(i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
