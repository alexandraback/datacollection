#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 128

using namespace std;

int a[N];
int n;
int T;
int A;

void solve(int test) {
    int best_cnt = n;
    sort(a + 1, a + n + 1);
    long long S = (long long) A;

    int cnt = 0,i;
    for (i = 1; i <= n; ++i) {
        bool del = 0;
        while (S <= (long long) a[i]) {
            ++cnt;
            if (S == 1) {
                del = 1;
                break;
            }
            S += S - 1;
        }
        if (del == 0)
            S += (long long) a[i];
        //printf ("%lld\n", S);
        best_cnt = min(best_cnt, cnt + (n - i));
    }
    printf ("Case #%d: %d\n", test, best_cnt);
}
int main() {
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    scanf ("%d\n", &T);
    for (int test = 1; test <= T; ++test) {
        scanf ("%d %d\n", &A, &n);
        for (int i = 1; i <= n; ++i)
            scanf ("%d ", &a[i]);
        solve(test);
    }

    return 0;
}
