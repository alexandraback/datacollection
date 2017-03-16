#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void inc(long long &x, int val) {
    x = x * 10 + val;
}

bool try_equal(char s[], char str[], long long &x, long long &y, int len) {
    x = y = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '?' && str[i] == '?') {
            inc(x, 0);
            inc(y, 0);
        }
        else if (s[i] == '?') {
            inc(x, str[i] - '0');
            inc(y, str[i] - '0'); }
        else if (str[i] == '?') inc(x, s[i] - '0'), inc(y, s[i] - '0');
        else if (s[i] != str[i]) return false;
        else inc(x, s[i] - '0'), inc(y, s[i] - '0');
    }
    return true;
}

long long mabs(long long x, long long y) {
    if (x >= y) return x - y;
    return y - x;
}

void update(long long &ans1, long long &ans2, long long x, long long y) {
    if (mabs(ans1, ans2) > mabs(x, y)) {
        ans1 = x, ans2 = y;
    }
    else if (mabs(ans1, ans2) == mabs(x, y)) {
        if (ans1 > x || (ans1 == x && ans2 > y)) ans1 = x, ans2 = y;
    }
}

void output(long long x, int len) {
    int a[25];
    memset(a , 0, sizeof(a));
    int cnt = 0;
    while(x) {
        a[cnt ++] = x % 10;
        x /= 10;
    }
    for (int i = len - 1; i >= 0; i--) printf("%d", a[i]);
}

void output(long long ans1, long long ans2, int len) {
    output(ans1, len);
    printf(" ");
    output(ans2, len); 
    printf("\n");
}

bool try_bigger(char s[], char str[], long long &xx, long long &yy) {
    int len = strlen(s);
    if (!len) return true;
    if (s[0] == '?' && str[0] == '?') inc(xx, 1), inc(yy, 0);
    else if (s[0] == '?') {
        if (str[0] == '9') return false;
        inc(xx, str[0] + 1 - '0');
        inc(yy, str[0] - '0');
    }
    else if (str[0] == '?') {
        if (s[0] == '0') return false;
        inc(xx, s[0] - '0');
        inc(yy, s[0] - '0' - 1);
    }
    else if (s[0] <= str[0]) return false;
    else inc(xx, s[0] - '0'), inc(yy, str[0] - '0');
    for (int i = 1; i < len; i++) {
        if (s[i] == '?') inc(xx, 0);
        else inc(xx, s[i] - '0');
        if (str[i] == '?') inc(yy, 9);
        else inc(yy, str[i] - '0');
    }
    return true;
}

bool try_smaller(char s[], char str[], long long &xx, long long &yy) {
    if (!s[0]) return true;
    int len = strlen(s);
    if (!len) return true;
    if (s[0] == '?' && str[0] == '?') inc(xx, 0), inc(yy, 1);
    else if (s[0] == '?') {
        if (str[0] == '0') return false;
        inc(xx, str[0] - 1 - '0');
        inc(yy, str[0] - '0');
    }
    else if (str[0] == '?') {
        if (s[0] == '9') return false;
        inc(xx, s[0] - '0');
        inc(yy, s[0] - '0' + 1);
    }
    else if (s[0] >= str[0]) return false;
    else inc(xx, s[0] - '0'), inc(yy, str[0] - '0');
    for (int i = 1; i < len; i++) {
        if (s[i] == '?') inc(xx, 9);
        else inc(xx, s[i] - '0');
        if (str[i] == '?') inc(yy, 0);
        else inc(yy, str[i] - '0');
    }
    return true;
}

void solve(int cas) {
    char s[25], str[25];
    scanf("%s%s", s, str);
    int len = strlen(s);
    int dif = -1;
    long long ans1 = 0, ans2 = 1LL << 61;
    for (int i = 0; i <= len; i++) { 
        long long x, y;
        if (!try_equal(s, str, x, y, i)) continue; 
        if (i == len) {
            update(ans1, ans2, x, y);
            continue;
        }
        long long xx = x, yy = y;
        bool tmp = try_bigger(s + i, str + i, xx, yy);
        if (tmp) update(ans1, ans2, xx, yy);
        long long xxx = x, yyy = y;
        bool temp = try_smaller(s + i, str + i, xxx, yyy);
        if (temp) update(ans1, ans2, xxx, yyy);
    }
    printf("Case #%d: ", cas);
    output(ans1, ans2, strlen(s));
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) solve(i);
    return 0;
}
