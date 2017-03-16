//
//  main.cpp
//  C
//
//  Created by fLOyd on 5/3/14.
//  Copyright (c) 2014 fLOyd. All rights reserved.
//

#include <iostream>

const int MAXN = 55;

int T, N, M;
int zip[MAXN];
int ans[MAXN], now[MAXN];
int g[MAXN][MAXN];

int min_idx;
int root;

int min(int num[], int count) {
    int ans = -1;
    min_idx = -1;
    for (int i = 0; i < count; ++i) {
        if (ans == -1 || num[i] < ans) {
            ans = num[i];
            min_idx = i;
        }
    }
    return ans;
}


bool expanded[MAXN];
int father[MAXN];

void solve(int f, int idx) {
    if (idx == N) {
        for (int i = 0; i < N; ++i) {
            if (ans[i] == -1 || now[i] < ans[i]) {
                for (int j = 0; j < N; ++j) {
                    ans[j] = now[j];
                }
                return;
            } else if (now[i] > ans[i]) { return; }
        }
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (!expanded[i] && g[f][i] == 1) {
            now[idx] = zip[i];
            expanded[i] = true;
            father[i] = f;
            solve(i, idx + 1);
            expanded[i] = false;
            father[i] = -1;
        }
    }
    if (father[f] != -1) {
        solve(father[f], idx);
    }

}

int main(int argc, const char * argv[]) {
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        for (int i = 0; i < MAXN; ++i) { ans[i] = -1; }
        for (int i = 0; i < MAXN; ++i) { father[i] = -1; }
        memset(g, 0, sizeof(g));
        memset(expanded, false, sizeof(expanded));
        std::cin >> N >> M;
        for (int i = 0; i < N; ++i) { std::cin >> zip[i]; }
        for (int i = 0; i < M; ++i) {
            int x, y;
            std::cin >> x >> y;
            x--, y--;
            g[x][y] = 1;
            g[y][x] = 1;
        }

        ans[0] = now[0] = min(zip, N);
        root = min_idx;
        expanded[root] = true;

        solve(root, 1);
        std::cout << "Case #" << t + 1 << ": ";
        for (int i = 0; i < N; ++i) {
            std::cout << ans[i];
        }
        std::cout << std::endl;

    }
    return 0;
}
