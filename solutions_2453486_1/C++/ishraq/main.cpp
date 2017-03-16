// Ishraq Huda
// tic
// Sat, Apr 13, 2013 10:30:23 AM

#include <cstdio>
#include <cctype>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for(int i=(a);i<(b);i++)
#define FR(i,a,b) for (int i=(a)-1;i>=(b);i--)
#define fi(a) FO(i,0,a)
#define fj(a) FO(j,0,a)
#define fk(a) FO(k,0,a)
#define all(c) (c).begin(), (c).end()
#define fit(c,i) \
    for (typeof((c).begin()) i=(c).begin(); i != (c).end(); i++)
#define sd(n) scanf(" %d ", &(n))

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int main() {
#ifndef DEBUG
    // freopen("tic.in", "r", stdin);
    // freopen("tic.out", "w", stdout);
#endif

    int T;
    sd(T);
    FO(Z,1,T+1) {
        char grid[4][5];
        fi(4) scanf(" %s", grid[i]);

        bool X = false, O = false, GO = true;;
        
        FO(y, 0, 4) {
            bool xwin = true;
            bool owin = true;
            FO(x, 0, 4) {
                if (grid[y][x] != 'X' && grid[y][x] != 'T') xwin = false;
                if (grid[y][x] != 'O' && grid[y][x] != 'T') owin = false;
                if (grid[y][x] == '.') GO = false;
            }
            X = X || xwin;
            O = O || owin;
        }
        FO(x, 0, 4) {
            bool xwin = true;
            bool owin = true;
            FO(y, 0, 4) {
                if (grid[y][x] != 'X' && grid[y][x] != 'T') xwin = false;
                if (grid[y][x] != 'O' && grid[y][x] != 'T') owin = false;
                if (grid[y][x] == '.') GO = false;
            }
            X = X || xwin;
            O = O || owin;
        }


        bool xwin = true, owin = true;
        fi(4) {
            if (grid[i][i] != 'X' && grid[i][i] != 'T') xwin = false;
            if (grid[i][i] != 'O' && grid[i][i] != 'T') owin = false;
        }
        X = X || xwin;
        O = O || owin;

        xwin = true, owin = true;
        fi(4) {
            if (grid[3-i][i] != 'X' && grid[3-i][i] != 'T') xwin = false;
            if (grid[3-i][i] != 'O' && grid[3-i][i] != 'T') owin = false;
        }
        X = X || xwin;
        O = O || owin;

        printf("Case #%d: ", Z);
        if (X) printf("X won");
        else if (O) printf("O won");
        else if (GO) printf("Draw");
        else printf("Game has not completed");
        printf("\n");
    }

    return 0;
}

