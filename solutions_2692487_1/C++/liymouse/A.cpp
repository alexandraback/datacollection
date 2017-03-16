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
	freopen("A-large.in" , "r" , stdin);
	freopen("A-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n , a[102] , s;
        scanf("%d %d" , &s , &n);
        for (int i = 0; i < n; i ++) scanf("%d" , &a[i]);
        sort(a , a + n);
        int p[102] = {0};
        int t = s;
        if (t == 1)
        {
            printf("%d\n" , n);
            continue;
        }
        for (int i = 0; i < n; i ++)
            if (t > a[i])
            {
                t += a[i];
                if (i > 0) p[i] = p[i-1];
                if (t > 10000000) t = 10000000;
            }
            else
            {
                int add = 0;
                int tmp = t;
                while (tmp <= a[i])
                {
                    add ++;
                    tmp += tmp - 1;
                }
                if (i == 0) p[0] = add;
                else p[i] = p[i-1] + add;
                t = tmp + a[i];
            }
        int res = n;
        for (int i = 0; i < n; i ++)
            res = min(res , p[i] + n-i-1);
        printf("%d\n" , res);
    }
    return 0;
}