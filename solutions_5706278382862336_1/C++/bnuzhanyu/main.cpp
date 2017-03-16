#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <map>
#include <string>
using namespace std;

int ispow2(long long y, long long x)
{
    if(x > (1LL<<40) || (x & (x-1)) ) return -1;
    int n = 1;
    while(y < (x/2)){
        n++;
        x >>= 1;
    }
    return n;
}

void ReadAndSolve(){
    int T;
    scanf("%d", &T);
    long long P, Q;
    char x[100];
    for(int ca=1; ca<=T; ca++){
        scanf("%s", x);
        sscanf(x, "%lld/%lld", &P, &Q);
        long long g = __gcd(P, Q);
        P/=g; Q/=g;
        int ans = ispow2(P, Q);
        printf("Case #%d: ", ca);
        if(ans == -1) printf("impossible\n");
        else printf("%d\n", ans);
    }
}


void UseStdIO(){
    ReadAndSolve();
}

void UseFileIO(){
    freopen("A3.in", "r", stdin);
    freopen("A3.out", "w", stdout);
    ReadAndSolve();
}


int main()
{
    bool toSubmit = 1;
    if(!toSubmit) UseStdIO();
    else UseFileIO();
    return 0;
}
