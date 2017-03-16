#include <cstdio>

int T;
int n, a[1024], b[1024];
int nr[1024];
void solve(int test) {
    int i, j;
    for (i = 1;i <= n; ++i)
        nr[i] = 0;

    int ok = 0;
    int S = 0;
    int sol = 0;
    while (1) {
        ok = 1;
        int mx = 0, pz = 0;
        for (i = 1; i <= n; ++i)
            if (nr[i] == 1) {
                if (b[i] <= S && 1 >= mx) {
                    mx = 1;
                    pz = i;
                }
            }
            else if (nr[i] == 0) {
                if (b[i] <= S && 2 > mx) {
                    mx = 2;
                    pz = i;
                }
                else if (a[i] <= S && 1 >= mx) {
                    if (1 == mx && nr[pz] == 0 && b[i] > b[pz]) {
                        mx = 1;
                        pz = i;
                    }
                    if (mx == 0)
                        mx = 1, pz = i;
                }
            }
        
        if (pz == 0)
            break;
        
        S += mx;
        nr[pz] += mx;
        ++sol;
        //fprintf (stderr, "%d %d, mx %d\n", a[pz], b[pz], mx);
    }

    printf ("Case #%d: ", test);
    for (i = 1; i <= n; ++i)
        if (nr[i] != 2) {
            printf ("Too Bad\n");
            return;
        }
    printf ("%d\n", sol);
}

int main() {
    freopen ("b.in", "r", stdin);
    freopen ("b.out", "w", stdout);
    scanf ("%d\n", &T);
    for (int test = 1; test <= T; ++test) {
        scanf ("%d\n", &n);
        int i;
        for (i = 1; i <= n; ++i)
            scanf ("%d %d\n", &a[i], &b[i]);
        solve(test);
    }
}
