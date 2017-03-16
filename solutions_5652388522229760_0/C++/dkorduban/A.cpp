/*
 * A.cpp
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

const int MAX_IT = 1000;

int fill(ll k, VI& used) {
	int ret = 0;
	while(k > 0) {
		int d = k % 10;
		ret += !(used[d]);
		used[d] = 1;
		k /= 10;
	}
	return ret;
}

ll f(ll n) {
	int dc = 0;
	VI used(10);
	ll k = n;
	REP(it, MAX_IT) {
		dc += fill(k, used);
		if (dc == 10) {
			return k;
		}
		k += n;
//		if (it > 40) {
//			cout << "n = " << n << " it =" << it << endl;
//		}
	}
	return -1;
}


int main() {
//	REP(i, 1000000+1) {
//		f(i);
//	}
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int tc;
	cin >> tc;
	FOR(t, 1, tc+1) {
		int n;
		cin >> n;
		ll x = f(n);
		printf("Case #%d: ", t);
		if (x == -1) {
			printf("INSOMNIA\n");
		} else {
			printf("%lld\n", x);
		}
	}
	fclose(stdout);
	return 0;
}

