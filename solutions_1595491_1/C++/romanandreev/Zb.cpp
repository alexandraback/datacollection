#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int n, s, p, T;
int a[1000];
int dp[1000][1000];
int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		scanf("%d %d %d", &n, &s, &p);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= s; j++) if (dp[i][j] >= 0){
				for (int p1 = 0; p1 <= 10; p1++) 
				for (int p2 = 0; p2 <= 10; p2++) 
				for (int p3 = 0; p3 <= 10; p3++) {
					if (p1 + p2 + p3 != a[i]) {
						continue;
					}
					int mx = max(max(abs(p1 - p2), abs(p1 - p3)), abs(p2 - p3));
					if (mx > 2) continue;
					int ff = 0;
					if (p1 >= p || p2 >= p || p3 >= p) {
						ff = 1;
					}
					if (mx == 2) {
						dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + ff);
					} else {
						dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + ff);
					}
				}
	
	

			}
		}
		printf("Case #%d: %d\n", ti, dp[n][s]);
	}	
	return 0;
}
