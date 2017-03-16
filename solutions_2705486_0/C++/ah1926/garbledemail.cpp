#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>

using namespace std;

const int MAX_LENGTH = 15;
const int MAX_N = 4005;
const int MAX_D = 522000;
const int MIN_ABS = 5;
const int oo = 0x3f3f3f3f;

int D, Length[MAX_D], N, DP[MAX_N][2 * MIN_ABS], Solution;
char String[MAX_N], Dictionary[MAX_D][MAX_LENGTH];

inline int Abs(const int value) {
    if (value < 0)
        return -value;
    return value;
}

void Solve() {
    memset(DP, oo, sizeof(DP));
    DP[0][5] = 0;
    for (int i = 0; i < N; ++i) {
        for (int last = 0; last <= MIN_ABS; ++last) {
            for (int w = 0; w < D; ++w) {
                if (i + Length[w] > N)
                    continue;
                int cost = 0, newLast = last + Length[w];
                int prevChange = i - last;
                bool valid = true;
                for (int p = 0; p < Length[w] && valid; ++p) {
                    if (Dictionary[w][p] != String[i + 1 + p]) {
                        if (i + 1 + p - prevChange < MIN_ABS)
                            valid = false;
                        ++cost;
                        newLast = Length[w] - p - 1;
                        prevChange = i + 1 + p;
                    }
                }
                newLast = min(newLast, MIN_ABS);
                if (valid)
                    DP[i + Length[w]][newLast] = min(DP[i + Length[w]][newLast], DP[i][last] + cost);
            }
        }
    }
    Solution = oo;
    for (int i = 0; i <= MIN_ABS; ++i)
        Solution = min(Solution, DP[N][i]);
}

void ReadDictionary() {
    assert(freopen("dictionary.txt", "r", stdin));
    while (scanf("\n%s", Dictionary[D]) == 1) {
        Length[D] = strlen(Dictionary[D]);
        ++D;
    }
    fclose(stdin);
}

void Read() {
    assert(scanf("\n%s", String + 1) == 1);
    N = strlen(String + 1);
}

void Print(const int test) {
    printf("Case #%d: %d\n", test, Solution);
}

void Clear() {
    memset(String, 0, sizeof(String));
    memset(DP, 0, sizeof(DP));
}

int main() {
    ReadDictionary();
    assert(freopen("input.in", "r", stdin));
    assert(freopen("output.out", "w", stdout));
    int tests; assert(scanf("%d", &tests) == 1);
    for (int t = 1; t <= tests; ++t) {
        Read();
        Solve();
        Print(t);
        Clear();
    }
    return 0;
}
