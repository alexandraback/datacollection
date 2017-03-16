//
//  a.cpp
//  codejam1B
//
//  Created by Tran Hieu on 5/2/15.
//  Copyright (c) 2015 TranHieu. All rights reserved.
//

#if 1
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stack>

#define for1(i,j,k) for (int i=j;i<=k;i++)
#define for2(i,n) for (int i=0;i<n;i++)
#define for1_(i,j,k) for (int i=j;i>=k;i--)
#define for2_(i,n) for (int i=n-1;i>=0;i--)
#define c_s cout.setf(ios::fixed)
#define c_p(x) cout.precision(x)
#define can(x,n) (int)pow(x,1.0/n)
#define mp(x,y) make_pair(x,y)
#define hvi(a,n) next_permutation(a,a+n)
#define Pi 2*asin(1.0)

#define maxN 1000007
#pragma comment(linker, "/STACK:36777216")

using namespace std;
int n;
vector<int> f;
queue<int> q;
vector<int> d;
vector<bool> inq;

void print(int test, int res)
{
    cout << "Case #" << test << ": "<<res << endl;
}
int reverseNum(int x)
{
    int res = x % 10;
    x /= 10;
    while (x > 0)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

void init()
{
    f.assign(maxN, -1);
    inq.assign(maxN, false);
    f[1] = 1;
    q.push(1);
    inq[1] = true;
    
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        //
        int next = x + 1;
        if (next < maxN && (f[next] == -1 || f[next] > f[x] + 1))
            {
                f[next] = f[x] + 1;
                if (!inq[next])
                {
                    q.push(next);
                    inq[next] = true;
                }
            }
        // reverse
        next = reverseNum(x);
        if (next < maxN && (f[next] == -1 || f[next] > f[x] + 1))
        {
            f[next] = f[x] + 1;
            if (!inq[next])
            {
                q.push(next);
                inq[next] = true;
            }
        }

    }
}
int main()
{
    //  FILE * f = fopen("", "r");
    //  FILE * fo = fopen("", "w");
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        cin >> n;
        print(t, f[n]);
    }
    
    
    return 0;
}
#endif