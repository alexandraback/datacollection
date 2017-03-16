#include <iostream>
#include <cstdio>
using namespace std;
char s[10010];
struct TT {
    TT() {v=0;m=0;}
    TT(char c) {
        m = 0;
        if (c == 'i') v = 1;
        else if (c == 'j') v = 2;
        else v = 3;
    }
    int v;//1-i;2-j;3-k;0-1
    bool m;//if minus
};
int T[4][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};
bool TM[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};
TT operator+(TT a, TT b) {
    TT c;
    c.v = T[a.v][b.v];
    c.m = a.m ^ b.m;
    c.m = c.m ^ TM[a.v][b.v];
    return c;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int l;
        long long x;
        cin >> l >> x;
        cin >> s;
        if (x > 16)
            x = 16 + x % 16;
        TT cur;
        int ck1 = 0, ck2 = 0;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < l; ++j) {
                cur = cur + TT(s[j]);
                if (!ck1 && cur.v == 1 && !cur.m)
                    ck1 = 1;
                if (ck1 && !ck2 && cur.v == 3 && !cur.m)
                    ck2 = 1;
            }
        }
        if (ck1 && ck2 && cur.v == 0 && cur.m)
            printf("Case #%d: YES\n", t);
        else
            printf("Case #%d: NO\n", t);
    }
}
