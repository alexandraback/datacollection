#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int T, n;
char s[2222];

bool check(int mid) {
    int now = mid;
    for (int i = 0; i <= n; i++) {
        if (now < i) return false;
        now += s[i] - '0';
    }
    return true;
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %s", &n, s);
        int st = 0;
        int ed = 10000;
        while (st < ed) {
            int mid = (st + ed) / 2;
            if (check(mid)) ed = mid;
            else st = mid + 1;
        }
        printf("Case #%d: %d\n", t, st);
    }

    return 0;

}
