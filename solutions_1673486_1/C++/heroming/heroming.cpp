/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2012/4/28 9:33:15
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define SZ(v) ((int)(v).size())

int t, a, b;
double rate, x, y;

int main()
{
        freopen("A.out", "w", stdout);
        scanf("%d", &t);
        for (int l = 1; l <= t; ++ l)
        {
                scanf("%d%d", &a, &b);
                rate = b + 2.0;
                x = 1.0;
                for (int i = 1; i <= a; ++ i)
                {
                        scanf("%lf", &y);
                        x *= y;
                        double d = x * (a + b - 2 * i + 1) + (1 - x) * (a + b - 2 * i + b + 2);
                        rate = min(rate, d);
                }
                printf("Case #%d: %lf", l, rate);
                if (l != t)
                        printf("\n");
        }
        return 0;
}
