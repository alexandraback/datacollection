#include <cassert>
#include <cstdio>

#include <algorithm>
#include <functional>
using namespace std;

const int MAX_N = 128;

int N, S, p;
int v[MAX_N];

int get_normal_score(int n) {
    return n / 3 + (n % 3 > 0 ? 1 : 0);
}

int get_surprising_score(int n) {
    if (n == 0) return 0;
    return n / 3 + (n % 3 == 2 ? 2 : 1);
}

int main() {
    assert(freopen("B.in", "r", stdin));
    assert(freopen("B.out", "w", stdout));

    int T; assert(scanf("%d", &T) == 1);
    for (int test = 1; test <= T; ++test) {
        assert(scanf("%d %d %d", &N, &S, &p) == 3);
        for (int i = 1; i <= N; ++i)
            assert(scanf("%d", &v[i]) == 1);
        sort(v + 1, v + N + 1, greater<int>());

        int sol = 0;
        for (int i = 1; i <= N; ++i) {
            int normal_score = get_normal_score(v[i]);
            if (normal_score >= p) {
                ++sol;
                continue;
            }

            int surprising_score = get_surprising_score(v[i]);
            if (surprising_score >= p && S > 0) {
                ++sol;
                --S;
            }
        }

        printf("Case #%d: %d\n", test, sol);
    }
}
