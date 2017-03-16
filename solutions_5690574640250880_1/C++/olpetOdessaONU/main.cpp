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

using namespace std;

char mas[60][60];
int r,c,m,empt;

bool cando(int r, int c, int m, int empt, int fr, int fc)
{
    for(int x = 2; x <= r; ++x)
    {
        int y = empt / x;
        if(y < 2)
            continue;
        int ost = empt % x;
        if(ost != 1 && 2 <= y && y + bool(ost) <= c)
        {
            for(int i=fr; i<fr+x; ++i)
                for(int j=fc; j<fc+y; ++j)
                    mas[i][j] = '.';
            for(int i = fr; i < fr+ost; ++i)
                mas[i][fc+y] = '.';
            
            for(int i = 0; i < fr; ++i)
                for(int j = 0; j < c; ++j)
                    mas[i][j] = '.';
            for(int i = 0; i < r; ++i)
                for(int j = 0; j < fc; ++j)
                    mas[i][j] = '.';
            mas[0][0] = 'c';
            
            return true;
        }
    }
    for(int y = 2; y <= c; ++y)
    {
        int x = empt / y;
        if(x < 2)
            continue;
        int ost = empt % y;
        if(ost != 1 && 2 <= x && x + bool(ost) <= r)
        {
            for(int i=fr; i<fr+x; ++i)
                for(int j=fc; j<fc+y; ++j)
                    mas[i][j] = '.';
            for(int j = fc; j < fc+ost; ++j)
                mas[fr+x][j] = '.';
            
            for(int i = 0; i < fr; ++i)
                for(int j = 0; j < c; ++j)
                    mas[i][j] = '.';
            for(int i = 0; i < r; ++i)
                for(int j = 0; j < fc; ++j)
                    mas[i][j] = '.';
            mas[0][0] = 'c';
            
            return true;
        }
    }
    return false;
}

void doit()
{
    if(r == 1 || c == 1)
    {
        bool was = 0;
        for(int i=0; i<r; ++i)
            for(int j=0; j<c; ++j)
                if(!was)
                {
                    was = 1;
                    mas[i][j] = 'c';
                    --empt;
                }
                else
                {
                    if(empt > 0)
                    {
                        --empt;
                        mas[i][j] = '.';
                    }
                }
        return;
    }
    if(empt == 1)
    {
        mas[0][0] = 'c';
        return;
    }
    for(int p = 0; p * c <= empt; ++p)
        if(p != 1)
            if(cando(r - p, c, m, empt - p * c, p, 0))
                return;
    for(int p = 0; p * r <= empt; ++p)
        if(p != 1)
            if(cando(r, c - p, m, empt - p * r, 0, p))
                return;
    r = 1;
    sprintf(mas[0], "Impossible");
    return;
}

void test(int T)
{
    memset(mas, 0, sizeof(mas));

    scanf("%d%d%d",&r,&c,&m);
    empt = r*c-m;
    for(int i=0; i<r; ++i)
        for(int j=0; j<c; ++j)
            mas[i][j] = '*';
    doit();
    
    printf("Case #%d:\n", T);
    for(int i=0; i<r; ++i)
        printf("%s\n",mas[i]);
}

int main(int argc, const char * argv[])
{

    freopen("/Users/olpet/Downloads/c.in", "r", stdin);
    freopen("/Users/olpet/Downloads/c.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}

