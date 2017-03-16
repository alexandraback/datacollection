/*
 * D.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: dkorduban
 */





#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#define FOR(i,s,n) for(int i=(s); i<(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define sz(x) int((x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> VI;

string f(const string& seed, const string& s, int t) {
	if (t == 1) {
		return s;
	}
	string gold(sz(seed), 'G');
	string ans = "";
	REP(i, sz(s)) {
		if(s[i] == 'G') {
			ans += gold;
		} else {
			ans += seed;
		}
	}
	return f(seed, ans, t - 1);
}

void g(int k, int c) {
	vector<string> a;
	REP(i, k) {
		string s(k, 'L');
		s[i] = 'G';
		s = f(s, s, c);
		a.pb(s);
	}
	VI b(c);
	REP(i, c) cin >> b[i];
	int pos = 0;
	REP(i, c) {
		pos = k * pos + b[i];
	}
	REP(i, k) if(a[i][pos] == 'G') cout << i << " ";
	cout << endl;
}

ll ff(VI b, ll k) {
	ll pos = 0;
	REP(i, sz(b)) {
		if (b[i] < 0 || b[i] >= k) {
			k = 0;
			cout << "WTF";
			cout << (1/k) << endl;

		}
		pos = k * pos + b[i];
	}
	return pos;
}

vector<ll> h(int k, int c, int s) {
	vector<ll> ret;
	VI pos(k);
	REP(i, s) {
		if (i * c >= k) {
			break;
		}
		// i * c < k
		VI b;
		REP(j, c) {
			b.pb(min(k - 1, i * c + j));
		}
		ret.pb(ff(b, k));
	}
	return ret;
}

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);

//	while (true) {
////		string s;
////		int c;
////		cin >> s >> c;
////		cout << f(s, s, c) << endl;
//		int k, c;
//		cin >> k >> c;
//		g(k, c);
//	}
	int tc;
	cin >> tc;
	FOR(t, 1, tc+1) {
		int k, c, s;
		cin >> k >> c >> s;
		printf("Case #%d:", t);
		if (s*c < k) {
			printf(" IMPOSSIBLE\n");
			continue;
		}
		vector<ll> ans = h(k, c, s);
		REP(i, sz(ans)) {
			printf(" %lld", ans[i]+1);
		}
		printf("\n");
	}
	fclose(stdout);
	return 0;
}
