#include <algorithm>
#include <cstdio>
#include <cmath>

int v[20];
int e;
int r;
int n;

int f[20][10];
int used[20][10];

int getMax()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= e; ++j) {
            used[i][j] = 0;
            f[i][j] = 0;
        }
    }
    for (int i = 0; i <= e; ++i) {
        f[0][i] = (e - i) * v[0];
        used[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= e; ++j) {
            if (used[i - 1][j]) {
                int tot = std::min(e, j + r);
                for (int k = 0; k <= tot; ++k) {
                    f[i][k] = std::max(f[i][k], f[i - 1][j] + v[i] * (tot - k));
                    used[i][k] = 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <=e; ++i) {
        ans = std::max(f[n - 1][i], ans);
    }
    return ans;
}

int main()
{
    FILE * fd = fopen("input", "r");
    int testnum = 0;
    fscanf(fd, "%d ", &testnum);
    for (int test = 1; test <= testnum; ++test)
    {
        fscanf(fd, "%d %d %d ", &e, &r, &n);
        for (int i = 0; i < n; ++i) {
            fscanf(fd, "%d", &v[i]);
        }
        fprintf(stdout, "Case #%d: %d\n", test, getMax());
    }
}

