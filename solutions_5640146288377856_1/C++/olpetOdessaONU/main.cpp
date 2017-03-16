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

using namespace std;

void test(int T)
{
    int r,c,w;
    scanf("%d%d%d",&r,&c,&w);
    int answ = r * (c / w);
    answ += w - 1;
    answ += bool(c % w);
    printf("Case #%d: %d\n", T, answ);
}

int main(int argc, const char * argv[])
{
    
    freopen("/Users/olpet/Downloads/tmp_files/a.in", "r", stdin);
    freopen("/Users/olpet/Downloads/tmp_files/a.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}

