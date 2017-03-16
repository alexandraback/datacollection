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
	freopen("C-small-1-attempt0.in" , "r" , stdin);

	freopen("C-small-1-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d:\n" , ca);
        int r , n , m , k;
        scanf("%d %d %d %d" , &r , &n , &m , &k);
        for (int pp = 0; pp < r; pp ++)
        {
        int a[10];
        for (int i = 0; i < k; i ++) scanf("%d" ,&a[i]);
        if (n == 1)
        {
            int res = 2;
            for (int i = 0; i < k; i ++) res = max(res , a[i]);
            printf("%d\n" , res);
        }
        else if (n == 2)
        {
            int ok = 0;
            int res1 , res2;
            for (int x = 2; x <= m; x ++)
            {
                for (int y = x; y <= m; y ++)
                {
                    ok = 1;
                    for (int i = 0; i < k; i ++)
                        if (a[i] != 1)
                        {
                            if (!(a[i] == x || a[i] == y || a[i] == x * y))
                            {
                                ok = 0;
                                break;
                            }
                        }
                    if (ok == 1)
                    {
                        res1 = x; res2 = y; break;
                    }
                }
                if (ok) break;
            }
            if (ok)
            printf("%d%d\n" , res1 , res2);
            else
                printf("22\n");
        }
        else
        {
            int ok = 0;
            int r1 , r2 , r3;
            for (int x = 2; x <= m; x ++)
            {
                for (int y = x; y <= m; y ++)
                {
                    for (int z = y; z <= m; z ++)
                    {
                        ok = 1;
                        for (int i = 0; i < k; i ++)
                            if (a[i] != 1)
                            {
                                if (!(a[i] == x || a[i] == y || a[i] == z ||
                                    a[i] == x * y || a[i] == y * z || a[i] == x * z ||
                                    a[i] == x * y * z))
                                {
                                    ok = 0; break;
                                }
                            }
                        if (ok)
                        {
                            r1 = x; r2 = y; r3 = z; break;
                        }
                    }
                    if (ok) break;
                }
                if (ok) break;
            }
            if (ok) printf("%d%d%d\n" , r1 , r2 , r3);
            else printf("222\n");
        }
        }
    }
    return 0;
}