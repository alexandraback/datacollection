#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

void printMatrix(int a[21][21], int n, int m) {
    cout << endl;
    for (int i = 0; i < n; ++i, cout << endl)
        for (int j = 0; j < m; ++j)
            cerr << a[i][j] << " ";
}

void bfs(int a[21][21], int n, int m, int sl, int sc) {
    if (a[sl][sc])
        return;

    queue< pair<int, int> > q;
    q.push(make_pair(sl, sc));
    a[sl][sc] = 2;

    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        int l = x.first, c = x.second;

        for (int dir = 0; dir < 4; ++dir) {
            int nl = l + dx[dir];
            int nc = c + dy[dir];

            if (nl >= 0 && nc >= 0 && nl < n && nc < m && a[nl][nc] == 0) {
                a[nl][nc] = 2;
                q.push(make_pair(nl, nc));
                //cerr << "(" << nl << " " << nc << ") ";
            }
        }
    }
    //printMatrix(a, n, m);
}

int a[21][21];
bool check(int n, int m, int k, int mask) {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 21; ++i)
        if (mask & (1 << i)) {
            int l = i / m;
            int c = i % m;
            a[l][c] = 1;
        }
        //printMatrix(a, n, m);

//cerr << "c1" << endl;
    for (int i = 0; i < n; ++i) {
        bfs(a, n, m, i, 0);
        bfs(a, n, m, i, m - 1);
    }

//cerr << "c2" << endl;
    for (int i = 0; i < m; ++i) {
        bfs(a, n, m, 0, i);
        bfs(a, n, m, n - 1, i);
    }
        //printMatrix(a, n, m);

//cerr << "c3" << endl;
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == 0 || a[i][j] == 1)
                count++;

    return count >= k;
}

bool iterate(int N, int M, int K, int k) {
    int s = (1 << k) - 1;
    //cerr << "Checking len: " << k;

    int n = N*M;
    while (!(s & 1 << n))
    {
        if (check(N, M, K, s))
            return true;

        int lo = s & ~(s - 1);       // lowest one bit
        int lz = (s + lo) & ~s;      // lowest zero bit above lo
        s |= lz;                     // add lz to the set
        s &= ~(lz - 1);              // reset bits below lz
        s |= (lz / lo / 2) - 1;      // put back right number of bits at end
    }

    return false;
}

int solve(int n, int m, int k) {
    for (int i = 1; i < k; ++i)
        if (iterate(n, m, k, i))
            return i;

    return k;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << "Case #" << t << ": " << solve(n, m, k) << endl;
    }

    return 0;
}
