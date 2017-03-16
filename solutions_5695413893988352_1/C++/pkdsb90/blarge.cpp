#include <bits/stdc++.h>

using namespace std;

#define  LL  long long

const LL Inf = 1e18 + 7;

int T, cas, len, flag; LL res0, res1, delta;

char ch[2][55], p[2][55];

void Gao(int pos) {
    if (pos == len) {
        LL s0 = 0, s1 = 0;
        bool mark = 0;
        for (int i = 0; i < len; i ++) s0 = s0 * 10 + ch[0][i] - '0';
        for (int i = 0; i < len; i ++) s1 = s1 * 10 + ch[1][i] - '0';
        if (abs(s0 - s1) < delta) {
            delta = abs(s0 - s1);
            mark = 1;
        } else if (abs(s0 - s1) == delta) {
            if (s0 < res0) {
                mark = 1;
            } else if (s0 == res0 && s1 < res1) {
                mark = 1;
            }
        }
        if (mark) {
            res0 = s0, res1 = s1;
            strcpy(p[0], ch[0]);
            strcpy(p[1], ch[1]);
        }
        return;
    }
    char t0 = ch[0][pos], t1 = ch[1][pos];
    if (flag == 0) {
        if (ch[0][pos] == '?' && ch[1][pos] == '?') {
            ch[0][pos] = '0', ch[1][pos] = '0'; flag = 0; Gao(pos + 1);
            ch[0][pos] = '0', ch[1][pos] = '1'; flag = -1; Gao(pos + 1);
            ch[0][pos] = '1', ch[1][pos] = '0'; flag = 1; Gao(pos + 1);
        } else if (ch[0][pos] == '?') {
            ch[0][pos] = ch[1][pos]; flag = 0; Gao(pos + 1);
            if (ch[1][pos] != '9') ch[0][pos] = ch[1][pos] + 1; flag = 1; Gao(pos + 1);
            if (ch[1][pos] != '0') ch[0][pos] = ch[1][pos] - 1; flag = -1; Gao(pos + 1);
        } else if (ch[1][pos] == '?') {
            ch[1][pos] = ch[0][pos]; flag = 0; Gao(pos + 1);
            if (ch[0][pos] != '9') ch[1][pos] = ch[0][pos] + 1; flag = -1; Gao(pos + 1);
            if (ch[0][pos] != '0') ch[1][pos] = ch[0][pos] - 1; flag = 1; Gao(pos + 1);
        } else {
            if (ch[0][pos] > ch[1][pos]) flag = 1;
            if (ch[0][pos] < ch[1][pos]) flag = -1;
            Gao(pos + 1);
        }
        flag = 0;
    } else if (flag == 1) {
        if (ch[0][pos] == '?') ch[0][pos] = '0';
        if (ch[1][pos] == '?') ch[1][pos] = '9';
        Gao(pos + 1);
    } else if (flag == -1) {
        if (ch[0][pos] == '?') ch[0][pos] = '9';
        if (ch[1][pos] == '?') ch[1][pos] = '0';
        Gao(pos + 1);
    }
    ch[0][pos] = t0, ch[1][pos] = t1;
}

int main() {
    freopen("B-large.in", "r", stdin);
//    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    while (T --) {
        printf("Case #%d: ", ++ cas);
        scanf(" %s %s", ch[0], ch[1]);
        len = strlen(ch[0]);
        res0 = Inf, res1 = Inf, delta = Inf, flag = 0;
        Gao(0);
        printf("%s %s\n", p[0], p[1]);
    }
}
