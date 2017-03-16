//
//  c.cpp
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

#define maxN 10000007
#pragma comment(linker, "/STACK:36777216")

using namespace std;
int n;
vector<int> d;
vector<int> h;
vector<int> m;

void print(int test, int res)
{
    cout << "Case #" << test << ": "<<res << endl;
}

double timego(int pos, int speed)
{
    double dis = 360 - pos;
    double res = dis / 360 * speed;
    return res;
}

int main()
{
    //  FILE * f = fopen("", "r");
    //  FILE * fo = fopen("", "w");
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        cin >> n;
        d.resize(n + 1);
        h.resize(n + 1);
        m.resize(n + 1);
        int sumH = 0;
        
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i] >> h[i] >> m[i];
            sumH += h[i];
        }
        if (sumH < 2) print(t, 0);
        else
        {
          if (n == 1)
          {
              print(t, 0);
          }
            else
            {
                
                    double t1 = timego(d[1], m[1]);
                    double t2 = timego(d[2], m[2]);
                    
                    if ((t1 + m[1] <= t2) || (t2 + m[2] <= t1))
                        print(t, 1);
                        else print(t, 0);
               
            }
        }
    }
    
    
    return 0;
}
#endif