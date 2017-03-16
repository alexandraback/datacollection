#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <vector>
#include <map>

using namespace std;

const int32_t N = 20;
const int32_t M = 40;

vector<int32_t> S[1<<N];
bool R[1<<N];
map<int32_t, int32_t> To[N + 1];
int32_t From[N];
int32_t m, n;

bool Reach(int32_t x, int32_t y) {
    map<int32_t, int32_t> tmp = To[n];
    for (int32_t i = 0; i < n; i++) {
        if ((1 << i) & x) {
            for (map<int32_t, int32_t>::iterator it = To[i].begin(); it != To[i].end(); ++it) {
                tmp[it->first] += it->second;
            }
            tmp[From[i]]--;
        }
    }
    return tmp[From[y]] > 0;
}
bool Better(const vector<int32_t> &a, const vector<int32_t> &b) {
    if (b.size() == 0) return true;
    for (int32_t i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) return false;
    }
    return false;
}
int32_t main() {
    int32_t cas = 0;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic++) {
        scanf("%d%d", &m, &n);
        for (int32_t i = 0; i <= n; i++) {
            To[i].clear();
        }
        for (int32_t i = 0; i < (1 << n); i++) {
            S[i].clear();
        }
        memset(R, 0, (1 << n) * sizeof(R[0]));
        for (int32_t i = 0; i < m; i++) {
            int32_t t = 0;
            scanf("%d", &t);
            To[n][t]++;
        }
        for (int32_t i = 0; i < n; i++) {
            int32_t sz = 0;
            scanf("%d%d", &From[i], &sz);
            for (int32_t j = 0; j < sz; j++) {
                int32_t t = 0;
                scanf("%d", &t);
                To[i][t]++;
            }
        }
        R[0] = true;
        for (int32_t i = 1; i < (1 << n); i++) {
            for (int32_t j = 0; j < n; j++) {
                if (((1 << j) & i) && R[i ^ (1 << j)] && Reach(i ^ (1 << j), j)) {
                    //printf("i = %d\n", i);
                    R[i] = true;
                    vector<int32_t> tmp = S[i ^ (1 << j)];
                    tmp.push_back(j);
                    if (Better(tmp, S[i])) {
                        S[i] = tmp;
                    }
                }
            }
        }
        printf("Case #%d: ", ic);
        if (!R[(1 << n) - 1]) {
            printf("IMPOSSIBLE\n");
        } else {
            for (int32_t i = 0; i < n; i++) {
                printf("%d %c", S[(1 << n) - 1][i] + 1, i == n - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
