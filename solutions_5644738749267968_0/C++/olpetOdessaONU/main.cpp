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

using namespace std;

int war(set<double> &nao, set<double> &ken)
{
    int answ = 0;
    for(set<double>::iterator it = nao.begin(); it != nao.end(); ++it)
    {
        set<double>::iterator fnd = ken.lower_bound(*it);
        if(fnd != ken.end())
            ken.erase(fnd);
        else
        {
            ken.erase(ken.begin());
            ++answ;
        }
    }
    return answ;
}

int dwar(set<double> &nao, set<double> &ken)
{
    int answ = 0;
    while(nao.size() > 0)
    {
        if(*nao.begin() < *ken.begin())
        {
            set<double>::iterator fnd = ken.end();
            --fnd;
            nao.erase(nao.begin());
            ken.erase(fnd);
        }
        else
        {
            ++answ;
            nao.erase(nao.begin());
            ken.erase(ken.begin());
        }
    }
    return answ;
}

void test(int T)
{
    int n;
    set<double> nao[2];
    set<double> ken[2];
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        double x;
        scanf("%lf", &x);
        nao[0].insert(x);
        nao[1].insert(x);
    }
    for(int i=0; i<n; ++i)
    {
        double x;
        scanf("%lf", &x);
        ken[0].insert(x);
        ken[1].insert(x);
    }
    printf("Case #%d: %d %d\n", T, dwar(nao[0], ken[0]), war(nao[1], ken[1]));
}

int main(int argc, const char * argv[])
{

    freopen("/Users/olpet/Downloads/d.in", "r", stdin);
    freopen("/Users/olpet/Downloads/d.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}

