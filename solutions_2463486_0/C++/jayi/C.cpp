/*
 *     Filename:  C.cpp
 *
 *  Description:  
 *
 *      Version:  1.0
 *      Created:  04/13/2013 02:48:28 PM
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

typedef long long LL;
#define N 10000000

LL fslist[N];
int len;

bool ispalindrome(LL n) {
    LL tmp = n, nn = 0;
    while (tmp) {
        nn = nn * 10 + tmp % 10;
        tmp /= 10;
    }
    return nn == n;
}

void init()
{
    len = 0;
    int i;
    for (i = 0; i < N; ++i) {
        if (!ispalindrome(i))
            continue;
        fslist[len] = (LL) i * (LL) i;
        if (ispalindrome(fslist[len])) {
            ++len;
        }
    }
}

int main(int argc, char *argv[])
{
    freopen("in.txt", "r", stdin);
    freopen("C.txt", "w", stdout);
    int T;
    int cas = 0;
    init();

    scanf("%d", &T);
    while (T--) {
        printf("Case #%d: ", ++cas);
        LL a, b;
        scanf("%lld%lld", &a, &b);
//        printf("%d\n", upper_bound(fslist, fslist + len, b));
//        printf("%d\n", lower_bound(fslist, fslist + len, a));
        printf("%d\n", (int)(upper_bound(fslist, fslist + len, b) - lower_bound(fslist, fslist + len, a)));
    }
    return EXIT_SUCCESS;
}

