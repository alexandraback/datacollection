#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define debug(x) cout<<(#x)<<":"<<x<<endl
#define PB push_back
#define MP make_pair
typedef long long int64;

#define N 10010
int rmq[N][16], idx[N][16], v[N], E, R;

int maxIdx(int l, int r) {
	if (l+1 == r) return l;
	int k = 1;
	while (l + (1<<k) < r) ++k;
	--k;
	if (rmq[l][k] > rmq[r-(1<<k)][k]) return idx[l][k]; else return idx[r-(1<<k)][k];
}

int64 calc(int l, int r, int eL, int eR) {
	int k = maxIdx(l, r);
	int can = min(eL + 1LL*(k-l)*R, 0LL+E);
	int need = max(0LL, eR-1LL*(r-k)*R);
	int64 ansL = 0, ansR = 0;
	if (l < k) ansL = calc(l, k, eL, can);
	if (k+1 < r) ansR = calc(k+1, r, need+R, eR);
	return ansL + ansR + 1LL*(can - need)*v[k];
}

int main() {
	int nT;
	cin >> nT;
	FOR(cN, 1, nT) {
		int n;
		cin >> E >> R >> n;
		REP(i, n) cin >> v[i];
		REP(i, n) rmq[i][0] = v[i], idx[i][0] = i;
		FOR(k, 1, 15) {
			int b = 1 << k, b1 = 1 << (k-1);
			REP(i, n) {
				if (i + b > n) break;
				if (rmq[i][k-1] > rmq[i+b1][k-1]) {
					rmq[i][k] = rmq[i][k-1];
					idx[i][k] = idx[i][k-1];
				} else {
					rmq[i][k] = rmq[i+b1][k-1];
					idx[i][k] = idx[i+b1][k-1];
				}
			}
		}
		cout << "Case #" << cN << ": " << calc(0, n, E, 0) << endl;
	}
}
