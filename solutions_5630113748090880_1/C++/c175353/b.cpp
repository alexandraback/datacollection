#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define FOR(i,a,b) for (int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define PB push_back

int ap[2510];

int main() {
	int tN;
	cin >> tN;
	FOR(cN, 1, tN) {
		int n;
		cin >> n;
		memset(ap, 0, sizeof(ap));
		REP(i, n+n-1)
		REP(j, n) {
			int x;
			cin >> x;
			++ap[x];
		}
		cout << "Case #" << cN << ":";
		FOR(h, 1, 2500) if (ap[h] & 1) cout << " " << h;
		cout << endl;
	}
}
