#include<cstdio>
char s[10002], sb[10002];
char sp2[8][8], sp3[8][8];
char ful[4];
static const int multable[][4] = {{0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4}};
static inline int mult(int a, int b) {
    int neg = ((a > 3 && !(b > 3)) || (b > 3 && !(a > 3))) << 2;
    return (multable[a % 4][b % 4] + neg) % 8;
}
int main() {
    int tt, l, x, i, j;
    int p1, p2, p3;
    int possible;
    scanf("%d", &tt);
    for (int t=1; t<=tt; t++) {
        scanf("%d %d", &l, &x);
        scanf("%s", s);
        possible = 0;
        for (i=0; i<8; i++) {
            for (j=0; j<8; j++) {
                sp2[i][j] = 0;
                sp3[i][j] = 0;
            }
        }
        for (i=0; i<l; i++) {
            switch (s[i]) {
                case 'i': s[i] = 1; break;
                case 'j': s[i] = 2; break;
                case 'k': s[i] = 3; break;
            }
        }
        sb[l] = 0;
        for (i=l-1; i>=0; i--) {
            sb[i] = mult(s[i], sb[i+1]);
        }
        ful[0] = 0;
        ful[1] = sb[0];
        ful[2] = mult(sb[0], sb[0]);
        ful[3] = mult(sb[0], ful[2]);
        p1 = 0;
        for (i=0; i<l; i++) {
            sp2[p1][sb[i]] = 1;
            p2 = 0;
            for(j=i; j<l; j++) {
                p3 = sb[j];
                if (p2 == 2) {
                    sp3[p1][p3] = 1;
                }
                p2 = mult(p2, s[j]);
            }
            p1 = mult(p1, s[i]);
        }
        // check 2
        for (i=0; i<64*64; i++) {
            int i1 = i/(8*64);
            int i2 = (i/64)%8;
            int i3 = (i/8)%8;
            int i4 = i%8;
            if (!sp2[i1][i2] || !sp2[i3][i4]) {
                continue;
            }
            for (j=0; j<64; j++) {
                int k1 = j/16;
                int k2 = (j/4)%4;
                int k3 = j%4;
                if (mult(ful[k1], i1) == 1 && mult(mult(i2, ful[k2]), i3) == 2 && mult(i4, ful[k3]) == 3 && (k1+k2+k3+2 <= x) && ((x-k1-k2-k3-2) % 4 == 0)) {
                    possible = 1;
                }
            }
        }
        // check 3
        for (i=0; i<64; i++) {
            int i1 = i/8;
            int i2 = i%8;
            if (!sp3[i1][i2]) {
                continue;
            }
            for (j=0; j<16; j++) {
                int k1 = j/4;
                int k2 = j%4;
                if (mult(ful[k1], i1) == 1 && mult(i2, ful[k2]) == 3 && (k1+k2+1 <= x) && ((x-k1-k2-1) % 4 == 0)) {
                    possible = 1;
                }
            }
        }
        if (possible) {
            printf("Case #%d: YES\n", t);
        } else {
            printf("Case #%d: NO\n", t);
        }
    }
    return 0;
}
