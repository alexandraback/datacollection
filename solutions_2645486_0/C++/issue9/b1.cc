#include <cstdio>

int e, r, n;
int v[16];
int best;

void f(int i, int e, int c = 0) {
    if (e > ::e) e = ::e;
    if (i >= n) {
        if (c > best) best = c;
        return;
    }
    for (int j = e; j >= 0; --j) {
        int ne = e - j + r;
        if (ne > ::e) ne = ::e;
        f(i + 1, ne, c + j * v[i]);
    }
}

int main(int argc, char const *argv[]) {
    int tc;
    scanf("%d", &tc);
    for (int ti = 1; ti <= tc; ++ti) {
        best = 0;
        scanf("%d%d%d", &e, &r, &n);
        for (int i = 0; i < n; ++i) { scanf("%d", v + i); }
        f(0, e);
        printf("Case #%d: %d\n", ti, best);
    }
    return 0;
}
