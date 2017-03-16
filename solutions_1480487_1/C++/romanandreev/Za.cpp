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
int a[10000];
int main(){	
	freopen(problem_name".in","rt",stdin);
	freopen(problem_name".out","wt",stdout);
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
    	printf("Case #%d: ", ti);
    	int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		for (int i = 0; i < n; i++) {
			ld l ,r, m;
			l = 0;
			r = 1;
			for (int it = 0; it <= 100; it++) {
				m = (l + r) / 2;
//				cerr<<l<<" "<<r<<endl;
				ld ss = m;
				for (int j = 0; j < n; j++) if (i != j) {
					if (a[j] <= a[i] + sum * m) {
						ss += (a[i] + sum * m - a[j]) / (ld)sum;
					}
				}
				if (ss > 1) 
					r = m;
				else 
					l = m;				
			}
			printf("%.18lf ", (double)l * 100);
		}
    	printf("\n");
    }
	return 0;
}
