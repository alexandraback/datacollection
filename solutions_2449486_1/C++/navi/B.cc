#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
int T, n, m;
int h[100][100];
int a[100][100];

void cut(int r, int c, int size, int dr, int dc, int height) {
    for (int i = 0; i < size; ++i) {
        int nr = (r + dr * i) % n;
        int nc = (c + dc * i) % m;
        if (h[nr][nc] > height) {
            return;
        }
    }
    for (int i = 0; i < size; ++i) {
        int nr = (r + dr * i) % n;
        int nc = (c + dc * i) % m;
        //a[nr][nc] = min(a[nr][nc], h);
        a[nr][nc] = height;
    }
}

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        vector<pii> v[101];
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &h[i][j]);
                v[h[i][j]].push_back(make_pair(i, j));
                a[i][j] = 100;
            }
        }
        for (int i = 100; i >= 1; --i) {
            for (vector<pii>::const_iterator j = v[i].begin(); j != v[i].end(); ++j) {
                int r = j->first;
                int c = j->second;
                if (a[r][c] > h[r][c]) {
                    cut(r, c, m, 0, 1, h[r][c]);
                    cut(r, c, n, 1, 0, h[r][c]);
                }
            }
        }
        bool res = true;
        for (int i = 0; i < n && res; ++i) {
            for (int j = 0; j < m && res; ++j) {
                res = a[i][j] == h[i][j];
            }
        }
        printf("Case #%d: %s\n", caseNum, res ? "YES" : "NO");
    }
    return 0;
}
