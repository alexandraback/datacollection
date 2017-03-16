#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

int H, W, D, D2;
int my_r, my_c;

char map[31][31];
set<pair<int, int> > sol;

int dist2(int r1, int c1, int r2, int c2) {
    int dr = abs(r1 - r2);
    int dc = abs(c1 - c2);
    return dr * dr + dc * dc;
}

bool test_x(int x, int my_x, int max_x) {
    //printf("test %d %d %d\n", x, my_x, max_x);
    int dx = abs(x - my_x);
    int vx = dx == 0 ? 0 : (x - my_x) / dx;

    //printf(" dx=%d, vx=%d\n", dx, vx);

    x = my_x;
    for (int i = 0; i < dx; ++i) {
        x += vx;
        if (x == 0) {
            x = 1;
            vx *= -1;
        }
        if (x == max_x - 1) {
            x = max_x - 2;
            vx *= -1;
        }
    }

    return x == my_x;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool test(int r, int c) {
    // printf("test %d %d\n", r, c);
    return test_x(r, my_r, H) & test_x(c, my_c, W);
}

int run() {
    cin >> H >> W >> D;
    D2 = D * D;
    //cout << H << W << D << endl;
    char tmp[31];

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> map[i][j];

            if (map[i][j] == 'X') {
                my_r = i;
                my_c = j;
            }
        }
    }

    bool ok;
    sol.clear();
    for (int r = my_r - D, rN = my_r + D; r <= rN; ++r)
        for (int c = my_c - D, cN = my_c + D; c <= cN; ++c) {
            if (0 < r && r < H - 1 && 0 < c && c < W - 1) continue;
            if (dist2(r , c, my_r, my_c) > D2) continue;
            ok = test(r , c);
            if (ok) {
                int dr = r - my_r;
                int dc = c - my_c;
                int ratio = gcd(abs(dr), abs(dc));
                sol.insert(make_pair(dr / ratio, dc / ratio));
            }
        }

    return sol.size();
}

int main() {
    int caseN;
    cin >> caseN;

    for (int t = 0; t < caseN; ++t) {
        int num = run();
        printf("Case #%d: %d\n", t + 1, num);
    }

    return 0;
}

