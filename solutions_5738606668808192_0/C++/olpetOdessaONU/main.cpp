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

void oneCase(ll id, int len)
{
    string res = "11";
    for(int i = len/2-3; i >= 0; --i)
        if((id>>i) & 1)
            res += "11";
        else
            res += "00";
    res += "11";
    printf("%s", res.c_str());
    for(int i = 2; i <= 10; ++i)
        printf(" %d", i + 1);
    printf("\n");
}

void test(int t)
{
    printf("Case #%d:\n", t);
    int n, j;
    scanf("%d%d", &n, &j);
    for(int i = 0; i < j; ++i)
        oneCase(i, n);
}

int main(int argc, const char * argv[])
{
    freopen("/Users/olpet/Downloads/gcj16/c.in", "r", stdin);
    freopen("/Users/olpet/Downloads/gcj16/c.out", "w", stdout);
    int t;
    cin>>t;
    while(t--)
        test(1);
    return 0;
}
