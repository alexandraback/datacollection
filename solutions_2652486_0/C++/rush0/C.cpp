#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long LL;

#define TWO(x) (1 << (x))
int T;
int R, N, M, K;
int guess[100 + 5][7 + 5];
set<int> cand[64 + 5];
string cand2[64 + 5];
void make() {
    R = 100, N = 3, M = 5, K = 7;
    int t[3];
    for (t[0] = 2; t[0] <= M; ++t[0]) {
        for (t[1] = 2; t[1] <= M; ++t[1]) {
            for (t[2] = 2; t[2] <= M; ++t[2]) {
                int k = (t[0] - 2) * 16 + (t[1] - 2) * 4 + (t[2] - 2);
                cand2[k] = string() + char('0' + t[0]) + char('0' + t[1]) + char('0' + t[2]);
                cand[k].clear();
                FOR(i, TWO(N)) {
                    int p = 1;
                    FOR(j, N) if (i & TWO(j)) p *= t[j];
                    cand[k].insert(p);
                }
            }
        }
    }
}

int main() {
    make();
    srand(time(NULL));
    scanf("%d", &T);
    for (int id = 1; id <= T; ++id) {
        scanf("%d%d%d%d", &R, &N, &M, &K);
        FOR(i, R) FOR(j, K) scanf("%d", &guess[i][j]);
        printf("Case #%d:\n", id);
        FOR(i, R) {
            vector<string> ans;
            FOR(k, 64) {
                bool ok = true;
                FOR(j, K) if (cand[k].count(guess[i][j]) == 0)  { ok = false; break; }
                if (ok) ans.push_back(cand2[k]);
            }
            int r = rand() % SZ(ans);
            printf("%s\n", ans[r].c_str());
        }
    }
    return 0;
}
