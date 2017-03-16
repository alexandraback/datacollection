//
//  main.cpp
//  b
//
//  Created by qylqy on 14-5-4.
//  Copyright (c) 2014年 linqiuyan. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#include <utility>
#include <cmath>
using namespace std;

long long solve(int a, int b, int k, int p)
{
    if (p<0) return 0;
    long long ans;
    int pa, pb;
    if (k==(1<<(p+1))-1)
        return ((long long)a+1)*(b+1);
    if (p==0 && k==0)
    {
        ans = 3;
        if (!a) ans--;
        if (!b) ans--;
        return ans;
    }
    if (p==0 && k)
    {
        if (a && b) return 4;
        if (a || b) return 2;
        return 1;
        ans = 4;
        if (!a) ans--;
        if (!b) ans--;
        if (!a && !b) ans--;
        return ans;
    }
    
    if (k&(1<<p))//1
    {
        //0 & 0;
        if (a&(1<<p))
            pa = (1<<p)-1;
        else
            pa = a;
        
        if (b&(1<<p))
            pb = (1<<p)-1;
        else
            pb = b;
        ans = solve(pa, pb, (1<<p)-1, p-1);
        //0 & 1;
        if (b&(1<<p))
            ans += solve(pa, b-(1<<p), (1<<p)-1, p-1);
        //1 & 0;
        if (a&(1<<p))
            ans += solve(a-(1<<p), pb, (1<<p)-1, p-1);
        //1 & 1
        if (b&(1<<p) && a&(1<<p))
            ans += solve(a-(1<<p), b-(1<<p), k-(1<<p), p-1);
    }
    else{
        //0 & 0;
        if (a&(1<<p))
            pa = (1<<p)-1;
        else
            pa = a;
        
        if (b&(1<<p))
            pb = (1<<p)-1;
        else
            pb = b;
        ans = solve(pa, pb, k, p-1);
        //0 & 1;
        if (b&(1<<p))
            ans += solve(pa, b-(1<<p), k, p-1);
        //1 & 0;
        if (a&(1<<p))
            ans += solve(a-(1<<p), pb, k, p-1);
    }
    //printf ("%d %d %d %d %lld\n", a, b, k, p, ans);
    return ans;
}
int main()
{
    int T, I, a, b, k;
    scanf ("%d", &T);
    for (I=1; I<=T; I++)
    {
        scanf ("%d%d%d", &a, &b, &k);
        printf ("Case #%d: %lld\n", I, solve(a-1, b-1, k-1, 31));
    }
    return 0;
}

