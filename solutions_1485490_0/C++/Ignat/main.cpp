#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define DEBUG(x)
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;


// Enlarge MSVS stack size
#pragma comment(linker, "/STACK:16777216")

#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("1.in", "r", stdin);
    freopen("_.out", "w", stdout);
}

const int MAX = 100 + 5;
int64 a[MAX], b[MAX], ta[MAX], tb[MAX];

int64 ca[MAX][MAX][MAX];
int64 cb[MAX][MAX][MAX];

int64 res[MAX][MAX];

int main()
{
    initialize();


    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> ta[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i] >> tb[i];
        }

        memset(ca, 0, sizeof(ca));
        for (int t = 0; t < MAX; ++t) {
            for (int i = 0; i <= n; ++i) {
                for (int j = i + 1; j <= n; ++j) {
                    ca[t][i][j] = ca[t][i][j - 1];
                    if (ta[j - 1] == t) ca[t][i][j] += a[j - 1];
                }
            }
        }
        
        memset(cb, 0, sizeof(cb));
        for (int t = 0; t < MAX; ++t) {
            for (int i = 0; i <= m; ++i) {
                for (int j = i + 1; j <= m; ++j) {
                    cb[t][i][j] = cb[t][i][j - 1];
                    if (tb[j - 1] == t) cb[t][i][j] += b[j - 1];
                }
            }
        }

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0) {
                    res[i][j] = 0;
                    continue;
                }
                res[i][j] = 0;
                for (int type: {tb[j - 1], ta[i - 1]}) {
                    for (int pi = 0; pi < i; ++pi) {
                        for (int pj = 0; pj < j; ++pj) {
                            res[i][j] = max(res[i][j],
                                    res[pi][pj] + min(ca[type][pi][i], cb[type][pj][j]));
                        }
                    }
                    
                }
            }
        }
        cout << "Case #" << tt << ": " << res[n][m] << "\n"; 
    }
    
    return 0;
}
