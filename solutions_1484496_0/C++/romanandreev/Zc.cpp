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
int n;
int a[10000];
int was[2000000];
int msk[2000000];
int cnt = 0;

int main(){	
	freopen(problem_name".in","rt",stdin);
	freopen(problem_name".out","wt",stdout);
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
    	printf("Case #%d:\n", ti);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		cnt++;
		bool ans = false;
		for (int i = 1; i < (1 << n); i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) if (((i >> j) & 1) == 1) {
				sum += a[j];
			}
			if (was[sum] == cnt) {
				for (int j = 0; j < n; j++) if (((i >> j) & 1) == 1) {
					printf("%d ", a[j]);
				}
				printf("\n");
				for (int j = 0; j < n; j++) if (((msk[sum] >> j) & 1) == 1) {
					printf("%d ", a[j]);
				}
				ans = true;
				break;
			}
			was[sum] = cnt;
			msk[sum] = i;
		}
		if (!ans) {
			printf("Impossible");
		}
    	printf("\n");
    }
	return 0;
}
