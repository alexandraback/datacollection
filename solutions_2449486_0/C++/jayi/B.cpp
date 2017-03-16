/*
 *     Filename:  B.cpp
 *
 *  Description:  
 *
 *      Version:  1.0
 *      Created:  04/13/2013 01:33:35 PM
 *     Revision:  none
 *     Compiler:  gcc
 *
 *       Author:  Hong Jinyi (hongjy), hongjy@chinanetcenter.com
 * Organization:  chinanetcenter
 */

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 128

int a[N][N]; 
int n, m;
void verticalcut(int c[][N], int s, int h) {
    int i;
    bool ok;

    ok = true;
    for (i = 0; i < n; ++i)
        if (a[i][s] > h)
            ok = false;
    
    if (!ok)
        return;

    for (i = 0; i < n; ++i) {
        c[i][s] = min(c[i][s], h);
    }
}

void horizoncut(int c[][N], int s, int h) {
    int i;
    bool ok;

    ok = true;
    for (i = 0; i < m; ++i)
        if (a[s][i] > h)
            ok = false;
    
    if (!ok)
        return;

    for (i = 0; i < m; ++i) {
        c[s][i] = min(c[s][i], h);
    }
}

int main(int argc, char *argv[])
{
    int T;
    int cas = 0;
    int c[N][N];
    int i, j;
    int b[2][N];

    freopen("in.txt", "r", stdin);
    freopen("B.txt", "w", stdout);

    scanf("%d", &T);
    while (T--) {
        printf("Case #%d: ", ++cas);
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; ++i) 
            for (j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
                c[i][j] = 100;
            }

        for (i = 0; i < n; ++i) {
            b[0][i] = a[i][0];
            for (j = 0; j < m; ++j) {
                b[0][i] = max(b[0][i], a[i][j]);
            }
//            printf("%d ", b[0][i]);
        }
//        puts("");

        for (j = 0; j < m; ++j) {
            b[1][j] = a[0][j];
            for (i = 0; i < n; ++i) {
                b[1][j] = max(b[1][j], a[i][j]);
            }
//            printf("%d ", b[1][j]);
        }
//        puts("");

        for (i = 0; i < n; ++i) {
            horizoncut(c, i, b[0][i]);
        }

        for (i = 0; i < m; ++i) {
            verticalcut(c, i, b[1][i]);
        }

        bool ok = true;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
//                printf("%d ", c[i][j]);
                if (a[i][j] < c[i][j]) 
                    ok = false;
            }
//            puts("");
        }

        if (ok) 
            puts("YES");
        else
            puts("NO");
    }
    return EXIT_SUCCESS;
}

