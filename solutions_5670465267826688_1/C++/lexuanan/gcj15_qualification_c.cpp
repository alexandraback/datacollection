#include <bits/stdc++.h>

char s[10005];

const int p[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2, -1, 4, -3},
    {0, 3, -4, -1, 2},
    {0, 4, 3, -2, -1}};

const int pat[] = {2, 4, -1};

int mult(int a, int b) {
    if (a > 0 && b > 0) return p[a][b];
    else if (a < 0 && b < 0) return p[-a][-b];
    else if (a < 0) return -p[-a][b];
    else return -p[a][-b];
}

int dd[20];

int main() {
    //freopen("C-large.in", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int *mark = dd+10;
    int ct;
    scanf("%d", &ct);
    for (int nt = 1; nt <= ct; nt++) {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", s);
        for (int i = 0; i < n; i++) s[i] -= ('i'-2);
        // tim i va j
        bool ok = true;
        int id = 0;
        int it = 0;
        int stat = 1;
        for (int pha = 0; pha < 2; pha++) {
            while (id < m && id < 16) {
                stat = mult(stat, s[it]);
                it++;
                if (it >= n) {
                    id++;
                    it = 0;
                }
                if (stat == pat[pha]) break;
            }
            if (stat != pat[pha]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            // tim k
            stat = 1;
            for (int i = 0; i < n; i++) stat = mult(stat, s[i]);
            for (int i = -4; i <= 4; i++) mark[i] = -1;
            int index;
            int tmp = 1;
            for (index = 1; index <= m; index++) {
                tmp = mult(tmp, stat);
                if (mark[tmp] == -1) {
                    mark[tmp] = index;
                }
                else {
                    break;
                }
            }
            if (index >= m) {
                if (tmp != pat[2]) ok = false;
            }
            else {
                int loop = index - mark[tmp];
                m -= mark[tmp];
                m %= loop;
                while (m > 0) {
                    tmp = mult(tmp, stat);
                    m--;
                }
                if (tmp != pat[2]) ok = false;
            }
        }
        printf("Case #%d: %s\n", nt, ok?"YES":"NO");
    }
    return 0;
}
