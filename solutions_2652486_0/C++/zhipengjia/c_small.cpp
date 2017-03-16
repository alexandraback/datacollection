#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int x[7];

void solve(int k) {
    for (int a = 2; a <= 5; a ++)
        for (int b = 2; b <= 5; b ++)
            for (int c = 2; c <= 5; c ++) {
                bool flag = true;
                for (int i = 0; i < k; i ++) {
                    bool ok = false;
                    if (x[i] == 1) ok = true;
                    if (x[i] == a) ok = true;
                    if (x[i] == b) ok = true;
                    if (x[i] == c) ok = true;
                    if (x[i] == a * b) ok = true;
                    if (x[i] == a * c) ok = true;
                    if (x[i] == b * c) ok = true;
                    if (x[i] == a * b * c) ok = true;
                    if (! ok) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    printf("%d%d%d\n", a, b, c);
                    return;
                }
            }
}

void work() {
    int r, n, m, k;
    scanf("%d%d%d%d", &r, &n, &m, &k);
    while (r > 0) {
        r --;
        for (int i = 0; i < k; i ++)
            scanf("%d", &x[i]);
        solve(k);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test ++) {
        printf("Case #%d:\n", test + 1);
        work();
    }

    return 0;
}