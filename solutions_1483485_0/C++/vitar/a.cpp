#include <stdio.h>
#include <string.h>

#define N 1005

char a[] = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvyqee";
char b[] = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupazoo";

char d[257];
char c[N];
int u[300];
int i,j , k, n, m, x, y, z, t, T, tt;

int main() {
    freopen("small2.in", "r", stdin);
    freopen("small2a.out", "w", stdout);
    for (i = 0; a[i]; i ++) {
        d[a[i]] = b[i];
    }
    d[' '] = ' ';
    for (i = 'a'; i <= 'z'; i ++) {
        u[d[i]] = 1;
    }
    for (i = 'a'; i <= 'z'; i ++) {
        if (u[i] == 0) {
            x = i;
        }
    }
    for (i = 'a'; i <= 'z'; i ++) {
        if (d[i] == 0) {
            d[i] = x;
        }
    }
    scanf("%d\n", &T);
    for (tt = 1; tt <= T; tt ++) {
        gets(c);
        printf("Case #%d: ", tt);
        for (i = 0; c[i]; i ++) {
            printf("%c", d[c[i]]);
        }
        printf("\n");
    }
    return 0;
}