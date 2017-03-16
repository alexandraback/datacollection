#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <sstream>
#include <string>
using namespace std;
#define out(X) cerr << #X << ": " << (X) << endl
#define SZ(X) ((int)(X.size()))
#define REP(I,N) for (int I = 0; I < (N); ++I)
#define FOR(I,L,H) for (int I = (L); I < (H); ++I)
#define MP(X,Y) make_pair((X),(Y))
#define PB push_back
#define ALL(X) X.begin(), X.end()
template <typename T> inline bool checkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template <typename T> inline bool checkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
typedef long long lint;

const int MAXN  = 100000 + 10;

int n, m;
double p[MAXN], pp[MAXN];
double ans;

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T, t = 0;
    for (scanf("%d", &T); t < T; ++t) {
        scanf("%d %d", &m, &n);
        FOR(i, 1, m + 1) {
            scanf("%lf", p + i);
            if (i != 1) {
                pp[i] = pp[i - 1] * p[i]; 
            } else {
                pp[i] = p[i];
            }
        }
        ans = 1e10;
        checkmin(ans, pp[m] * (n - m + 1) + (1 - pp[m]) * (n - m + 1 + n + 1));
        checkmin(ans, 1.0 + n + 1);
        checkmin(ans, 0.0 + m + n + 1);
        for (int back = 1; back < m; ++back) {
            checkmin(ans, pp[m - back] * (back + n - m + back + 1) + (1 - pp[m - back]) * (back + n - m + back + 1 + n + 1));
        }
        printf("Case #%d: %f\n", t + 1, ans);
    } 
    return 0;
}

