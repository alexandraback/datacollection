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

using namespace std; 

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++) 
#define sz(v) (int)(v).size() 
#define all(v) (v).begin(), (v).end()

const double EPS = 1e-9;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	REP(_, T) {
		int n;
		cin >> n;
		vector <double> a(n), b(n);
		REP(i, n) cin >> a[i];
		REP(i, n) cin >> b[i];
		sort(all(a));
		sort(all(b));
		int res1 = 0, res2 = 0;
		for (int k = 1; k <= n; k++) {
			bool OK = 1;
			for (int i = n - k, j = 0; i <= n - 1; i++, j++) {
				if (abs(a[i] - b[j]) < EPS || a[i] + EPS < b[j]) {
					OK = 0;
					break;
				}
			}
			if (OK) res1 = k;
		}
		int ptr = 0;
		REP(i, n) {
			for (; ptr < n; ptr++) {
				if (a[i] + EPS < b[ptr]) {
					break;
				}
			}
			if (ptr < n) ++res2, ++ptr;
		}
		printf("Case #%d: %d %d\n", _ + 1, res1, n - res2);
	}
	return 0;
}