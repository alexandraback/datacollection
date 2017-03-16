#pragma comment(linker,"/stack:256000000")

#include <cmath> 
#include <ctime> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <set> 
#include <map> 
#include <cstring> 
#include <cstdlib> 
#include <queue> 
#include <cstdio> 
#include <cfloat>
#include <cassert>
#include <ctime>

using namespace std; 

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++) 
#define sz(v) (int)(v).size() 
#define all(v) (v).begin(), (v).end()

void solve() {
	int n;
	cin >> n;
	vector <pair <string, int> > s(n);
	REP(i, n) {
		cin >> s[i].first;
		s[i].second = i;
	}
	sort(all(s));
	int res = 0;
	do {
		string t;
		REP(i, sz(s)) {
			t += s[i].first;
		}
		t += ".";
		vector <bool> u(26, 0);
		char p = t[0];
		bool OK = 1;
		REP(i, sz(t)) {
			if (t[i] != p) {
				u[p - 'a'] = 1;
				p = t[i];
				if (i == sz(t) - 1) break;
				if (u[p - 'a']) {
					OK = 0;
					break;
				}
			}
		}
		if (OK) ++res;
	} while (next_permutation(all(s)));
	cout << res << endl;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long start = clock();
#endif
	int T;
	cin >> T;
	for (int tst = 1; tst <= T; tst++) {
		cerr << tst << endl;
		cout << "Case #" << tst << ": ";
		solve();
	}
	return 0;
}