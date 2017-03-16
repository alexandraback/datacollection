#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

const int MAXN = 100;
const int MAXE = 56;

int T, E, R, N, v[MAXN], res[MAXN][MAXE], mxen;

int main() {
	scanf("%d",&T);
	for(int ct=1;ct<=T;ct++) {
		for(int i=0;i<MAXN;i++) for(int j=0;j<MAXE;j++) res[i][j] = -1000000;
		scanf("%d%d%d",&E,&R,&N);
		for(int i=1;i<=N;i++) scanf("%d",&v[i]);
		for(int i=0;i<=E;i++) res[1][i] = v[1]*(E-i);
		mxen = E+R;
		for(int i=2;i<=N;i++) {
			for(int j=R;j<=E;j++) {
				for(int k=0;k<=j;k++) {
					res[i][k] = max(res[i][k], res[i-1][j-R]+(j-k)*v[i]);
				}
			}
			mxen += R;
		}
		printf("Case #%d: %d\n", ct, res[N][0]);
	}
	return 0;
}
