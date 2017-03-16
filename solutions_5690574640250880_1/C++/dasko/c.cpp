#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <cassert>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

vector<string> rot(const vector<string> &s) {
    int n = SZ(s), m = (n == 0 ? 0 : SZ(s[0]));
    vector<string> res(m);
    REP (i, m) {
        res[i] = string(n, '.');
        REP (j, n) {
            res[i][j] = s[j][i];
        }
    }
    return res;
}

vector<string> make(int n, int m) {
    vector<string> res(n);
    REP (i, n) {
        res[i] = string(m, '*');
    }
    return res;
}

vector<string> solve1(int n, int m, int K) {
    if (n == 1) {
        vector<string> res = make(n, m);
        res[0][0] = 'c';
        REP (i, K - 1) {
            res[0][1 + i] = '.';
        }
        return res;
    } else {
        if (K == 2 || K == 3 || K == 5 || K == 7) {
            return vector<string>();
        }
        vector<string> res = make(n, m);
        res[0][0] = 'c';
        if (K == 1) {
            return res;
        }
        if (n == 2 && K % 2 == 1) {
            return vector<string>();
        }
        res[0][1] = res[1][0] = res[1][1] = '.';
        int Z = 4;
        if (n > 2) {
            if (K > Z) {
                res[2][0] = res[2][1] = '.';
                Z += 2;
            }
        }
        if (K > Z) {
            res[0][2] = res[1][2] = '.';
            Z += 2;
        }
        if (n > 2) {
            for (int i = 3; i < n && K - Z >= 2; ++i) {
                res[i][0] = res[i][1] = '.';
                Z += 2;
            }
        }
        for (int j = 3; j < m && K - Z >= 2; ++j) {
            res[0][j] = res[1][j] = '.';
            Z += 2;
        }
        for (int i = 2; i < n && K > Z; ++i) {
            for (int j = 2; j < m && K > Z; ++j) {
                res[i][j] = '.';
                ++Z;
            }
        }
        return res;
    }
}

vector<string> solve(int n, int m, int K) {
    if (n > m) {
        return rot(solve1(m, n, K));
    }
    return solve1(n, m, K);
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n, m, K; scanf("%d%d%d", &n, &m, &K);
        K = n * m - K;
        vector<string> res = solve(n, m, K);
        printf("Case #%d:\n", t);
        if (res.empty()) {
            puts("Impossible");
        } else {
            REP (i, n) {
                printf("%s\n", res[i].c_str());
            }
        }
    }
    return 0;
}
