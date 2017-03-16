#include <iostream>
#include <string>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

typedef long long ll;

int aa[32], bb[32], kk[32];
ll dp[32][2][2][2];

ll fun(int n, int a, int b, int k) {
	if (n < 0) {
		return (a && b && k);
	}
	if (dp[n][a][b][k] > -1ll) {
		return dp[n][a][b][k];
	}
	dp[n][a][b][k] = 0ll;
	int la = (a || aa[n]),
		lb = (b || bb[n]),
		lk = (k || kk[n]);
	for(int p=0;p<=la;p++) for(int q=0;q<=lb;q++) {
		int r = (p & q);
		if (k || r <= kk[n]) {
			dp[n][a][b][k] += fun(n-1, (a || (p < la)), (b || (q < lb)), (k || (r < lk)));
		}
	}
	return dp[n][a][b][k];
}

void do_case(int case_no) {
	int A, B, K;
	cin >> A >> B >> K;
	for(int i=0;i<30;i++) {
		aa[i] = !!(A&(1<<i));
		bb[i] = !!(B&(1<<i));
		kk[i] = !!(K&(1<<i));
	}
	memset(dp,-1,sizeof(dp));
	cout << "Case #" << case_no << ": " << fun(29,0,0,0) << endl;
}

int main() {
	int T;
	cin >> T;
	for(int te=1;te<=T;te++) {
		do_case(te);
	}
	return 0;
}