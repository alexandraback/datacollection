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
int T, a, b;
ll ans;
int stp[100];
map<pi, int> M;
void rotat(int x) {
	int s = 0;
	int y = x;
	while (y > 0) {
		s++;
		y /= 10;
	}
	for (int i = 0; i < s; i++) {
		int y = x / stp[i] + (x % stp[i]) * stp[s - i];
		if (x < y && y >= a && y <= b && x >= a && x <= b) {
			if (M[mp(x, y)] == 0) {
				M[mp(x, y)] = 1;
				ans++;
			}
		}
	}
}
int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	stp[0] = 1;
	for (int i = 1; i <= 9; i++) {
		stp[i] = stp[i - 1] * 10;
	}
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		scanf("%d %d", &a, &b);
		ans = 0;
		M.clear();
		for (int i = a; i <= b; i++) {
			rotat(i);
		}
		printf("Case #%d: %I64d\n", ti, ans);
	}
	return 0;
}
