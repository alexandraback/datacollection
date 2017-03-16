//
//  main.cpp
//  Fashion Police
//
//  Created by Nasca Sergiu Alin on 08/05/16.
//  Copyright © 2016 Nasca Sergiu Alin. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

typedef struct
{
    int a, b, c;
}NOD;

vector<NOD> v;

bool verificare(NOD t, int k)
{
    int contor = 0, x = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        x = 0;
        if(v[i].a == t.a)
        {
            x++;
        }
        if(v[i].b == t.b)
        {
            x++;
        }
        if(v[i].c == t.c)
        {
            x++;
        }
        if(x == 3)
        {
            return false;
        }
        if(x == 2)
        {
            contor++;
        }
    }
    if(contor >= k)
    {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[])
{
    int t, a, b, c, w;
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    scanf("%d", &t);
    for(int q = 1; q <= t; ++q)
    {
        printf("Case #%d: ", q);
        v.clear();
        
        scanf("%d %d %d %d", &a, &b, &c, &w);
        
        for(int i = 1; i <= a; ++i)
        {
            for(int j = 1; j <= b; ++j)
            {
                for(int k = 1; k <= c; ++k)
                {
                    if(verificare({i, j, k}, w) == true)
                    {
                        v.push_back({i, j, k});
                    }
                }
            }
        }
        
        printf("%lu\n", v.size());
        for(int i = 0; i < v.size(); ++i)
        {
            printf("%d %d %d\n", v[i].a, v[i].b, v[i].c);
        }
        
        printf("\n");
    }
    return 0;
}
