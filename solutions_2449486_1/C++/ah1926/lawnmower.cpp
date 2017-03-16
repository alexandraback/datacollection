#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long int64;
typedef vector<int>::iterator it;

const int oo = 0x3f3f3f3f;
const int MAX_N = 105;

int R, C, Map[MAX_N][MAX_N];
bool Solution;

inline int FindMinValue() {
    int minValue = oo;
    for (int r = 1; r <= R; ++r)
        for (int c = 1; c <= C; ++c)
            minValue = min(minValue, Map[r][c]);
    return minValue;
}

inline void EraseRow(const int row) {
    for (int r = row; r < R; ++r)
        for (int c = 1; c <= C; ++c)
            Map[r][c] = Map[r + 1][c];
    --R;
}

inline void EraseColumn(const int column) {
    for (int c = column; c <= C; ++c)
        for (int r = 1; r <= R; ++r)
            Map[r][c] = Map[r][c + 1];
    --C;
}

inline bool ConstantRow(const int row) {
    for (int c = 2; c <= C; ++c)
        if (Map[row][c] != Map[row][1])
            return false;
    return true;
}

inline bool ConstantColumn(const int column) {
    for (int r = 2; r <= R; ++r)
        if (Map[r][column] != Map[1][column])
            return false;
    return true;
}

void Solve() {
    bool step = true;
    while (R > 0 && C > 0 && step) {
        step = false;
        int minValue = FindMinValue();
        for (int r = 1; r <= R; ++r) {
            if (Map[r][1] == minValue && ConstantRow(r)) {
                step = true;
                EraseRow(r);
                --r;
            }
        }
        for (int c = 1; c <= C; ++c) {
            if (Map[1][c] == minValue && ConstantColumn(c)) {
                step = true;
                EraseColumn(c);
                --c;
            }
        }
    }
    Solution = (R == 0 || C == 0);
}

int main() {
    ifstream in("input.in");
    ofstream out("output.out");
    int Tests; in >> Tests;
    for (int t = 1; t <= Tests; ++t) {
        in >> R >> C;
        for (int i = 1; i <= R; ++i)
            for (int j = 1; j <= C; ++j)
                in >> Map[i][j];
        Solve();
        out << "Case #" << t << ": " << (Solution ? "YES" : "NO") << "\n";
    }
    in.close();
    out.close();
    return 0;
}
