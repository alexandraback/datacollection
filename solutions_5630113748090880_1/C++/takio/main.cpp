#include <cstdio>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define LL long long
#define pii pair <int, int>
#define piii pair <pii, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
using namespace std;

const int N = 2505;
int c[N];

int main () {
    freopen ("B-large.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int T, cas = 1;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n;
        memset (c, 0, sizeof c);
        for (int i = 1; i <= 2 * n - 1; i++) {
            for (int j = 1; j <= n; j++) {
                scanf ("%d", &x);
                c[x]++;
            }
        }
        printf ("Case #%d:", cas++);
        for (int i = 1; i <= 2500; i++) if (c[i] & 1) printf (" %d", i);
        printf ("\n");
    }
}
