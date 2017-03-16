#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
//#include <assert.h>

using namespace std;

#define For(i,a,b,d) for (int i = (a); i != (b); i += d)
#define FORD(i,a,b) for (int i = (a); i >= b; i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REPD(i,n) for (int i = (n - 1); i >= 0; i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
#define CLR(a,x) memset(a,x,sizeof(a))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define Abs(a) ((a < 0) ? -(a) : a)
#define sqr(a) ((a)*(a))
#define pb push_back
#define mp make_pair
#define eps 10e-5
#define Inf 1000000000
#define Mi 1000000007
#define N 515
#define K 20

typedef double ld;
typedef long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;
typedef enum {heavy, light} lbl;

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

inline ll gcd (ll a, ll b){ return (!b ? a : gcd (b, a % b)); }

const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

int rand15() { return rand() % (1 << 15); }
int rand30() { return (rand15() << 15) + rand15(); }
int rand(int L, int R) { if (L > R) return R; return rand30() % (R - L + 1) + L; }
ld random(ld L, ld R) { return rand(ceil((L-eps)*100), floor((R+eps)*100)) / 100.0;}

//#define DEBUG

char A[10][10];

bool check(char pl) {
    bool fld1 = true, fld2 = true;
    REP(i, 4) {
        bool flr = true, flc = true;
        REP(j, 4) {
            if (A[i][j] != pl && A[i][j] != 'T')
                flr = false;
            if (A[j][i] != pl && A[j][i] != 'T')
                flc = false;
        }
        if (flc || flr)
            return true;
        if (A[i][i] != pl && A[i][i] != 'T')
            fld1 = false;
        if (A[i][3 - i] != pl && A[i][3 - i] != 'T')
            fld2 = false;
    }
    if (fld1 || fld2)
        return true;
    return false;
}

bool isempty(){
    REP(i, 4)
        REP(j, 4)
            if (A[i][j] == '.')
                return true;
    return false;
}

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main ()
{
    std::ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "wb", stdout);
    #endif
    int T;
    scanf ("%d", &T);
    REP(t, T) {
        scanf("\n");
        REP(i, 4)
            scanf("%s\n", &A[i]);
        printf("Case #%d: ", t + 1);
        if (check('X')) {
            printf("X won\n");
        } else if (check('O')) {
            printf("O won\n");
        } else if (isempty()) {
            printf("Game has not completed\n");
        } else printf("Draw\n");
    }
    return 0;
}
