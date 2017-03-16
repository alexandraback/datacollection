#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

#define pf printf
#define sf scanf
#define VI vector<int>
#define pb push_back
#define fo(a,b) for((a)=0;(a)<(b);a++)

#define debug 0
const int inf = 1000000000;

long long ncr[305][305] = {0}; void gen_ncr(int n) { int i, j; fo(i, n+1) ncr[i][0] = 1; for(i=1;i<=n;i++) for(j=1;j<=n;j++) ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];}
double dis(double x1, double y1, double x2, double y2) { return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); }

int n, m;
double h;
int C[105][105];
int F[105][105];
int move[][2] = {0, 1, 0, -1, 1, 0, -1, 0};

struct node {
	int r, c;
};

bool valid(int r, int c) {
	return r >= 0 && c >= 0 & r < n && c < m;
}

double bfs() {
	double dp[105][105];
	int i, j;
	for(i=0; i<n; i++) for(j=0; j<m; j++) dp[i][j] =  inf;
	dp[0][0] = 0;
	queue<node> Q; while( !Q.empty() ) Q.pop();
	node A;
	A.r = A.c = 0;
	Q.push(A);
	
	while ( !Q.empty() ) {
		node A = Q.front();
		Q.pop();

		int i;
		for(i=0; i<4; i++) {
			int rr = A.r + move[i][0];
			int cc = A.c + move[i][1];
			if( valid(rr, cc) ) {
				double wl = h - dp[A.r][A.c] * 10;
				bool yes = true;
				int ca = C[rr][cc];
				int fa = F[rr][cc];
				int fc = F[A.r][A.c];
				int cec = C[A.r][A.c];
				if( (ca - fc) >= 50 && (ca - fa) >= 50 && (ca - wl) >= 50 && (cec - fa) >= 50) {
					if( fabs(dp[A.r][A.c]) < 1e-9 && fabs(dp[rr][cc]) > 1e-9 ) {
						dp[ rr] [cc] = 0;
						node T;
						T.r = rr; T.c = cc;
						Q.push(T);
					}
					else {
						double dif = wl - fc;
						double newcost;
						if( dif >= 20 || fabs(dif-20) < 1e-9) {
							newcost = dp[A.r][A.c] + 1;
						}
						else newcost = dp[A.r][A.c] + 10;
						if( dp[rr][cc] > newcost ) {
							dp[rr][cc]  = newcost;
							node T;
							T.r = rr; T.c = cc;
							Q.push(T);
						}
						
					}
				}
				else {
					if( (ca - fc) >= 50 && (ca - fa) >= 50 &&  (cec - fa) >= 50)  { // water level high
						double rwl = ca - 50;
						double dif = wl - rwl;
						double wt = dif / 10;
						wl = rwl;
						dif = wl - fc;
						double newcost;
						if( dif >= 20 || fabs(dif-20) < 1e-9) {
							newcost = dp[A.r][A.c] + 1 + wt;
						}
						else newcost = dp[A.r][A.c] + 10 + wt;
						
                        if( dp[rr][cc] > newcost ) {
							dp[rr][cc]  = newcost;
							node T;
							T.r = rr; T.c = cc;
							Q.push(T);
						}
					}
				}
			}
		}
	}
	return dp[n-1][m-1];
}

int main() {
	int test, cases = 1;
	cin >> test;
	for( cases=1; cases<=test; cases++ ) {
		cin >> h >> n >> m;
		int i, j;
		for(i=0; i<n; i++) for(j=0; j<m; j++) cin >> C[i][j];
		for(i=0; i<n; i++) for(j=0; j<m; j++) cin >> F[i][j];

		double res = bfs();
		pf("Case #%d: %.6lf\n", cases, res);
	}
	return 0;
}

