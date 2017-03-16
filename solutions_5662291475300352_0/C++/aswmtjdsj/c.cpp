/* base IO */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>

/* data structure */
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>

/* alrotihm and math */
#include <algorithm>
#include <random>
#include <cmath>

/* run-time */
#include <cstdlib>
#include <ctime>
#include <climits>

/* system dependent */
#include <sys/time.h>

using namespace std;

#define VI vector<int>
#define VD vector<double>
#define PII pair<int, int>
#define PDD pair<double, double>
#define PB push_back
#define MP make_pair
#define len(x) ((x).size())

const int inf = INT_MAX;
const long long inf_ll = 0x7f7f7f7f;
const long double eps = 1e-10;

/*
 * 0 1 2
 * 3   4
 * 5 6 7
 */
const int bfs_dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int bfs_dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
 *   3  
 * 2   0
 *   1  
 */
const int dfs_dy[] = {0, 1, 0, -1};
const int dfs_dx[] = {1, 0, -1, 0};

PII dir[] = {make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)};
/* TC HEADER END */

pair <int, int> human[500005];
int main() {
    int T;
    cin >> T;
    bool m[16][16] = {false};
    for(int _ = 1; _ <= T; _++) {
        int tot = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int d, h, m;
            cin >> d >> h >> m;
            for(int j = 0; j < h; j++) {
                human[tot++] = MP(d, m + j);
            }
        }
        int c = 360;
        long double lo = c * c, hi = 0;
        // v[i] = 360 / m[i]
        // t[i] = d[i] / v[i]
        // v_to = 360 / t[i] = 360 * v[i] / d[i] = 360 ^ 2 / (m[i] * d[i])
        for(int i = 0; i < tot; i++) {
            long double cur = (c - human[i].first) * 1. / 360.;
            cur *= human[i].second;
            cur = 360 / cur;
            // cout << human[i].first << ' ' << human[i].second << ' ' << cur << endl;
            lo = min(lo, cur);
            hi = max(hi, cur);
        }
        int ans = tot;
        // cout << lo << ' ' << hi << endl;
        if(fabs(lo * 2 - hi) < eps || lo * 2 > hi + eps) { // for tot = 2
            ans = 0;
        } else {
            ans = 1;
        }
        /*while(lo + eps < hi) {
            long double mid = (lo + hi) / 2.;
        }*/
        printf("Case #%d: %d\n", _, ans);
    }
    return 0;
}
