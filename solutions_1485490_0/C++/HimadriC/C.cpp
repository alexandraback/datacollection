#include <cmath>
#include <queue>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>

using namespace std;

#define sz(X) ((int)X.size())
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define fr(i,a,b) for(int i=a; i<=b; i++)
#define it(it) __typeof((it)->begin())
#define foreach(v) for(IT(v) it=(v)->begin(); it!=(v)->end(); it++)
#define all(x) (x).begin(),x.end()
#define pb(x) push_back(x)
#define VI vector<long long> 
#define VVI vector<vector<long long> >
#define VS vector<string>
typedef long long ll;

int main()
{
	
	//freopen("B-small-0.in","r",stdin);
    int T, N, M;
    cin >> T;
    rep(zz,T) {
		cin >> N >> M;
		VVI a(2, VI(N));
		VI A(N);
		VVI b(2,VI(M));
		VI B(M);
		rep(i,N) cin >> a[0][i] >> A[i];
		rep(i,N) a[1][i]=a[0][i];
		rep(i,M) cin >> b[0][i] >> B[i];
		VVI dp(N+1,VI(M+1));
		rep(i,N) {
			int x = N-1-i;			
			int curr=0;
			rep(i,N) a[0][i]=a[1][i];
			rep(j,M) {
			int y = M-1-j;
			//b[1-curr][y]=b[curr][y];
			if (A[x] == B[y]) {
				if (a[curr][x] < b[curr][y]) {
					dp[i+1][j+1] = a[curr][x] + max(dp[i][j+1],dp[i+1][j]);
					b[curr][y]=b[curr][y]-a[curr][x];
					a[curr][x]=0;
				}
				else if (a[curr][x] == b[curr][y]) {
					dp[i+1][j+1] = a[curr][x] + max(dp[i][j],max(dp[i+1][j],dp[i][j+1]));
					a[curr][x]=0;
					b[curr][y]=0;
				}
				else {
					dp[i+1][j+1] = b[curr][y] + max(dp[i+1][j],dp[i][j+1]);
					
					a[curr][x]=a[curr][x]-b[curr][y];					
					b[curr][y]=0;
				}
			} else {
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
			}
			
		}
		printf("Case #%d: %lld\n", zz+1, dp[N][M]);
	}
    return 0;
}
