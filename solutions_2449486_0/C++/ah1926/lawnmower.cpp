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

int R, C, Values[MAX_N][MAX_N];
int MaxRow[MAX_N], MaxColumn[MAX_N];
bool Solution;

int main() {
    ifstream in("input.in");
    ofstream out("output.out");
    int Tests; in >> Tests;
    for (int t = 1; t <= Tests; ++t) {
        in >> R >> C;
        for (int i = 1; i <= R; ++i)
            for (int j = 1; j <= C; ++j)
                in >> Values[i][j];
        for (int i = 1; i <= R; ++i) {
            MaxRow[i] = 0;
            for (int j = 1; j <= C; ++j)
                MaxRow[i] = max(MaxRow[i], Values[i][j]);
        }
        for (int j = 1; j <= C; ++j) {
            MaxColumn[j] = 0;
            for (int i = 1; i <= R; ++i)
                MaxColumn[j] = max(MaxColumn[j], Values[i][j]);
        }
        Solution = true;
        for (int i = 1; i <= R; ++i)
            for (int j = 1; j <= C; ++j)
                if (Values[i][j] != MaxRow[i] && Values[i][j] != MaxColumn[j])
                    Solution = false;
        out << "Case #" << t << ": " << (Solution ? "YES" : "NO") << "\n";
    }
    in.close();
    out.close();
    return 0;
}
