#include <cmath>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct level {
    int a, b;
};

int cmp(level a, level b) {
    return a.b < b.b;
}

const int MAXN = 1010;
int n, tot, ans;
level d[MAXN];
bool used[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tot;
    int num = 0;
    while (num < tot) {
        ++num;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &d[i].a, &d[i].b);
        }
        sort(d, d+n, cmp);
        memset(used, 0, sizeof(used));
        ans = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            while (cur < d[i].b) {
                bool change = false;
                for (int j = n-1; j >= i; --j)
                    if (!used[j] && d[j].a <= cur) {
                        used[j] = true;
                        ++cur;
                        ++ans;
                        change = true;
                        break;
                    }
                if (!change)
                    break;
            }
            if (cur < d[i].b) {
                ans = -1;
                break;
            }
            if (used[i])
                ++cur;
            else
                cur += 2;
            used[i] = true;
            ++ans;
        }
        if (ans < 0)
            printf("Case #%d: Too Bad\n", num);
        else
            printf("Case #%d: %d\n", num, ans);
    }
}
