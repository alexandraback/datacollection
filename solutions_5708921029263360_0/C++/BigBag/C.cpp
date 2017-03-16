#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int max_n = 11, inf = 1111111111;

int t, a, b, c, k;
int f[3][max_n][max_n];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    freopen("input.txt", "r", stdin);
    ofstream O("C-small.out");
    cin >> t;
    for (int test = 1; test <= t; ++test) {
        cin >> a >> b >> c >> k;
        int all = a * b * c, ans = 0, res;
        for (int mask = (1 << all) - 1; mask > 0; --mask) {
            if (ans == all) {
                break;
            }
            int num = 0, cnt = 0;
            for (int i = 0; i < a * b * c; ++i) {
                if (get_bit(mask, i)) {
                    ++cnt;
                }
            }
            if (cnt <= ans) {
                continue;
            }
            for (int q = 1; q <= c; ++q) {
                for (int w = 1; w <= c; ++w) {
                    f[0][q][w] = 0;
                    f[1][q][w] = 0;
                    f[2][q][w] = 0;
                }
            }
            for (int q = 1; q <= a; ++q) {
                for (int w = 1; w <= b; ++w) {
                    for (int e = 1; e <= c; ++e) {
                        if (get_bit(mask, num)) {
                            ++f[0][q][w];
                            ++f[1][q][e];
                            ++f[2][w][e];
                        }
                        ++num;
                    }
                }
            }
            int mx = 0;
            for (int q = 1; q <= a; ++q) {
                for (int w = 1; w <= b; ++w) {
                    mx = max(mx, f[0][q][w]);
                }
            }
            for (int q = 1; q <= a; ++q) {
                for (int w = 1; w <= c; ++w) {
                    mx = max(mx, f[1][q][w]);
                }
            }
            for (int q = 1; q <= b; ++q) {
                for (int w = 1; w <= c; ++w) {
                    mx = max(mx, f[2][q][w]);
                }
            }
            if (mx <= k) {
                ans = cnt;
                res = mask;
            }
        }
        cout << "Case #" << test << ": " << ans << endl;
        O << "Case #" << test << ": " << ans << endl;
        int num = 0;
        for (int q = 1; q <= a; ++q) {
            for (int w = 1; w <= b; ++w) {
                for (int e = 1; e <= c; ++e) {
                    if (get_bit(res, num)) {
                        O << q << " " << w << " " << e << endl;
                    }
                    ++num;
                }
            }
        }
    }
    return 0;
}
