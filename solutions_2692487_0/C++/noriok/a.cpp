#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

typedef vector<int> vi;

int g_ans = 0;

void calc_1(int a, int opcnt, int p, const vi& v) {
    if (p == v.size()) {
        g_ans = min(g_ans, opcnt);
        return;
    }

    int x = v[p];
    if (x < a) {
        calc_1(a+x, opcnt, p+1, v);
    }
    else {
        // rempve
        calc_1(a, opcnt+1, p+1, v);


        // add (a-1)
        if (a > 1) {
            calc_1(a+a-1, opcnt+1, p, v);
        }
    }
}

int calc(int a, vi& v) {
    g_ans = INT_MAX;

    sort(v.begin(), v.end());
    calc_1(a, 0, 0, v);

    return g_ans;
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        int a, n;
        scanf("%d %d", &a, &n);

        vi v(n);
        For(i, n) scanf("%d", &v[i]);

        printf("Case #%d: %d\n", cc+1, calc(a, v));
    }
}
