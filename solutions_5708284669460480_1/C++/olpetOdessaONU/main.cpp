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

char red[2][111];

int ballance[2][256];
int k,l,s;

int table[111][256];

double dyn[111][111];

vector<int> pf;

vector<int> prefix_function (string s) // This function is copied from http://e-maxx.ru/algo/prefix_function
{
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

int getTail()
{
    for(int i = 1; red[1][i]; ++i)
    {
        bool good = 1;
        for(int j = 0; red[1][i+j]; ++j)
            if(red[1][i+j] != red[1][j])
            {
                good = false;
                break;
            }
        if(good)
            return i;
    }
    return l;
}

void buildTable()
{
    pf = prefix_function(red[1]);
    for(int j = 'A'; j <= 'Z'; ++j)
        if(red[1][0] == j)
            table[0][j] = 1;
        else
            table[0][j] = 0;
    for(int i = 0; i < l; ++i)
        for(int j = 'A'; j <= 'Z'; ++j)
        {
            if(j == red[1][i+1])
            {
                table[i + 1][j] = i + 2;
                continue;
            }
            int cur = pf[i];
            while(cur > -1 && red[1][cur] != j)
            {
                --cur;
                if(cur >= 0)
                cur = pf[cur];
            }
            table[i + 1][j] = cur + 1;
        }
//    for(int i = 0; i <= l; ++i)
//    {
//        for(int j = 'A'; j <= 'Z'; ++j)
//            printf("%d ", table[i][j]);
//        printf("\n");
//    }
}

void test(int T)
{
    scanf("%d%d%d",&k,&l,&s);
    scanf(" %s %s", red[0], red[1]);
    memset(ballance, 0, sizeof(ballance));
    memset(table, 0, sizeof(table));
    memset(dyn, 0, sizeof(dyn));
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; red[i][j]; ++j)
        {
            ballance[i][red[i][j]]++;
        }
    }
    double answ = 0.0;
    for(int i = 'A'; i <= 'Z'; ++i)
        if(ballance[0][i] == 0 && ballance[1][i] > 0)
        {
            answ = 0.0;
            printf("Case #%d: %.9lf\n", T, answ);
            return;
        }
    int bananas = 1;
    bananas += (s - l) / getTail();
    buildTable();
    dyn[0][0] = 1;
    for(int i = 0; i < s; ++i)
        for(int j = 0; j <= l; ++j)
            for(int f = 'A'; f <= 'Z'; ++f)
            {
                double prob = ballance[0][f] / (double) k;
                dyn[i+1][table[j][f]] += dyn[i][j] * prob;
            }
    for(int i = 0; i <= s; ++i)
        answ += dyn[i][l];
    answ = bananas - answ;
    printf("Case #%d: %lf\n", T, answ);
}

int main(int argc, const char * argv[])
{
    
    freopen("/Users/olpet/Downloads/tmp_files/b.in", "r", stdin);
    freopen("/Users/olpet/Downloads/tmp_files/b.out", "w", stdout);
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

