#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

typedef pair<int, int> pii;
typedef long long ll;

bool n[50][50];

void solve() {
	ll b;
	ll m;
	cin >> b >> m;
	if (m > (1LL << (b - 2))) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << "POSSIBLE" << endl;
	REP(i,b) {
		REP(j,b) {
			if (i >= j) {
				cout << 0;
				continue;
			}
			ll bit = 1LL << (b - i - 2);
			if (bit <= m) {
				cout << 1;
			} else {
				ll bit2 = 1LL << (b - j - 2);
				if ((m & bit2) && j != b-1) {
					cout << 1;
				} else {
					cout << 0;
				}
			}
		}
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cout << "Case #" << (i+1) << ": ";
		solve();
	}
}