#include <stdio.h>
#include <string.h>
#include <math.h>


char s1[100], s2[100];

int abs(int n) {
    if (n>0) return n;
    return -n;
}

int fit(int n, char *s) {
    int len = strlen(s);
    for (int i=len-1; i>=0; i--) {
        if ((n%10)!=s[i]-'0' && s[i]!='?')
            return false;
        n /= 10;
    }
    return true;
}
int better(int a, int b, int pa, int pb) {
    if (abs(pa-pb) > abs(a-b))
        return true;
    if (abs(pa-pb) == abs(a-b)) {
        if (pa>a) {
            return true;
        }
        if (pa==a && b<pb) {
            return true;
        }
    }
    return false;
}

int main() {
    int t, n, nten;
    int nowa, nowb;
    scanf("%d", &t);
    for (int c=1; c<=t; c++) {
        scanf("%s %s", s1, s2);
        n = strlen(s1);
        nten = 1;
        for (int i=0; i<n; i++) nten *= 10;

        nowa = -10000;
        nowb = 10000;
        for (int i=0; i<nten; i++) if (fit(i, s1)) {
            for (int j=0; j<nten; j++) if (fit(j, s2)) {
                if (better(i, j, nowa, nowb)) {
                    nowa = i;
                    nowb = j;
                }
            }
        }
        printf("Case #%d: %0*d %0*d\n", c, n, nowa, n, nowb);
    }
}
