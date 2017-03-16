/* hanhanw v1.2 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
// for Online Judge or Contests
#define MSET(x,y) memset(x,y,sizeof(x))
#define REP(x,y,z) for(int x=y; x<=z; x++)
#define FORD(x,y,z) for(int x=y; x>=z; x--)
#define FLST(x,y,z) for(int x=y; x; x=z[x])
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define SZ size
#define PB push_back

using namespace std;
//
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LD;
// start here OAO~


int x[514],dp[514];

void solve(int T){
	int n, a, ans=2147483647>>1;
	scanf("%d%d",&a,&n);
	REP(i,1,n) scanf("%d", &x[i]);
	sort(x+1,x+1+n);
	int cnt=0;
	REP(i,1,n) dp[i] = 2147483647>>1;
	REP(i,1,n){
		if (x[i] >= a && a == 1) break;
		if (x[i] < a){
			a += x[i];
		} else {
			while (x[i] >= a){
				a += a-1;
				cnt++;
			}
			a += x[i];
		}
		dp[i] = cnt;
	}
	ans = n;
	REP(i,1,n)
		ans = min(ans,dp[i]+n-i);
	printf("Case #%d: %d\n", T, ans);
}
int main(){
	int nT; scanf("%d", &nT);
	REP(i,1,nT) solve(i);

	return 0;
}
