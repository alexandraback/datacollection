//
//  main.cpp
//  Close Match
//
//  Created by Nasca Sergiu Alin on 30/04/16.
//  Copyright © 2016 Nasca Sergiu Alin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

char a[40], b[40], c[40], d[40];
long long minim;
long long min1, min2;

void bktr(int p)
{
    if(p == strlen(a))
    {
        if(llabs(atoll(a) - atoll(b)) < minim)
        {
            strcpy(c, a);
            strcpy(d, b);
            minim = llabs(atoll(a) - atoll(b));
        }
    }
    else
    {
        if(a[p] == '?' && b[p] != '?')
        {
            for(int i = '0'; i <= '9'; ++i)
            {
                a[p] = i;
                bktr(p+1);
            }
            a[p] = '?';
        }
        else if(b[p] == '?' && a[p] != '?')
        {
            for(int i = '0'; i <= '9'; ++i)
            {
                b[p] = i;
                bktr(p+1);
            }
            b[p] = '?';
        }
        else if(a[p] == '?' && b[p] == '?')
        {
            for(int i = '0'; i <= '9'; ++i)
            {
                a[p] = i;
                for(int j = '0'; j <= '9'; ++j)
                {
                    b[p] = j;
                    bktr(p+1);
                }
            }
            a[p] = '?';
            b[p] = '?';
        }
        else bktr(p+1);
    }
}

int main(int argc, const char * argv[])
{
    int n, k;
    ifstream fin("file.in");
    ofstream fout("file.out");
    fin>>n;
    for(int i = 1; i <= n; ++i)
    {
        k = 0;
        
        fin>>a;
        fin>>b;
        
        minim = (1LL << 62);
        
        bktr(0);
        
        /*for(int j = 0; j < strlen(a); ++j)
        {
            if(k == 0)
            {
                if(a[j] == '?' && b[j] == '?')
                {
                    a[j] = '0';
                    b[j] = '0';
                }
                else if(a[j] == '?')
                {
                    a[j] = b[j];
                }
                else if(b[j] == '?')
                {
                    b[j] = a[j];
                }
                if(a[j] > b[j])
                {
                    k = 1;
                }
                else if(a[j] < b[j])
                {
                    k = -1;
                }
            }
            else if(k == 1)
            {
                if(b[j] == '?')
                {
                    b[j] = '9';
                }
                if(a[j] == '?')
                {
                    a[j] = '0';
                }
            }
            else if(k == -1)
            {
                if(b[j] == '?')
                {
                    b[j] = '0';
                }
                if(a[j] == '?')
                {
                    a[j] = '9';
                }
            }
        }*/
        
        //fout<<"Case #"<<i<<": "<<a<<" "<<b<<'\n';
        
        fout<<"Case #"<<i<<": "<<c<<" "<<d<<'\n';
    }
    return 0;
}
