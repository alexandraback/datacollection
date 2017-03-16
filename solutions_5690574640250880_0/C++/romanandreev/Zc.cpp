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
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0 , 1, -1, 1, -1, 0, 1};
char a[100][100];
int was[100][100];

int dp[52][52][52 * 52];
pair<int, int> bc[52][52][52 * 52];
int r, c, m;
void bct(int c, int last, int zap) {
    for (int i = 0; i < last; i++) {
        a[i][c - 1] = '.';
        a[i + 1][c - 1] = '.';
        a[i][c] = '.';
        a[i + 1][c] = '.';
    }
    if (c > 1) {
        bct(c - 1, bc[c][last][zap].x, bc[c][last][zap].y);
    }
}
int calc(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            if (a[nx][ny] == '*') {
                cnt++;
            }
        }
    }
    return cnt;
}
void dfs(int x, int y) {
    was[x][y] = 1;
    //cerr<<x<<" "<<y<<endl;
    if (calc(x, y) != 0) {
        return;
    }
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && was[nx][ny] == 0) {
            dfs(nx, ny);
        }
    }
}
bool check() {
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == '*') {
                cnt++;
            }
            was[i][j] = 0;
        }
    }
    if (cnt != m) return false;
    if (a[0][0] != 'c') {
        return false;
    }
    a[0][0] = '.';
    dfs(0, 0);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if ((a[i][j] == '.') ^ (was[i][j] == 1)) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
        printf("Case #%d:\n", ti);
        scanf("%d %d %d", &r, &c, &m);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                a[i][j] = '*';
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= r; i++) {
            dp[1][i][min(r, i + 1)] = 1;
        }
        for (int j = 2; j <= c; j++) {
            for (int last = 1; last <= r; last++) {
                for (int zap = 0; zap <= (j - 1) * r; zap++) if (dp[j - 1][last][zap] == 1) {
                    for (int nw = 1; nw <= last; nw++) {
                        dp[j][nw][zap + min(last + 1, r)] = 1;
                        bc[j][nw][zap + min(last + 1, r)] = mp(last, zap);
                    }
                }
            }
        }
        for (int j = 1; j <= c; j++) {
            for (int last = 1; last <= r; last++) {
                for (int zap = 0; zap <= j * r; zap++) if (dp[j][last][zap]){
                    int curzap = zap;
                    if (j < c) {
                        curzap += min(last + 1, r);
                    }
                    if (curzap == r * c - m && curzap > 0) {
                        bct(j, last, zap);
                        a[0][0] = 'c';
                        for (int i1 = 0; i1 < r; i1++) {
                            for (int i2 = 0; i2 < c; i2++) {
                                printf("%c", a[i1][i2]);
                            }
                            printf("\n");
                        }
                        assert(check());
                        goto a;
                    }
                }
            }
        }
        if (r * c - m == 1) {
            a[0][0] = 'c';
            for (int i1 = 0; i1 < r; i1++) {
                for (int i2 = 0; i2 < c; i2++) {
                    printf("%c", a[i1][i2]);
                }
                printf("\n");
            }
            assert(check());
            goto a;
        }
        printf("Impossible\n");
        a:;
    }
    return 0;
}
