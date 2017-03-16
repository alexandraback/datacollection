//
//  main.cpp
//  A
//
//  Created by Oleg Petrov on 12/04/2014.
//  Copyright (c) 2014 Oleg Petrov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void test(int T)
{
    double c,f,x;
    scanf("%lf%lf%lf", &c, &f, &x);
    double answ = x * 0.5;
    double cps = 2.0;
    double curtime = 0.0;
    while(true)
    {
        curtime += c / cps;
        cps += f;
        double newansw = curtime + x / cps;
        if(newansw < answ)
            answ = newansw;
        else
            break;
    }
    printf("Case #%d: %.9lf\n", T, answ);
}

int main(int argc, const char * argv[])
{

    freopen("/Users/olpet/Downloads/b.in", "r", stdin);
    freopen("/Users/olpet/Downloads/b.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}

