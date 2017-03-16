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

const int MAXN = 1000 + 10;

int ans, n;
int need[MAXN][2];
bool done[MAXN][2];

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T, t = 0;
    for (scanf("%d", &T); t < T; ++t) {
        scanf("%d", &n);
        REP(i, n) {
            scanf("%d%d", need[i], need[i] + 1);
        }
        memset(done, false, sizeof(done));
        int now = 0, step = 0;
        for ( ; ; ) {
            bool flag = false;
            REP(i, n) {
                if (!done[i][1] && !done[i][0] && now >= need[i][1]) {
                    now += 2;
                    done[i][1] = true;
                    flag = true;
                    ++step;
                    break;
                }
            }
            if (flag) continue;
            REP(i, n) {
                if (!done[i][1] && done[i][0] && now >= need[i][1]) {
                    now += 1;
                    done[i][1] = true;
                    flag = true;
                    ++step;
                    break;
                }
            }
            if (flag) continue;
            int maxval = 0, maxone = -1;
            REP(i, n) {
                if (!done[i][1] && !done[i][0] && now >= need[i][0]) {
                    if (need[i][1] > maxval) {
                        maxval = need[i][1];
                        maxone = i;
                    }
                }
            }
            if (maxone != -1) {
                done[maxone][0] = true;
                now += 1;
                ++step;
                flag = true;
            }
            if (flag) continue;
            break;
        }
        printf("Case #%d: ", t + 1);
        if (now == 2 * n) {
            printf("%d\n", step);
        } else {
            printf("Too Bad\n");
        }
    }
    return 0;
}

