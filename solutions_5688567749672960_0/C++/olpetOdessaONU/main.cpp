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

int dyn[1000100];
bool was[1000100];

int revIt(int a)
{
    int answ = 0;
    while(a)
    {
        answ = 10 * answ + a % 10;
        a /= 10;
    }
    return answ;
}

void calcDyn()
{
    dyn[1] = 1;
    was[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        int nx = cur+1;
        for(int i=0; i<2; ++i)
        {
            if(nx <= 1e6+1 && !was[nx])
            {
                was[nx] = 1;
                dyn[nx] = dyn[cur]+1;
                q.push(nx);
            }
            nx = revIt(cur);
        }
    }
}

void test(int T)
{
    int n;
    scanf("%d",&n);
    printf("Case #%d: %d\n", T, dyn[n]);
}

int main(int argc, const char * argv[])
{
    
    freopen("/Users/olpet/Downloads/tmp_files/a.in", "r", stdin);
    freopen("/Users/olpet/Downloads/tmp_files/a.out", "w", stdout);
    calcDyn();
//    for(int i=1; i <= 100; ++i)
//        printf("%d %d\n", i, dyn[i]);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}

