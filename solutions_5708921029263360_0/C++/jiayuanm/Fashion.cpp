#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <map>

using namespace std;

typedef long long LL;

int J, P, S, K, N;
int cc[15][15][15];
int ii[2000], jj[2000], kk[2000];
int si[2000], sj[2000], sk[2000];

bool check(LL msk) {
	memset(cc, 0, sizeof(cc));
	for (int i = 0; i < N; ++i) {
		if (msk & (1 << i)) {
			if ((++cc[ii[i]][0][kk[i]]) > K ||
					(++cc[ii[i]][jj[i]][0]) > K ||
					(++cc[0][jj[i]][kk[i]]) > K)
				return false;
		}
	}
	return true;
}

void solve() {
	scanf("%d%d%d%d", &J, &P, &S, &K);

	int res = 0, sol = 0;

	memset(cc, 0, sizeof(cc));
	for (int i = 1; i <= J; ++i) {
		for (int j = 1; j <= P; ++j) {
			for (int k = 1; k <= S; ++k) {
				if (cc[i][j][0] < K &&
						cc[i][0][k] < K &&
						cc[0][j][k] < K) {
					++cc[i][j][0];
					++cc[i][0][k];
					++cc[0][j][k];
					si[sol] = i;
					sj[sol] = j;
					sk[sol] = k;
					++sol;
				}
				
				ii[res] = i;
				jj[res] = j;
				kk[res] = k;
				++res;
			}
		}
	}
	
	N = J * P * S;
	LL smsk = -1;
	for (LL msk = 1L; msk < (1L << N); ++msk) {
		if (__builtin_popcount(msk) <= sol)
			continue;
		if (check(msk)) {
			smsk = msk;
			sol = __builtin_popcount(smsk);
		}
	}

	cout << " " << sol << endl;
	if (smsk == -1) {
		for (int i = 0; i < sol; ++i) {
			cout << si[i] << " " << sj[i] << " " << sk[i] << endl;
		}
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (smsk & (1 << i)) {
			cout << ii[i] << " " << jj[i] << " " << kk[i] << endl;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);

	for (int tt = 1; tt <= t; ++tt) {
		printf("Case #%d:", tt);
		solve();
	}
	return 0;	
}
