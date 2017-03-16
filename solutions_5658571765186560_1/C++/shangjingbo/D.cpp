#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int left[100], right[100];

bool dfs(int i, int r, int c, int x, int last_l, int last_r, int mod)
{
    if (i == r) {
        if (x == 0) {
            bool flag = true;
            for (int shift = -c; shift <= c; ++ shift) {
                bool valid = true;
                int ls = 0, rs = 0;
                for (int i = 0; i < r; ++ i) {
                    int ll = left[i] + shift;
                    int rr = right[i] + shift;
                    if (rr >= c || ll < 0) {
                        valid = false;
                        break;
                    }
                    ls += ll;
                    rs += c - 1 - rr;
                }
                if (!valid) {
                    continue;
                }
                if (ls % mod == 0 && rs % mod == 0) {
                    flag = false;
                    break;
                }
            }
            return flag;
        }
        return false;
    }
    for (int ll = 0; ll < c; ++ ll) {
        for (int rr = ll; rr < c; ++ rr) {
            if (rr - ll + 1 > x) {
                break;
            }
            if (max(last_l, ll) <= min(last_r, rr)) {
                left[i] = ll;
                right[i] = rr;
                if (dfs(i + 1, r, c, x - (rr - ll + 1), ll, rr, mod)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool solve(int r, int c, int x)
{
    return dfs(0, r, c, x, 0, c, x);
}

int main()
{
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);

    int test = 1, tests;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        int x, r, c;
        scanf("%d%d%d", &x, &r, &c);
        if (x >= 7 || max(r, c) < x || min(r, c) < (x + 1) / 2 || r * c % x != 0) {
            printf("Case #%d: RICHARD\n", test);
        } else {
            if (solve(r, c, x) || solve(c, r, x)) {
                printf("Case #%d: RICHARD\n", test);
            } else{
                printf("Case #%d: GABRIEL\n", test);
            }
        }
    }

    return 0;
}
