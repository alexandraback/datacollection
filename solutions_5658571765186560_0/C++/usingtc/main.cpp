#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define dbg(x) cout << #x << " = " << (x) << endl
#define dbg2(x,y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define dbg3(x,y,z) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl

template<class T> inline T cabs(T x) { return x > 0 ? x : (-x); }
template<class T> inline T gcd(T x, T y) { return (y == 0) ? x : gcd(y, x % y); }

#define out(x) cout << (x) << endl
#define out2(x,y) cout << (x) << " " << (y) << endl
#define out3(x,y,z) cout << (x) << " " << (y) << " " << (z) << endl

int dp[5][5][5];

void init()
{
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= 4; i ++) {
        for(int j = 1; j <= 4; j ++) {
            for(int k = 1; k <= 2; k ++) {
                if( (i * j) % k == 0 )
                    dp[i][j][k] = 1;
                else
                    dp[i][j][k] = -1;
            }
            for(int k = 3; k <= 4; k ++) {
                if( i * j < k || (i * j) % k != 0 )
                    dp[i][j][k] = -1;
                else {
                    ;
                }
            }
        }
    }

    dp[1][3][3] = -1;
    dp[1][4][4] = -1;
    dp[2][2][4] = -1;
    dp[2][3][3] = 1;
    dp[2][4][4] = -1;
    dp[3][1][3] = -1;
    dp[3][2][3] = 1;
    dp[3][3][3] = 1; //
    dp[3][4][3] = 1;
    dp[3][4][4] = 1;
    dp[4][1][4] = -1;
    dp[4][2][4] = -1; //
    dp[4][3][3] = 1;
    dp[4][3][4] = 1;
    dp[4][4][4] = 1;

    for(int i = 1; i <= 4; i ++) {
        for(int j = 1; j <= 4; j ++) {
            for(int k = 1; k <= 4; k ++) {
                if( dp[i][j][k] == 0 ) {
                    printf("dp[%d][%d][%d] = ;\n", i, j, k);
                }
            }
        }
    }
}

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    init();
    int idx = 0, nt;
    scanf("%d", &nt);
    for(; nt > 0; nt --) {
        int X, R, C;
        scanf("%d %d %d", &X, &R, &C);
        printf("Case #%d: %s\n", ++ idx, dp[R][C][X] == 1 ? "GABRIEL" : "RICHARD");
    }
    return 0;
}
