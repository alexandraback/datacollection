#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int table[1000][1000];

int qx[1000000], qy[1000000], qz[1000000];
char qd[1000000];
int st, ed;

int recur(int a)
{
    if ( qx[a] == 500 && qy[a] == 500 ) return 0;

    recur(table[qx[a]][qy[a]]);
    printf("%c", qd[a]);

    return 0;
}

int main()
{
    int aa, nn, x, y, c;
    int sx, sy, tx, ty;
    scanf("%d", &nn);
    for (aa = 1; aa <= nn; aa++) {
        scanf("%d %d", &x, &y);
        memset(table, -1, sizeof(table));
        qx[0] = 500; qy[0] = 500; qz[0] = 0;
        st = 0; ed = 1;
        x += 500; y += 500;
        while ( qx[st] != x || qy[st] != y ) {
            tx = qx[st]; ty = qy[st]; c = qz[st] + 1;
            // N
            if ( ty + c < 1000 && table[tx][ty+c] < 0 ) {
                qd[ed] = 'N';
                qx[ed] = tx;
                qy[ed] = ty+c;
                qz[ed++] = c;
                table[tx][ty+c] = st;
            }
            // S
            if (ty - c >= 0 && table[tx][ty-c] < 0 ) {
                qd[ed] = 'S';
                qx[ed] = tx;
                qy[ed] = ty-c;
                qz[ed++] = c;
                table[tx][ty-c] = st;
            }
            // E
            if (tx + c < 1000 && table[tx+c][ty] < 0 ) {
                qd[ed] = 'E';
                qx[ed] = tx+c;
                qy[ed] = ty;
                qz[ed++] = c;
                table[tx+c][ty] = st;
            }
            // W
            if (tx - c > -250 && table[tx-c][ty] < 0) {
                qd[ed] = 'W';
                qx[ed] = tx-c;
                qy[ed] = ty;
                qz[ed++] = c;
                table[tx-c][ty] = st;
            }
            st++;
        }
        printf("Case #%d: ", aa);
        recur(st);
        printf("\n");
    }
    return 0;
}

