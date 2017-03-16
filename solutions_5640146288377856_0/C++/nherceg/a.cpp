#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;++i)
#define FOR(i, a, b) for(int i = a;i < b;++i)
#define F first
#define S second
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int, int> ii;
typedef long long int ll;

int r, c, w;

int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cin >> r >> c >> w;
		cout << "Case #" << i + 1 << ": ";
		if(w == 1) {
			cout << r*c << "\n";
			continue;
		}
		if(c == w) {
			cout << r - 1 + w << "\n";
			continue;
		}
		if(c % w) cout << c/w*r + w << "\n";
		else cout << c/w*r - 1 + w << "\n";
	}
}