#include <bits/stdc++.h>
using namespace std;

const int LIM = 1000;
typedef long long ll;

int N,J;
int prime[168];
int res[1000][11][32];

void solve() {
	scanf("%d%d",&N,&J);
	int on = 0;
	for (int i=2;i<=LIM;i++) {
		bool ok = 1;
		for (int j=2;j*j<=i;j++) {
			if (i%j==0) ok = 0;
		}
		if (ok) {
			prime[on++] = i;
			for (int j=2;j<=10;j++) {
				res[i][j][0] = 1;
				for (int k=1;k<32;k++) {
					res[i][j][k] = (res[i][j][k-1]*j)%i;
				}
			}
		}
	}
	int i = (1<<(N-1))+1;
	while (J) {
		bool ok = 1;
		vector<int> ans;
		for (int j=2;j<=10;j++) {
			for (int p: prime) {
				int cur = 0;
				for (int k=0;k<N;k++) {
					if (i&(1<<k)) cur = (cur+res[p][j][k])%p;
				}
				if (!cur) {
					ans.push_back(p);
					break;
				}
			}
			if (ans.size()<j-1) ok = 0;
		}
		if (ok) {
			for (int k=N-1;k>=0;k--) {
				if (i&(1<<k)) printf("1");
				else printf("0");
			}
			for (int j: ans) printf(" %d",j);
			printf("\n");
			J-=1;
		}
		i+=2;
	}
}

int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		printf("Case #%d:\n",t);
		solve();
	}

	return 0;
}
