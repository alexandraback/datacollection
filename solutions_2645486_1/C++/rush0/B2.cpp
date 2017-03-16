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
int v[1000 * 10000 + 5];
int gain[15][10];
void update(int &x, int y) {
    x = max(x, y);
}

int main() {
    scanf("%d", &T);
    for (int id = 1; id <= T; ++id) {
        scanf("%d%d%d", &E, &R, &N);
        for (int i = 1; i <= N; ++i) scanf("%d", &v[i]);
        LL sum = 0;
        for (int i = 1; i <= N; ++i) sum += v[i];
        LL maxv = *max_element(v + 1, v + N + 1);
        LL ans = min(R, E) * sum + (E - min(R, E)) * maxv;
        printf("Case #%d: %lld\n", id, ans);
    }
    return 0;
}
