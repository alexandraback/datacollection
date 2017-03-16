/*
 *     Filename:  A.cpp
 *
 *  Description:  
 *
 *      Version:  1.0
 *      Created:  04/13/2013 12:59:41 PM
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
#define LL long long

int a[128];
int sum[128];

int main(int argc, char *argv[])
{
    freopen("/home/hongjy/Downloads/A-large.in", "r", stdin);
//    freopen("in.txt", "r", stdin);
    freopen("A.txt", "w", stdout);
    int T;
    int i;

    scanf("%d", &T);
//    printf("%d\n", T);
    int cas = 0;
    int A, n;
    while (T--) {
        printf("Case #%d: ", ++cas);
        scanf("%d%d", &A, &n);
        for (i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
//        if (A == 1) {
//            printf("%d\n", n);
//            continue;
//        }
        sort(a, a + n);
        sum[0] = A;
        for (i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + a[i];
        }
        int ret = 100000000;
        int AA = A;
        for (int s = 0; s <= n; ++s) {

//            printf(" s= %d\n", s);
            int cnt = 0;
            A = AA;
            for (i = 0; i < s; ++i) {
//                printf("%d\n", cnt);
//                printf("cnt = %d, A=%d, a[i] = %d  \n", cnt, A, a[i]);
                if (a[i] < A) {
                    A += a[i];
                } else {
                    if (A == 1) break;
                    while (a[i] >= A) {
//                            printf("%d\n", A);
                        A += A - 1;
                        ++cnt;
                    }
                    A += a[i];
                }
            }
            cnt += n - i;

//            printf("%d %d\n", cnt, s);
            ret = min(cnt, ret);
        }
//        int pos = i;
//        printf("%d %d\n", A, pos);
        printf("%d\n", ret);
    }

    return EXIT_SUCCESS;
}

