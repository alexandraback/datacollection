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
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
int c,d,v;
bool dyn[666];
int mas[666];

void test(int T)
{
    int answ = 0;
    scanf("%d%d%d",&c,&d,&v);
    for(int i = 0; i < d; ++i)
        scanf("%d", mas+i);
    sort(mas, mas+d);
    memset(dyn, 0, sizeof(dyn));
    dyn[0] = 1;
    for(int i = 0; i < d; ++i)
        for(int j = v; j >= 0; --j)
            if(dyn[j])
                dyn[j + mas[i]] = 1;
    for(int i = 1; i <= v; ++i)
        if(!dyn[i])
        {
            ++answ;
            for(int j = v; j >= 0; --j)
                if(dyn[j])
                    dyn[j + i] = 1;
        }
    printf("Case #%d: %d\n", T, answ);
}

int main(int argc, const char * argv[])
{
    
//    freopen("/Users/olpet/Downloads/tmp_files/c.in", "r", stdin);
//    freopen("/Users/olpet/Downloads/tmp_files/c.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}

/*
 1
 6 2 2
 GOOGLE
 GO
 */

