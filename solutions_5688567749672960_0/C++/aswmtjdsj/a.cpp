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
const double eps = 1e-8;

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

const int maxn = 1000006;
int d[maxn];
int main() {
    int T;
    cin >> T;
    for(int _ = 1; _ <= T; _++) {
        int n;
        cin >> n;
        fill(d, d + n + 1, -1);
        queue <int> Q;
        d[1] = 1;
        Q.push(1);
        while(!Q.empty()) {
            int cur = Q.front();
            // cout << cur << ' ' << d[cur] << endl;
            Q.pop();
            string temp = to_string(cur);
            reverse(temp.begin(), temp.end());
            int biu = stoi(temp);
            if(biu <= n) {
                if(d[biu] == -1 || d[biu] > d[cur] + 1) {
                    d[biu] = d[cur] + 1;
                    Q.push(biu);
                }
            }
            if(cur + 1 <= n && (d[cur+1] == -1 || d[cur+1] > d[cur] + 1)) {
                d[cur+1] = d[cur] + 1;
                Q.push(cur+1);
            }
        }
        printf("Case #%d: %d\n", _, d[n]);
    }
}
