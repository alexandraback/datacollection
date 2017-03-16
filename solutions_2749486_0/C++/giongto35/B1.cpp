#include <iostream>
#include <cstdio>
#include <cstdlib>
#define FOR(i,a,b) for(int i=(a),_b=(b); i <= _b; ++i)
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int ntest; cin >> ntest;
	FOR(test,1,ntest) {
		int x, y; cin >> x >> y;
		printf("Case #%d: ", test);
		if (x > 0) {
			FOR(i,1,x) cout << "WE";
		}
		else if (x < 0) {
			FOR(i,1,-x) cout << "EW";
		}
		if (y > 0) {
			FOR(i,1,y) cout << "SN";
		}
		else if (y < 0) {
			FOR(i,1,-y) cout << "NS";
		}
		puts("");
	}
	return 0;
}
