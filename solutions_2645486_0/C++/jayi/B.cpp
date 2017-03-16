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
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 10005
#define min(a,b) ((a)<(b) ? (a):(b))
#define max(a,b) ((a)>(b) ? (a):(b))

int e, r, n;
int v[N];
int ret;
int path[N];

void dfs(int eng, int pos, int gain) {
    if (pos == n) {
        if (gain > ret) {
            ret = gain;
//            for (int i = 0;i < n; ++i) {
//                printf("%d ", path[i]);
//            }
//            printf("\n");
        }
        return;
    }
    int i;
    for (i = 0; i <= eng; ++i) {
        path[pos] = i;
        dfs(min(eng - i + r, e), pos + 1, gain + i * v[pos]);
    }
}

int main(int argc, char *argv[])
{
    int T;
    int cas = 0;

    freopen("/home/hongjy/Downloads/B-small-attempt1.in", "r", stdin);
    freopen("B.txt", "w", stdout);

    scanf("%d", &T);
    while (T--) {
        printf("Case #%d: ", ++cas);
        scanf("%d%d%d", &e, &r, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
        }
        ret = 0;
        dfs(e, 0, 0);
        printf("%d\n", ret);
    }
    return EXIT_SUCCESS;
}

