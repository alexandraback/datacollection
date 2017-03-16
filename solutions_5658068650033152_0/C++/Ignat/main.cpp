#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define PRINT(x)
#define PRINT_CONT(x)
#define PRINT_MSG(x)
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
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

const int MAX = 10;
bool table[MAX][MAX];
bool visited[MAX][MAX];

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        cerr << tt << endl;

        int n, m, k;
        cin >> n >> m >> k;

        if (n == 1 || m == 1) {
            cout << "Case #" << tt << ": " << k << "\n";
            continue;
        }

        int res = n * m;

        vector<pair<int, int>> queue(20);

        for (int mask = 0; mask < (1 << n * m); ++mask) {
            memset(table, 0, sizeof(table));
            memset(visited, 0, sizeof(visited));
            int w = 0;
            for (int j = 0; j < (n * m); ++j) {
                if (((1 << j) & mask) == 0) continue;
                w += 1;
                table[j / m][j % m] = true;
            }

            int s = 0, t = 0;
            for (int i = 0; i < n; ++i) {
                if (!table[i][0] && !visited[i][0]) {
                    queue[s++] = make_pair(i, 0);
                    visited[i][0] = true;
                }
                if (!table[i][m - 1] && !visited[i][m - 1]) {
                    queue[s++] = make_pair(i, m - 1);
                    visited[i][m - 1] = true;
                }
            }
            for (int i = 0; i < m; ++i) {
                if (!table[0][i] && !visited[0][i]) {
                    queue[s++] = make_pair(0, i);
                    visited[0][i] = true;
                }
            }
            for (int i = 0; i < m; ++i) {
                if (!table[n - 1][i] && !visited[n - 1][i]) {
                    queue[s++] = make_pair(n - 1, i);
                    visited[n - 1][i] = true;
                }
            }

            int c = 0;
            while (s != t) {
                auto p = queue[t++];
                int x = p.first, y = p.second;
                c += 1;
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >=n || ny <0 || ny >= m || visited[nx][ny] || table[nx][ny]) {
                        continue;
                    }

                    visited[nx][ny] = true;
                    queue[s++] = make_pair(nx, ny);
                }
            }

            //cerr << w << endl;
            if (n * m - c >= k) {
                res = min(res, w);
            }

        }

        cout << "Case #" << tt << ": " << res << "\n";
    }
    
    return 0;
}
