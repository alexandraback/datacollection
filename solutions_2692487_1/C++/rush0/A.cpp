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

int T, N, A, v[105];

int main() {
    scanf("%d", &T);
    for (int id = 1; id <= T; ++id) {
        scanf("%d%d", &A, &N);
        FOR(i, N) scanf("%d", &v[i]);
        sort(v, v + N);

        const int oo = 0x3F3F3F3F;
        int ans = +oo;
        for (int i = N; i >= 0; --i) {
            int B = A;
            int cnt = N - i;
            for (int j = 0; j < i; ++j) {
                if (B <= v[j] && B - 1 <= 0) {
                    cnt = +oo;
                    break;
                }
                while (B <= v[j]) {
                    B += B - 1;
                    cnt += 1;
                }
                B += v[j];
            }
            ans = min(ans, cnt);
        }
        printf("Case #%d: %d\n", id, ans);
    }
    return 0;
}
