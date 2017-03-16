#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
typedef pair<int, int> PII;

#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define FILLCHAR(a, x) memset(a, x, sizeof(a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()

int board[50][50];
int visited[50][50];
int n, m, k;

void fill(int x, int y) {
    if (board[x][y]) return;
    if (visited[x][y]) return;
    visited[x][y] = 1;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) + abs(j) == 1) {
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    // cout << " go to " << nx << " " << ny << endl;
                    fill(nx, ny);
                }
            }
        }
    }
}
int count() {
    FILLCHAR(visited, 0);

    for (int i = 0; i < n; i++) {
        fill(i, 0);
        fill(i, m - 1);
    }

    for (int i = 0; i < m; i++) {
        fill(0, i);
        fill(n - 1, i);
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0) ret++;
        }
    }

    return ret;
}
int run() {
    cin >> n >> m >> k;
    FILLCHAR(board, 0);
    int ret = INT_MAX;
    REP(i, (1 << (n * m))) {
        int stone = 0;
        REP(j, n * m) {
            int x = j / m;
            int y = j % m;
            board[x][y] = (i & (1 << j)) != 0;
            if (board[x][y]) stone++;
        }

        if (count() >= k) {
            ret = min(ret, stone);
        }
    }

    return ret;
}

int main() {
    int t;
    cin >> t;
    REP(i,t) {
        int ret = run();
        cout << "Case #" << i + 1 << ": " << ret << endl;
    }
}

