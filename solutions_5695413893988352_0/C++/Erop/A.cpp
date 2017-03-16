#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


char s1[50], s2[50];

ll ans1, ans2;

enum EStatus {
    EQ,
    GT,
    LT
};

ll myabs(ll x) {
    if (x < 0)
        return -x;
    return x;
}

void update(ll x, ll y) {
    if (myabs(x - y) > myabs(ans1 - ans2))
        return;
    if (myabs(x - y) < myabs(ans1 - ans2)) {
        ans1 = x;
        ans2 = y;
        return;
    }
    if (x != ans1) {
        if (x < ans1) {
            ans1 = x;
            ans2 = y;
        }
        return;
    }
    if (y < ans2) {
        ans1 = x;
        ans2 = y;
    }
}

void find(int pos, ll x, ll y, EStatus st) {
    if (s1[pos] == 0) {
        update(x, y);
        return;
    }
    x *= 10;
    y *= 10;
    if (st == GT) {
        if (s1[pos] != '?')
            x += s1[pos] - '0';
        if (s2[pos] != '?') {
            y += s2[pos] - '0';
        }
        if (s2[pos] == '?') {
            y += 9;
        }
        find(pos + 1, x, y, st);
        return;
    }
    if (st == LT) {
        if (s1[pos] != '?')
            x += s1[pos] - '0';
        if (s2[pos] != '?') {
            y += s2[pos] - '0';
        }
        if (s1[pos] == '?') {
            x += 9;
        }
        find(pos + 1, x, y, st);
        return;
    }
    for (int i = 0; i < 10; ++i) {
        if (s1[pos] != '?' && s1[pos] - '0' != i)
            continue;
        for (int j = 0; j < 10; ++j) {
            if (s2[pos] != '?' && s2[pos] - '0' != j)
                continue;
            if (i == j && i != 0 && s1[pos] == '?' && s2[pos] == '?')
                continue;
            if (i < j)
                find(pos + 1, x + i, y + j, LT);
            if (i == j)
                find(pos + 1, x + i, y + j, EQ);
            if (i > j)
                find(pos + 1, x + i, y + j, GT);
        }
    }
}

char buff[500];

void print(ll v, int len) {
    for (int i = 0; i < len; ++i) {
        buff[i] = v % 10 + '0';
        v /= 10;
    }
    for (int i = len - 1; i >= 0; --i) {
        printf("%c", buff[i]);
    }
}

void solve() {
    scanf("%s%s", &s1, &s2);
    ans1 = 2e18;
    ans2 = 0;
    find(0, 0, 0, EQ);
    int len = strlen(s1);
    print(ans1, len);
    printf(" ");
    print(ans2, len);
    puts("");
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}