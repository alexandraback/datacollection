#include <bits/stdc++.h>

using namespace std;

const int Inf = 1e9 + 7;

int T, cas, res0, res1, delta, len;

char ch[15][15], p[2][15];

void Gao(int id, int pos) {
    if (pos == len) {
        if (id == 0) Gao(1, 0);
        else {
            int s0 = 0, s1 = 0;
            bool flag = 0;
            for (int i = 0; i < len; i ++) s0 = s0 * 10 + ch[0][i] - '0';
            for (int i = 0; i < len; i ++) s1 = s1 * 10 + ch[1][i] - '0';
//            cout << ch[0] << ' ' << ch[1] << ' ' << s0 << ' ' << s1 << ' '<< delta << endl;
//            system("pause");
            if (abs(s0 - s1) < delta) {
                delta = abs(s0 - s1);
                flag = 1;
            } else if (abs(s0 - s1) == delta) {
                if (s0 < res0) {
                    flag = 1;
                } else if (s0 == res0 && s1 < res1) {
                    flag = 1;
                }
            }
            if (flag) {
//                cout << "~~~~~~~~~~" << endl;
                res0 = s0, res1 = s1;
                strcpy(p[0], ch[0]);
                strcpy(p[1], ch[1]);
            }
        }
        return;
    }
    if (ch[id][pos] != '?') Gao(id, pos + 1);
    else {
        for (int i = 0; i < 10; i ++) {
            ch[id][pos] = '0' + i;
            Gao(id, pos + 1);
        }
        ch[id][pos] = '?';
    }
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    while (T --) {
        printf("Case #%d: ", ++ cas);
        scanf(" %s %s", ch[0], ch[1]);
        len = strlen(ch[0]);
        res0 = Inf, res1 = Inf, delta = Inf;
        Gao(0, 0);
        printf("%s %s\n", p[0], p[1]);
    }
}
