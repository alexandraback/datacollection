#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int n, m, st, need, ok = 0;

bool good(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int i, int j, int amo, vector<vector<bool> > used, vector<vector<bool> > ws) {
	//cout << i << " " << j << endl;
    if (ok) return;
	ws[i][j] = 1;
    for (int dx = -1; dx < 2; dx++) {
        for (int dy = -1; dy < 2; dy++) {
            if (good(i + dx, j + dy) && !used[i + dx][j + dy]) {
                used[i + dx][j + dy] = 1;
                amo++;
            }
        }
    }
    if (amo > need) {
        return;
    } else if (amo == need) {
        ok = 1;
        for (int ci = 0; ci < n; ci++) {
            for (int cj = 0; cj < m; cj++) {
                if (used[ci][cj] && ci == i && cj == j) {
                    printf("c");
                } else if (used[ci][cj]) {
                    printf(".");
                } else {
                    printf("*");
                }
            }
            puts("");
        }
    }
    for (int dx = -1; dx < 2; dx++) {
        for (int dy = -1; dy < 2; dy++) {
            if (good(i + dx, j + dy) && (dx != 0 || dy != 0) && !ws[i + dx][j + dy]) {
                dfs(i + dx, j + dy, amo, used, ws);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test_amo; cin >> test_amo;
    for (int test_num = 1; test_num <= test_amo; test_num++) {
        cin >> n >> m >> st;
        need = n * m - st, ok = 0;
        printf("Case #%d:\n", test_num);
        vector<vector<bool> > used(n, vector<bool>(m, false)), ws(n, vector<bool>(m, false));
		if (need == 1) {
			ok = 1;
			for (int ci = 0; ci < n; ci++) {
				for (int cj = 0; cj < m; cj++) {
					if (ci == 0 && cj == 0) printf("c");
					else
						printf("*");
				}
				puts("");
			}
		}

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++)
				dfs(i, j, 0, used, ws);
		}

        if (!ok) {
            puts("Impossible");
        }
    }
    return 0;
}
