//
//  main.cpp
//  GCJ
//
//  Created by 祝风翔 on 14-5-11.
//  Copyright (c) 2014年 祝风翔. All rights reserved.
//

#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
LL gcd(LL a,LL b) {
    if(b == 0) return a;
    else return gcd(b,a%b);
}
bool ispow(LL x) {
    while(x % 2 == 0) x = x/2;
    if(x != 1) return false;
    return true;
}
int main(int argc, const char * argv[])
{

    // insert code here...
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t,cas = 0;
    scanf("%d",&t);
    while(t--) {
        LL P,Q;
        scanf("%lld/%lld",&P,&Q);
        LL c = gcd(P,Q);
        P = P/c;Q=Q/c;
        if(ispow(Q) == false) {
            printf("Case #%d: impossible\n",++cas);
        }else{
            int d = 0;
            while(P < Q) {
                d++;
                P = P * 2;
            }
            printf("Case #%d: %d\n",++cas,d);
        }
    }
    return 0;
}

