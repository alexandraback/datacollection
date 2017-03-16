/*
 * B.cpp
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

int sum(const VI& a) {
	int s = 0;
	REP(i, sz(a)) s += a[i];
	return s;
}
int f(const string& s) {
	VI a(sz(s));
	REP(i, sz(s)) {
		a[i] = s[i] == '+';
	}
	int ans = 0;
	while(sum(a) != sz(a)) {
		int i = 1;
		while(i < sz(a) && a[i] == a[i-1]) {
			++i;
		}
		reverse(a.begin(), a.begin() + i);
		REP(j, i) {
			a[j] = 1 - a[j];
		}
		++ans;
	}
	return ans;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int tc;
	cin >> tc;
	FOR(t, 1, tc+1) {
		string s;
		cin >> s;
		int x = f(s);
		printf("Case #%d: %d\n", t, x);
	}
	fclose(stdout);
	return 0;
}

