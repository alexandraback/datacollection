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
	freopen("B-small-attempt0.in" , "r" , stdin);
	//freopen("input.txt" , "r" , stdin);
	freopen("B-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int m , n;
        int a[105][105];
        scanf("%d %d" , &n , &m);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                scanf("%d" , &a[i][j]);
        int ok = 1;
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j ++)
            {
                int ok1 = 1, ok2 = 1;
                for (int k = 0; k < n; k ++)
                    if (a[k][j] > a[i][j]) {ok1 = 0; break;}
                for (int k = 0; k < m; k ++)
                    if (a[i][k] > a[i][j]) {ok2 = 0; break;}
                ok = ok1 | ok2;
                if (ok == 0) break;
            }
            if (ok == 0) break;
        }
        if (ok == 0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}