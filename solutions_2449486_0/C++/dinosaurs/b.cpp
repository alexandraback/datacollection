#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const int MAXR = 101, MAXC = 101, begin = 100;

int T, R, C, grid[MAXR][MAXC], grass[MAXR][MAXC];
vector<pair<int, pair<int, int> > > sorted;

bool try_cut_row(int row, int col, int goal) {
    for (int i = 0; i < C; i++) {
        if (grid[row][i] > goal) {
            return false;
        }
    }

    for (int i = 0; i < C; i++) {
        grass[row][i] = min(grass[row][i], goal);
    }
    return true;
}

bool try_cut_col(int row, int col, int goal) {
    for (int i = 0; i < R; i++) {
        if (grid[i][col] > goal) {
            return false;
        }
    }

    for (int i = 0; i < R; i++) {
        grass[i][col] = min(grass[i][col], goal);
    }
    return true;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        sorted.clear();

        scanf("%d %d", &R, &C);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%d", &grid[i][j]);
                sorted.push_back(make_pair(-grid[i][j], make_pair(i, j)));
            }
        }

        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                grass[i][j] = begin;
            }
        }

        bool fail = false;
        for (int i = 0; i < sorted.size(); i++) {
            int goal = -sorted[i].first;
            int row = sorted[i].second.first;
            int col = sorted[i].second.second;

            bool success = false;
            if (try_cut_row(row, col, goal)) {
                success = true;
            }
            if (try_cut_col(row, col, goal)) {
                success = true;
            }
            if (!success) {
                fail = true;
                break;
            }
        }

        if (fail) {
            printf("Case #%d: NO\n", t);
        } else {
            printf("Case #%d: YES\n", t);
        }
    }

    return 0;
}
