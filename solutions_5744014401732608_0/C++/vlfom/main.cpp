#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <memory.h>
#include <cmath>

using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define FOR0(i,n) for( i = 0 ; i < n ; ++i )
#define FOR1(i,n) for( i = 1 ; i <= n ; ++i )
#define sys_p system( "pause" )
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define sz(a) (int)a.size()

typedef long long LL;

int T, T_;
int n;
int p[60][60];
int used[60];
int i, j;
LL pow2[60];
LL maxp, k;
int sleep;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    pow2[0] = 1;
    FOR1(i, 50) {
        pow2[i] = pow2[i-1] * 2LL;
    }

    cin >> T;
    FOR1(T_, T) {
        cout << "Case #" << T_ << ": ";
        cin >> n >> k;
        maxp = pow2[n-2];
        k = maxp - k;
        FOR0(i, 60) {
            FOR0(j, 60)
                p[i][j] = 0;
            used[i] = 0;
        }
        FOR1(i, n)
            for (j = i+1; j <= n; ++j) {
                p[i][j] = 1;
            }
        sleep = 0;
        while (k) {
            sleep = 1;
            for (i = n-1; i >= 1; --i) {
                if (!used[i] && pow2[i-2] <= k) {
                    k -= pow2[i-2];
                    used[i] = 1;
                    p[i][n] = 0;
                    sleep = 0;
                    break;
                }
            }
            if (sleep) {
                break;
            }
        }
        if (sleep)
            cout << "IMPOSSIBLE\n";
        else {
            cout << "POSSIBLE\n";
            FOR1(i, n) {
                FOR1(j, n) {
                    cout << p[i][j];
                }
                cout << endl;
            }
        }
    }
}