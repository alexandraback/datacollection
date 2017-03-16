#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#define y1 _dfdfdfd


const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[3] = {-1, 0, -1};
const int dy[3] = {0, -1, -1};

int n, m, k;
char c[64][64];
bool vis[64][64];

bool ok(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(n - 1, m - 1));
    memset(vis, 0, sizeof(vis));
    vis[n - 1][m - 1] = 1;
    
    int cur = 0;
    while (cur < k) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        c[i][j] = '*';
        cur++;
        for (int o = 0; o < 2; o++) {
            int nx = i + dx[o], ny = j + dy[o];
            if (!ok(nx, ny) || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
}

void solve() {
    if (k == n * m - 1) return;
    int cur = n * m - 4;
    c[0][1] = c[1][0] = c[1][1] = '.';
    int ci = 2;
    while (ci < m && cur - k >= 2) {
        c[0][ci] = c[1][ci] = '.';
        cur -= 2;
        ci++;
    }
    
    if (ci == m && cur - k >= 2) {
        int i = 2, j = 0;
        while (cur - k > 0) {
            c[i][j++] = '.';
            cur--;
            if (j == m) {
                j = 0;
                i++;
            }
        }
        if (j == 1) {
            c[i][j] = '.';
            c[i - 1][m - 1] = '*';
        }
    } else if (cur - k == 1) {
        ci--;
        c[0][ci] = c[1][ci] = '*';
        c[2][0] = c[2][1] = c[2][2] = '.';
    }
}
 
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ":\n";
        
        cin >> n >> m >> k;
        bool rev = n > m;
        if (rev) swap(n, m);
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) c[i][j] = '*';
        c[0][0] = 'c';
        if (n == 1) {
            for (int i = 1; m - i > k; i++) c[0][i] = '.';
        } else {
            if ((k == n * m - 2 || k == n * m - 3 || k == n * m - 5 || k == n * m - 7 || k % 2 == 1 && n == 2) && k != n * m - 1) {
                cout << "Impossible\n";
                continue;
            }
            solve();
        }
        
        if (rev) {
            for (int i = 0; i < 64; i++) for (int j = i; j < 64; j++) swap(c[i][j], c[j][i]);
            swap(n, m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << c[i][j];
            }
            cout << endl;
        }
    }
	return 0;
}
