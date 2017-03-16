//
//  main.cpp
//  Slides!
//
//  Created by Nasca Sergiu Alin on 08/05/16.
//  Copyright © 2016 Nasca Sergiu Alin. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <math.h>

int main(int argc, const char * argv[])
{
    long long  m, a[100][100], drum, start, stop, maxim, mat;
    int n, t;
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    scanf("%d", &t);
    for(int k = 1; k <= t; ++k)
    {
        printf("Case #%d: ", k);
        
        scanf("%d %lld", &n ,&m);

        if( (1 << (n-2)) < m)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        else printf("POSSIBLE\n");
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = i + 1; j <= n; ++j)
            {
                a[i][j] = 1;
            }
        }
        
        drum = (1 << (n-2));
        
        while(drum != m)
        {
            start = 0; stop = 0; maxim = 0;
            for(int j = n; j >= 1; --j)
            {
                for(int i = 1; i <= n; ++i)
                {
                    mat = (n - (j - i + 2));
                    if(mat < 0)
                    {
                        mat = 0;
                    }
                    if(drum - (1 << mat) >= m && maxim < (1 << mat))
                    {
                        start = i;
                        stop = j;
                        maxim = 1 << mat;
                    }
                }
            }
            a[start][stop] = 0;
            drum = drum - maxim;
        }
        
        for(int i = n-1; i >= 1; --i)
        {
            for(int j = n-1; j > i; --j)
            {
                if(a[ j ][n] == 0)
                {
                    a[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                printf("%lld ", a[i][j]);
            }
            printf("\n");
        }
        
        printf("\n");
    }
    return 0;
}
