#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <fstream>

using namespace std;

#define DEBUG(x) cout<< #x << ':' << x << endl
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,n-1)
#define FORIT(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()
#define ZERO(a) memset(a, 0, sizeof(a))
#define PB push_back
#define MP make_pair
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define abs(x) (((x)^((x)>>31))-((x)>>31))
const int inf = ~0u>>1;

typedef long long ll;

int dp[15][10];

int main()
{
	int T;
	int E,R,N;
	cin>>T;
	FOR(ii,1,T){
		memset(dp,0,sizeof(dp));
		cin>>E>>R>>N;
		FOR(i,1,N){
			int v;
			cin>>v;
			FOR(j,1,E){
				FOR(k,0,j){
					int remain=j-k+R;
					remain = min(remain,E);
					int valg=k*v;
					dp[i][remain] = max(dp[i][remain],dp[i-1][j]+valg);
				}
			}
			//FOR(ix,1,E) cout<<dp[i][ix]<<" ";cout<<endl;
		}
		int max_dp = -1;
		FOR(i,1,E) max_dp = max(max_dp,dp[N][i]);
		printf("Case #%d: %d\n",ii,max_dp);
	}
	return 0;
}
