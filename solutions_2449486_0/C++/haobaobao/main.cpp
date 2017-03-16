#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t;
int n, m;
int w[100], h[100];
int grass[100][100];

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    scanf("%d", &t);
    for (int ti = 1; ti <= t; ++ti) {
        memset(w, 0, sizeof(w));
        memset(h, 0, sizeof(h));
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &grass[i][j]);
                if (grass[i][j] > w[i]) {
                    w[i] = grass[i][j];
                }
                if (grass[i][j] > h[j]) {
                    h[j] = grass[i][j];
                }
            }
        }

        bool ans = true;
        for (int i = 0; i < n && ans; ++i) {
            for (int j = 0; j < m && ans; ++j) {
                if (grass[i][j] < w[i] && grass[i][j] < h[j]) {
                    ans = false;
                }
            }
        }
        printf("Case #%d: ", ti);
        if (ans) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }


    return 0;
}

