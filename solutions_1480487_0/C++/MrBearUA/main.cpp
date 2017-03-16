//
//  main.cpp
//  code_jam_c
//
//  Created by Andriy Medvid' on 14.04.12.
//  Copyright (c) 2012 taran studio. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int T, n, s[200], max;
    double result, d;
    freopen("a.out", "w", stdout);
    freopen("A-small-attempt0.in", "r", stdin);
    scanf("%d", &T);
    for(int t = 0; t < T; t++)
    {
        scanf("%d", &n);
        max = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", s + i);
            max += s[i];
        }
        printf("Case #%d: ", t+1);
        for(int q = 0; q < n; q++)
        {
            result = 0.5;
            d = 0.25;
            for(int i = 0; i < 40; i++)
            {
                double needed = 0;
                double myVal = s[q] + max * result;
                for(int j = 0; j < n; j++)
                    if(j != q)
                    {
                        if(s[j] <= myVal)
                            needed += (myVal - s[j]) / max;
                    }
                if(needed + result > 1)
                {
                    result -= d;
                }
                else {
                    result += d;
                }
                d /= 2.0;
            }
            printf("%.6lf ", result * 100);
        }
        printf("\n");
    }
    
    return 0;
}

