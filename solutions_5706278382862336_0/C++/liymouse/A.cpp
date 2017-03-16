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

i64d gcd(i64d x , i64d y)
{
    if (y == 0) return x;
    return gcd(y , x % y);
}

int main()
{
	freopen("A-small-attempt0 (1).in" , "r" , stdin);
	freopen("A-small-attempt0 (1).out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        i64d p , q;
        scanf("%I64d/%I64d" , &p , &q);
        i64d k = gcd(p , q);
        p /= k;
        q /= k;
        i64d x = 1;
        i64d y = 2;
        i64d t = q;
        int num = 0;
        while (t)
        {
            num += (t & 1);
            t >>= 1;
        }
        if (num > 1) printf("impossible\n");
        else
        {
            int ans = 1;
            while (1)
            {
                if (x * p < q && q <= y * p) break;
                ans ++;
                x *= (i64d)2; y *= (i64d)2;
            }
            printf("%I64d\n" , ans);
        }
    }
    return 0;
}