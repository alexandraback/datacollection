// gcj2012c.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int a[22];
map<int, int> p;
int main()
{
	freopen("in.txt","r",stdin);
    freopen("out5.txt","w",stdout);
    int t; cin >> t;
    int cas = 1;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        bool flag = false;
        printf("Case #%d:\n", cas++);
        for(int i = 1; i < (1 << n); ++i)
        {
            int sum = 0;
            for(int j = 0; j < n; ++j)
                if(i & (1 << j)) sum += a[j];
            if(p[sum] != 0)
            {
                int t1 = (i & p[sum]) ^ i, t2 = (i & p[sum]) ^ p[sum];
                flag = true;
                for(int k = 0; k < n; ++k)
                    if(t1 & (1 << k))
                    {
                        t1 ^= (1 << k);
                        printf("%d%c", a[k], t1 ? ' ' : '\n');
                    }
                for(int k = 0; k < n; ++k)
                    if(t2 & (1 << k))
                    {
                        t2 ^= (1 << k);
                        printf("%d%c", a[k], t2 ? ' ' : '\n');
                    }
                break;
            }
            else
            {
                p[sum] = i;
            }
        }
        if(!flag) puts("Impossible");
        p.clear();
    }
    return 0;
}
