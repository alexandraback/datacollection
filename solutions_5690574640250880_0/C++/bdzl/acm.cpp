#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int max_n = 5;

const int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

int a[max_n][max_n];
int b[max_n][max_n];
int n, m, k;
int used[max_n][max_n];

void dfs(int i, int j)
{
    used[i][j] = 1;
    if (a[i][j] == 0)
        for (int t = 0; t < 8; ++t) {
            int ni = i + dx[t];
            int nj = j + dy[t];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !used[ni][nj] && !b[ni][nj])
                dfs(ni, nj);
        }
}

bool check() 
{
    for (int i = 0; i < n; ++i)     
        for (int j = 0; j < m; ++j) {
            if (b[i][j]) continue;
            a[i][j] = 0;
            for (int t = 0; t < 8; ++t) {
                int ni = i + dx[t];
                int nj = j + dy[t];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) 
                    a[i][j] += b[ni][nj];
            }
        }
    
    if (n * m - 1 == k) return true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            used[i][j] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!b[i][j] && a[i][j] == 0) {
                dfs(i, j);
                bool good = true;
                for (int ni = 0; ni < n; ++ni)
                    for (int nj = 0; nj < m; ++nj) 
                        if (!b[ni][nj] && !used[ni][nj])
                            good = false;
                return good;
            }
    return false;
}

bool calc(int i, int j, int x) 
{
    if (x == k) {
        return check();
    }
    if (i == n) {
        return false;
    }
    if (j == m) {
        return calc(i + 1, 0, x);
    }
    b[i][j] = 1;
    if (calc(i, j + 1, x + 1)) return true;
    b[i][j] = 0;
    return calc(i, j + 1, x);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; ++test) {
        scanf("%d%d%d", &n, &m, &k);
        printf("Case #%d:\n", test);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                b[i][j] = 0;
        if (!calc(0, 0, 0)) {
            printf("Impossible\n");
        } else {
            bool out = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j)
                    if (b[i][j])
                        printf("*");
                    else {
                        if (a[i][j] == 0) {
                            if (!out) {
                                out = true;
                                printf("c");
                            } else {
                                printf(".");
                            }
                        } else {
                            if (n * m - 1 == k) {
                                printf("c");
                            } else {
                                printf(".");
                            }
                        }
                    }
                printf("\n");
            }
        }
    }
        

    return 0;
}

