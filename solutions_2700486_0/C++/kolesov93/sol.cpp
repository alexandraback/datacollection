#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int N = 1500;
const int M = 3333;

int a[M][N];

int gx, gy;
double gans;
int tp;

bool cplus(int x, int y, double prob) {
    a[x][y] = 1;
    if (x == gx && y == gy) { 
        gans += prob;
        return true;
    }
    return false;
}

void rec(int l, int cx, int cy, double prob) {
    if (l == 0) {
        return;
    }
    while (cy > 0) {
        while (cy > 0 && !a[cx][cy - 1] && !a[cx - 1][cy - 1] && !a[cx + 1][cy - 1]) cy--;
        if (cy == 0) {
            bool got = cplus(cx, cy, prob);
            if (!got) rec(l - 1, N, tp, prob);
            a[cx][cy] = 0;
            return;
        }

        int msk = 0;
        if (a[cx - 1][cy - 1]) msk |= 1;
        if (a[cx + 1][cy - 1]) msk |= 2;

        if (msk == 3) {
            bool got = cplus(cx, cy, prob);
            if (!got) rec(l - 1, N, tp, prob);
            a[cx][cy] = 0;
            return;
        } else if (msk == 2) {
            --cx; 
        } else if (msk == 1) {
            ++cx;
        } else {
            rec(l, cx - 1, cy, prob / 2);
            rec(l, cx + 1, cy, prob / 2);
            return;
        }
    }
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int _T;
    scanf("%d\n", &_T);

    for (int __test = 1; __test <= _T; ++__test) {
        int n, x, y;
        cin >> n >> x >> y;

        x += N;
        memset(a, 0, sizeof(a));

        gans = 0;
        gx = x;
        gy = y;
        tp = n;

        rec(n, N, tp, 1.);

        printf("Case #%d: ", __test);
        cout.precision(20);
        cout << fixed;
        cout << gans << endl;

        cerr << "Got " << __test << endl;
    }


    return 0;
}

