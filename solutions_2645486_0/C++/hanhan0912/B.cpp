/* hanhanw v1.1 */
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
// for Online Judge or Contests
#define MSET(x,y) memset(x,y,sizeof(x))
#define REP(x,y,z) for(int x=y; x<=z; x++)
#define FORD(x,y,z) for(int x=y; x>=z; x--)
#define FLST(x,y,z) for(int x=y; x; x=z[x])
#define SZ size
#define PB push_back

using namespace std;
//
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LD;
// start here OAO~

const int N = 15;
const int E = 15;

int dp[N][E], x[N];

void solve(int T){
	int e,r,n;
	scanf("%d %d %d", &e, &r, &n);
	MSET(dp,-1);
	REP(i,1,n) scanf("%d", &x[i]);
	dp[0][e] = 0;
	REP(i,1,n){
		REP(j,0,e){
			dp[i][j] = max(dp[i-1][j], dp[i][j]);
			REP(k,0,j){
				if (dp[i-1][j] != -1){
					int v=min(e,j-k+r);
					dp[i][v] = max(dp[i][v], dp[i-1][j]+k*x[i]);
				}
			}
		}
	}
	int ans=0;
	REP(i,0,e) ans = max(ans, dp[n][i]);
	printf("Case #%d: %d\n", T, ans);
}

int main(){
	int nT; scanf("%d", &nT);
	REP(T,1,nT) solve(T);

	
	return 0;
}
