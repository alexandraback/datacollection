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
	freopen("A-small-attempt0.in" , "r" , stdin);
	freopen("A-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n;
        char s[1500];
        scanf("%d %s" , &n , s);
        int res = 0;
        int now = 0;
        for (int i = 0; i <= n; i ++)
        {
            if (now >= i) now += s[i]-'0';
            else if (s[i] > '0')
            {
                res += i - now;
                now = i + s[i]-'0';
            }
        }
        printf("%d\n" , res);
    }
    return 0;
}