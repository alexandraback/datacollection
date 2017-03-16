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

void test(int t)
{
    printf("Case #%d:", t);
    int k,c,s;
    scanf("%d%d%d", &k,&c,&s);
    if(k > c * s)
    {
        printf(" IMPOSSIBLE\n");
        return;
    }
    for(int i = 0; i < k; i += c)
    {
        ll res = 0;
        for(int j = i; j < i + c && j < k; ++j)
            res = res * k + j;
        ++res;
        printf(" %lld", res);
    }
    printf("\n");
}

int main(int argc, const char * argv[])
{
    freopen("/Users/olpet/Downloads/gcj16/d.in", "r", stdin);
    freopen("/Users/olpet/Downloads/gcj16/d.out", "w", stdout);
    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i)
        test(i);
    return 0;
}
