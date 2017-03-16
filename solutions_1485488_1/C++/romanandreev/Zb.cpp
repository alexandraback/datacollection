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
int h, n, m;
const int maxn = 100000;
int num(int x, int y) {
	return x + y * n;
}
int d[maxn];
int was[maxn];
const int inf = 1e9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
bool ins(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
int c[110][110];
int f[110][110];

int main(){	
	freopen(problem_name".in","rt",stdin);
	freopen(problem_name".out","wt",stdout);
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
    	printf("Case #%d: ", ti);
    	cerr<<ti<<endl;
    	scanf("%d %d %d", &h, &n, &m);
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			scanf("%d", &c[i][j]);
    		}
    	}
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			scanf("%d", &f[i][j]);
    		}
    	}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				d[num(i, j)] = inf;
				was[num(i, j)] = 0;
			}
		}
		d[num(0, 0)] = -1000;			
		while (1) {			
			int mn = -1;
			for (int i = 0; i < n * m; i++) {
				if (was[i] == 0 && (mn == -1 || d[i] < d[mn])) {
					mn = i;
				}
			}
			if (mn == -1 || d[mn] == inf) break;
			was[mn] = 1;
			int x = mn % n;
			int y = mn / n;
			for (int t = 0; t < 4; t++) {
				int nx = x + dx[t];
				int ny = y + dy[t];
                if (ins(nx, ny) && c[nx][ny] >= f[nx][ny] + 50 && c[nx][ny] >= f[x][y] + 50 && f[nx][ny] + 50 <= c[x][y]) {
                	int t0 = max(d[mn], h - (c[nx][ny] - 50));
                	if (t0 <= 0) {
                		t0 = -1000;
                	}
					if (h - t0 >= f[x][y] + 20) {
						t0 += 10;
					} else {
						t0 += 100;
					}
					if (t0 <= 0) {
                		t0 = -1000;
                	}
					d[num(nx, ny)] = min(d[num(nx, ny)], t0);
                }
			}
		}
		printf("%.18lf", (double)max(0, d[num(n - 1, m - 1)]) / 10.);
    	printf("\n");
    }
	return 0;
}
