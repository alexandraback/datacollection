#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int T;
int E, R, N;
int v[15];
int gain[15][10];
void update(int &x, int y) {
    x = max(x, y);
}

int main() {
    scanf("%d", &T);
    for (int id = 1; id <= T; ++id) {
        scanf("%d%d%d", &E, &R, &N);
        for (int i = 1; i <= N; ++i) scanf("%d", &v[i]);
        memset(gain, 0, sizeof(gain));
        for (int i = 1; i <= N; ++i) {
            for (int p = 0; p <= E; ++p) {
                for (int c = 0; c <= p; ++c) {
                    update(gain[i][min(E, p - c + R)], gain[i - 1][p] + c * v[i]);
                }
            }
        }
        int ans = 0;
        for (int e = 0; e <= E; ++e) ans = max(ans, gain[N][e]);
        printf("Case #%d: %d\n", id, ans);
    }
    return 0;
}
