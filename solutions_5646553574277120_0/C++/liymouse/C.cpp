#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

int main()
{
	freopen("C-small-attempt0.in" , "r" , stdin);
	freopen("C-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int c , d , v;
        scanf("%d %d %d" , &c , &d , &v);
        int a[100] = {0};
        memset(a , 0 , sizeof(a));
        a[0] = 1;
        int b[10];
        for (int i = 0; i < d; i ++) scanf("%d" , &b[i]);
        for (int i = 0; i < d; i ++)
        {
            for (int j = v; j >= 0; j --)
                if (a[j] == 1 && j+b[i] <= v) a[j+b[i]] = 1;
        }
        int res = 0;
        while (1)
        {
            int ok = 1;
            int t;
            for (int i = 1; i <= v; i ++)
                if (a[i] == 0) 
                {
                    t = i;
                    ok = 0; break;
                }
            if (ok == 1) break;
            for (int i = v; i >= 0; i --)
            {
                if (a[i] == 1 && i + t <= v) a[i+t] = 1;
            }
            res ++;
        }
        printf("%d\n" , res);
    }
    return 0;
}