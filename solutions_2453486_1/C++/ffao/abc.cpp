#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int T;

char b[4][4];
int teste;

bool m(char a, char b) {
    return (a != '.' && b != '.') && (a == 'T' || b == 'T' || a == b);
}

bool check(char a, char b, char c, char d) {
    return m(a,b)&&m(a,c)&&m(a,d)&&m(b,c)&&m(b,d)&&m(c,d);
}

int main() {
    for (scanf("%d", &T); T; T--) {
        int empty = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf(" %c", &b[i][j]);
                if (b[i][j] == '.') empty++;
            }
        }

        printf("Case #%d: ", ++teste);
        bool ok = false;
        for (int i = 0; i < 4; i++) {
            if (check(b[i][0], b[i][1], b[i][2], b[i][3])) {
                printf("%c won\n", b[i][0]!='T'?b[i][0]:b[i][1]);
                ok = true;
                break;
            }

            if (check(b[0][i], b[1][i], b[2][i], b[3][i])) {
                printf("%c won\n", b[0][i]!='T'?b[0][i]:b[1][i]);
                ok = true;
                break;
            }

            if (check(b[0][0],b[1][1],b[2][2],b[3][3])) {
                printf("%c won\n", b[0][0]!='T'?b[0][0]:b[1][1]);
                ok = true;
                break;
            }

            if (check(b[3][0],b[2][1],b[1][2],b[0][3])) {
                printf("%c won\n", b[0][3]!='T'?b[0][3]:b[1][2]);
                ok = true;
                break;
            }
        }

        if (ok) continue;

        if (empty) printf("Game has not completed\n");
        else printf("Draw\n");
    }
}