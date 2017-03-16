#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define debug(x) cout<<(#x)<<":"<<x<<endl
typedef long long int64;

double f(int64 r, int64 k) {
	return 2.*k*r + 1.*k*(2.*k-1);
}

int main() {
	int nT;
	cin >> nT;
	FOR(cN, 1, nT) {
		int64 r, s;
		cin >> r >> s;
		int64 L = 1, R = 1LL << 40, M;
		while (L + 1 < R) {
			M = (L + R) / 2;
			if (f(r, M) > s + 1e-9) R = M; else L = M;
		}
		cout << "Case #" << cN << ": " << L << endl;
	}
}
