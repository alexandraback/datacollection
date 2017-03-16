//
//  main.cpp
//  a
//
//  Created by qylqy on 14-5-11.
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
typedef  long long llong;

int solve(llong p, llong q)
{
    if (q==0 || p==0 || p>q) return -1;
    //cout << p << " " << q << endl;
    
    int ans = 0;
    
    while (p && (p%2)==0 && q && (q%2)==0)
    {
        p >>= 1;
        q >>= 1;
    }
    //cout << p << " " << (q)<< endl;
    
    llong qq = q;
    
    while (q && (q%2)==0)
    {
        ans ++;
        q >>= 1;
    }
    if (p % q) return -1;
    p /= q;
    qq /= q;
    
    //cout << p << qq << endl;
    
    while (p!=1)
    {
        p >>= 1;
        ans --;
    }
    
    
    return ans;
}

int main()
{

    int T, I, ans;
    llong p, q;
    scanf ("%d", &T); I = 1;
    while (T--)
    {
        printf ("Case #%d: ", I++);
        scanf ("%lld/%lld", &p, &q);
        //cout << p << " " << q;
        ans = solve(p, q);
        if (ans == -1)
            printf ("impossible\n");
        else
            printf ("%d\n", ans);
    }
    return 0;
}

