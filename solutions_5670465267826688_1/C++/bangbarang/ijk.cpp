#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int T,cs;
int L;
long long X;
char str[200000];
bool dp[200005][4][4][2]; // [idx][1,i,ij,ijk][1,i,j,k][sign]
int mat[4][4];
int sign[4][4];
const int n1 = 0;
const int ni = 1;
const int nj = 2;
const int nk = 3;

int main() {
	freopen("a.in", "r", stdin);
	freopen("b.out","w", stdout);
	mat[n1][n1] = n1, sign[n1][n1] = 0;
	mat[n1][ni] = ni, sign[n1][ni] = 0;
	mat[n1][nj] = nj, sign[n1][nj] = 0;
	mat[n1][nk] = nk, sign[n1][nk] = 0;

	mat[ni][n1] = ni, sign[ni][n1] = 0;
	mat[ni][ni] = n1, sign[ni][ni] = 1;
	mat[ni][nj] = nk, sign[ni][nj] = 0;
	mat[ni][nk] = nj, sign[ni][nk] = 1;

	mat[nj][n1] = nj, sign[nj][n1] = 0;
	mat[nj][ni] = nk, sign[nj][ni] = 1;
	mat[nj][nj] = n1, sign[nj][nj] = 1;
	mat[nj][nk] = ni, sign[nj][nk] = 0;

	mat[nk][n1] = nk, sign[nk][n1] = 0;
	mat[nk][ni] = nj, sign[nk][ni] = 0;
	mat[nk][nj] = ni, sign[nk][nj] = 1;
	mat[nk][nk] = n1, sign[nk][nk] = 1;

	scanf("%d",&T);
	for(cs=1;cs<=T;++cs) {
		scanf("%d%lld%s",&L,&X,str);
		X = min(X, 12ll + X % 4ll);
		for(int i=L;i<L*X;++i) str[i] = str[i%L];

		memset(dp,0,sizeof(dp));
		dp[0][0][0][0] = 1;
		for(int i=0;i<L*X;++i) {
			for(int t=0;t<4;++t) for(int x=0;x<4;++x) for(int s=0;s<2;++s) {
				int cur;
				if(str[i] == 'i') cur = 1;
				else if(str[i] == 'j') cur = 2;
				else cur = 3;

				dp[i+1][t][mat[x][cur]][s ^ sign[x][cur]]
					|= dp[i][t][x][s];
			}

			dp[i+1][ni][n1][0] |= dp[i+1][n1][ni][0];
			dp[i+1][nj][n1][0] |= dp[i+1][ni][nj][0];
			dp[i+1][nk][n1][0] |= dp[i+1][nj][nk][0];
			
			dp[i+1][ni][n1][1] |= dp[i+1][n1][ni][1];
			dp[i+1][nj][n1][1] |= dp[i+1][ni][nj][1];
			dp[i+1][nk][n1][1] |= dp[i+1][nj][nk][1];
		}

		if(dp[L*X][3][0][0]) {
			printf("Case #%d: YES\n",cs);
		}
		else {
			printf("Case #%d: NO\n",cs);
		}
	}
}

