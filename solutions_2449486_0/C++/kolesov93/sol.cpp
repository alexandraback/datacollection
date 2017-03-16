#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>
#include <memory.h>

using namespace std;

const int N = 111;
bool a[N][N], b[N][N];
int c[N][N];

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int _T;
    scanf("%d\n", &_T);

    for (int __test = 1; __test <= _T; ++__test) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) cin >> c[i][j];

        bool cool = true;
        for (int level = 100; level; --level) {
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (c[i][j] <= level) a[i][j] = true;

            for (int i = 0; i < n; ++i) {
                bool can = true;
                for (int j = 0; j < m; ++j)
                    if (!a[i][j]) { 
                        can = false;
                        break;
                    }
                if (can) {
                    for (int j = 0; j < m; ++j) {
                        b[i][j] = true;
                    }
                }
            }

            for (int i = 0; i < m; ++i) {
                bool can = true;
                for (int j = 0; j < n; ++j)
                    if (!a[j][i]) { 
                        can = false;
                        break;
                    }
                if (can) {
                    for (int j = 0; j < n; ++j) {
                        b[j][i] = true;
                    }
                }
            }

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (a[i][j] != b[i][j]) cool = false;
            if (!cool) break;
        }
        
        printf("Case #%d: ", __test);
        if (cool) puts("YES");
        else puts("NO");
    }


    return 0;
}

