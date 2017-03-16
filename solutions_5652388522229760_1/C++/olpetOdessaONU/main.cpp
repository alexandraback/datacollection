//
//  main.cpp
//  C
//
//  Created by Oleg Petrov on 09/04/2016.
//  Copyright © 2016 Oleg Petrov. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

int chMask(int mask, ll num)
{
    while(num > 0)
    {
        mask |= 1<<(num%10);
        num /= 10;
    }
    return mask;
}

void test(int t)
{
    ll n;
    cin>>n;
    int mask = 0;
    if(n == 0)
    {
        printf("Case #%d: INSOMNIA\n", t);
        return;
    }
    mask = chMask(mask, n);
    ll tmp = n;
    while(mask != 1023)
    {
        tmp += n;
        mask = chMask(mask, tmp);
//        if(n > 1e18)
//        {
//            printf("Case #%d: INSOMNIA\n", t);
//            return;
//        }
    }
    printf("Case #%d: %lld\n", t, tmp);
}

int main(int argc, const char * argv[])
{
    freopen("/Users/olpet/Downloads/gcj16/a.in", "r", stdin);
    freopen("/Users/olpet/Downloads/gcj16/a.out", "w", stdout);
    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i)
        test(i);
    return 0;
}
