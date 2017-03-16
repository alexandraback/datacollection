/*
 * =====================================================================================
 *
 *       Filename:  A.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月11日 17时11分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Terence (tec), 
 *   Organization:  Intel
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100000

long long gcd(long long a, long long b)
{
    while(b) {
        long long c = a; a = b; b = c % b;
    }
    return a;
}
int gen(long long p, long long q) {
    long long d = gcd(p, q);
    p /= d; q /= d;
    int r = 0;
    while(!(q & 1)) {
        q >>= 1;
        ++r;
    }
    if(q > 1 || r > 40)
        return -1;
    q = (1LL << r);
    r = 0;
    while(q > p) {
        q >>= 1;
        r++;
    }
    return r;
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int iCase = 1; iCase <= t; iCase++) {
        long long p, q, d;
        scanf("%lld/%lld", &p, &q);
        int r = gen(p, q);
        if(r >= 0) {
            printf("Case #%d: %d\n", iCase, r);
        } else {
            printf("Case #%d: impossible\n", iCase);
        }
    }
    return 0;
}

