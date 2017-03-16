#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<list>
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
using namespace std;

typedef long long LL;

LL P, Q;

LL gcd(LL a, LL b)
{
    LL r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int g2(LL a)
{
    int n = 0;
    while(a != 0) {
        a = a & (a-1);
        n++;
    }
    return n;
}

int main()
{
    CASET {
        scanf("%ld/%ld", &P, &Q);
        
        printf("Case #%d: ", case_n++);
        
        LL r = gcd(P, Q);
        P /= r;
        Q /= r;
        
        if(g2(Q) != 1){
            printf("impossible\n");
            continue;
        }
        r = 0;
        while(P < Q){
            r ++;
            Q /= 2;
        }
        printf("%ld\n", r);
    }
    return 0;
}
