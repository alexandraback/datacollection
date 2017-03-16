#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int tt, l, x;
char s[110000];

int op(int a, int b) {
    int t1 = 1;
    if (a < 0) {
        t1 = -1;
        a = -a;
    }
    int t2 = 1;
    if (b < 0) {
        t2 = -1;
        b = -b;
    }
    if (a == -1 || b == -1 || a == 1 || b == 1)
        return a * b * t1 * t2;
    if (a == b)
        return -1 * t1 * t2;
    if (a == 2 && b == 3)
        return t1 * t2 * 4;
    if (a == 2 && b == 4)
        return -1 * t1 * t2 * 3;
    if (a == 3 && b == 2)
        return -1 * t1 * t2 * 4;
    if (a == 3 && b == 4)
        return t1 * t2 * 2;
    if (a == 4 && b == 2)
        return t1 * t2 * 3;
    if (a == 4 && b == 3)
        return -1 * t1 * t2 * 2;
    return 1;
}
int c2i(char x) {
    return x - 'i' + 2;
}
char i2c(int x) {
    return x - 2 + 'i';
}
int gets(int n) {
    int tmp = 1;
    for (int i = 0; i < n; ++i) {
        tmp = op(tmp, c2i(s[i]));
        if (tmp == 2)
            return i + 1;
    }
    return -1;
}
int gete(int n) {
    int tmp = 1;
    int k = 1;
    for (int i = n-1; i >= 0; --i) {
        tmp = op(tmp, c2i(s[i]));
        if (tmp == k*4)
            return i;
        k = k*-1;
    }
    return -1;
}
int get(int pre, int post, int start, int end) {
    for (int i = start; i < end; ++i)
        pre = op(pre, c2i(s[i]));
    pre = op(pre, post);
    return pre;
}
int check(int xx) {
    int start, end, m;
    if (l < 10 || x < 5) {
        int now = l;
        for (int i = 0; i < x-1; ++i)
            for (int j = 0; j < l; ++j)
                s[now++] = s[j];
        start = gets(l * x);
        if (start == -1)
            return 0;
        end = gete(l * x);
        if (start >= end || end == -1)
            return 0;
        m = get(1, 1, start, end);
        //printf("here %d %d %d\n", start, end, m);
        return m == 3;
    }
    start = gets(l);
    if (start == -1)
        return 0;
    end = gete(l);
    if (end == -1)
        return 0;
    int pre = 1;
    int post = 1;
    pre = get(1, 1, start, l);
    post = get(1, 1, 0, end);
    for (int i = 0; i < x-2; ++i) {
        pre = op(pre, xx);
    }
    return op(pre, post) == 3;
}

int main() {
    scanf("%d", &tt);
    for (int t = 1; t <= tt; ++t) {
        scanf("%d %d\n", &l, &x);
        int tmp = 1;
        for (int i = 0; i < l; ++i) {
            scanf("%c", &s[i]);
            tmp = op(tmp, c2i(s[i]));
        }
        if (check(tmp))
            printf("Case #%d: YES\n", t);
        else
            printf("Case #%d: NO\n", t);
    }
}
