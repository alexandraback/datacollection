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
	freopen("C-large.in" , "r" , stdin);
	freopen("C-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int c , d;
        i64d v;
        scanf("%d %d %lld" , &c , &d , &v);
        int a[110] = {0};
        for (int i = 0; i < d; i ++) scanf("%d" , &a[i]);
        int res = 0;
        i64d now = 0;
        int x = 0;
        
        while (now < v)
        {
            if (x < d && now >= a[x]-1)
            {
                now += (i64d)a[x] * c;
                x ++;
            }
            else
            {
                res ++;
                i64d add = now+1;
                now += add * c;
            }
        }
        printf("%d\n" , res);
    }
    return 0;
}