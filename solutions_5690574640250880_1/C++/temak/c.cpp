#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <queue>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

// #define double long double

#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int R, C, M;


void solve(int t) {
   int N = R*C - M;
   int a[R][C];
   
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            a[i][j] = 1;
        }
    }
    
    if (N == 1) {
        a[0][0] = -1;
    } else if (R == 1 && N > 0) {
        for (int j = 0; j < N; ++j) {
            a[0][j] = 0;
        }
    }
    else if (C == 1 && N > 0) {
        for (int i = 0; i < N; ++i) {
            a[i][0] = 0;
        }
    }
    else if ((N < 4 && M > 0) || N == 7 || N == 5)
    {
        printf("Case #%d:\nImpossible\n", t + 1);
        return;
    } 
    else if ((R == 2 || C == 2) && (N % 2 == 1)) {
        printf("Case #%d:\nImpossible\n", t + 1);
        return;
    } else if (C == 3 && R > 3) {
        int x = N / 2;
        x = min(x, R);
        for (int i = 0; i < x; ++ i) {
            a[i][0] = a[i][1] = 0;
        }
        int rest = N - 2 * x;
        if (rest == 1) {
            a[x-1][0] = a[x-1][1] = 1;
            a[0][2] = a[1][2] = a[2][2] = 0;
        } else {
            assert(rest == 0 || x == R);
            for (int i = 0; i < rest; ++i) {
                a[i][2] = 0;
            }
        }
    } else {
        
        int rc = N / (2*C);
        rc = min(rc, R / 2);
        for (int i = 0; i < 2 * rc; ++i) {
            for (int j = 0; j < C; ++j) {
                a[i][j] = 0;
            }
        }
        int rest = N - rc * 2 * C;
        if (rest == 1) {
            a[2 * (rc -1)][C - 1] = 1;
            a[2 * (rc -1)+ 1][C - 1] = 1;
            a[2 * rc][0] = a[2 * rc][1] = a[2 * rc][2] = 0;
        } else {
            if (rc > 0) { 
                if (rest <= C) {
                    for (int i = 0 ; i < rest; ++i) {
                        a[2 * rc][i] = 0;
                    }
                } else {
                    int p = rest / 2;
                    bool last = rest % 2 == 1;
                    for (int i = 0; i < p; ++i) {
                        a[2 * rc][i] = 0;
                        a[2 * rc + 1][i] = 0;
                    }
                    if (last) {
                        a[2* rc][p] = 0; 
                    }
                }
            } else {//rc =0
                int p = rest / 2;
                bool last = rest % 2 == 1;
                for (int i = 0; i < p; ++i) {
                    a[2 * rc][i] = 0;
                    a[2 * rc + 1][i] = 0;
                }
                if (last) {
                    a[0][p-1] = a[1][p-1] = 1;
                    a[2][0] = a[2][1] = a[2][2] = 0; 
                }
            } 
        }
    }
    
    a[0][0] = -1;
    
    int x, y, z;
    x = y = z = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (a[i][j] == -1)
                x ++;
            else if (a[i][j] == 0)
                y++;
            else 
                z++;
        }
    }
    
//     cout << x << " " << y << " " << z << endl;
    assert(x == 1);
    assert(y == (N - 1));
    assert(z == M);
    
    
    printf("Case #%d:\n", t + 1);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (a[i][j] == -1)
                printf("c");
            else if (a[i][j] == 0)
                printf(".");
            else 
                printf("*");
        }
        printf("\n");
    }
    
   
}


    
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
 
    int T;
    scanf("%d", &T);
    
    
    for (int t = 0 ; t < T; ++t) {
        scanf("%d %d %d", &R, &C, &M);
        
        solve(t);
        
    }
    
    return 0;
}

