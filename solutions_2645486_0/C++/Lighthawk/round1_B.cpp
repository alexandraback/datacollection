#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;

int E, R, N;
int v[12], dp[12][12][12];

inline int getmin(int a, int b){
	return a < b ? a : b;
}

inline int getmax(int a, int b){
	return a > b ? a : b;
}


int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T, cases, lft;
	scanf("%d", &T);
	for(cases=1; cases<=T; ++cases){
		scanf("%d%d%d", &E, &R, &N);
		for(int i=0; i<N; ++i){
			scanf("%d", &v[i]);
		}
		memset(dp, 0, sizeof(dp));
		for(int i=E; i>=0; --i){
			if(E-i>=0){
				lft = E-i+R;
				if(lft > E) lft = E;
				dp[0][i][lft] = v[0]*i;
			}
		}
		for(int i=1; i<N; ++i){
			for(int j=0; j<=E; ++j){
				for(int k=E; k>=0; --k){
					//dp[i][j][k] = getmax(dp[i][j][k], dp[i-1][0][k]);
					//if(k-j>=0){
						lft = k+j-R;
						if(lft<0)continue;
						if(lft > E) lft = E;
						dp[i][j][k] = getmax(dp[i][j][k], dp[i-1][0][k]);
						dp[i][j][k] = getmax(dp[i][j][k], dp[i-1][j][lft]+v[i]*j);
					//}
				}
			}
		}

		int res = -9999999;
		for(int i=0; i<=E; ++i){
			for(int j=0; j<=E; ++j){
				res = getmax(res, dp[N-1][i][j]);
			}
		}

		printf("Case #%d: %d\n", cases, res);
	}

	return 0;
}