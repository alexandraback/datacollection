#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
string s, str;

int sign(int x)
{
    return x > 0 ? 1 : -1;
}
int transform(int now, char s)
{
    if (s == 'i') {
        if (abs(now) == 1) {
            now = now * 2;
        } else if (abs(now) == 2) {
            now = -sign(now);
        } else if (abs(now) == 3) {
            now = -sign(now) * 4;
        } else {
            now = sign(now) * 3;
        }
    } else if (s == 'j') {
        if (abs(now) == 1) {
            now = now * 3;
        } else if (abs(now) == 2) {
            now = sign(now) * 4;
        } else if (abs(now) == 3) {
            now = -sign(now);
        } else {
            now = -sign(now) * 2;
        }
    } else {
        if (abs(now) == 1) {
            now = sign(now) * 4;
        } else if (abs(now) == 2) {
            now = -sign(now) * 3;
        } else if (abs(now) == 3) {
            now = sign(now) * 2;
        } else {
            now = -sign(now);
        }
    }
    return now;
}

int check(const string &s, int st, int len, int goal) {
    int now = 1;
    for (int i = st; i < len; i++) {
        now = transform(now, s[i]);
        if (now == goal) {
            return i + 1;
        }
    }
    return - 1;
}

int check2(const string &s, int st, int len) {
    int now = 1;
    for (int i = st; i < len; i++) {
        now = transform(now, s[i]);
    }
    return now == 4;
}


bool work()
{
    int L, X;
    cin >> L >> X;
    cin >> s;
    str = "";
    for (int i = 0; i < X; i++) {
        str += s;
    }
    int n = str.length();
    int i = check(str, 0, n, 2);
    if (i == -1) {
        return false;
    }
    int j = check(str, i, n, 3);
    if (j == -1) {
        return false;
    }
    int k = check2(str, j, n);
    if (k == 0) {
        return false;
    }
    return true;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        puts(work() ? "YES" : "NO");
    }
    return 0;
}