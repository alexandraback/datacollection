#include <cstdio>
#include <algorithm>

using namespace std;

int T, a, b, k;

int solve() {
    int res = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            int c = i & j;
            if (c < k)
                res++;
        }
    }
    return res;
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &a, &b, &k);
        printf("Case #%d: %d\n", t, solve());
    }

    return 0;

}
