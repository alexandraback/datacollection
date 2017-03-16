#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1010;

int T, N, M, m[MAXN][MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    int i, j, k, test = 1;
    cin >> T;

    for ( ; T--; ) {
        cout << "Case #" << test++ << ": ";
        cin >> N >> M;
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                cin >> m[i][j];
            }
        }

        bool ok = true;

        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                int now = m[i][j], max_prev_up = INT_MIN, max_prev_left = INT_MIN, max_next_down = INT_MIN, max_next_right = INT_MIN;
                for (k = 0; k < N; k++) {
                    if(k < i) max_prev_up = max(max_prev_up, m[k][j]);
                    if(k > i) max_next_down = max(max_next_down, m[k][j]);
                }
                for (k = 0; k < M; k++) {
                    if(k < j) max_prev_left = max(max_prev_left, m[i][k]);
                    if(k > j) max_next_right = max(max_next_right, m[i][k]);
                }
                if((max_prev_up > m[i][j] || max_next_down > m[i][j]) && (max_prev_left > m[i][j] || max_next_right > m[i][j])) {
                    ok = false; goto end;
                }
            }
        }
        end:;
        if(ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
