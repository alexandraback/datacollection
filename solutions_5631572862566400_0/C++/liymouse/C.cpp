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
        int n;
        int a[1001];
        scanf("%d" , &n);
        for (int i = 1; i <= n; i ++) scanf("%d" , &a[i]);
        int b[11];
        for (int i = 0; i < n; i ++) b[i] = i+1;

        int res = 0;
        do
        {
            for (int L = res; L <= n; L ++)
            {
                int ok = 1;
                for (int i = 0; i < L; i ++)
                {
                    int x = (i == 0) ? b[L-1] : b[i-1];
                    int y = (i == L-1) ? b[0] : b[i+1];
                    if (a[b[i]] != x && a[b[i]] != y) {ok = 0; break;}
                }
                if (ok == 1 && L > res)
                {
                    //for (int i = 0; i < L; i ++) printf("%d " , b[i]); printf("\n");
                    res = L;
                }
            }
        }
        while(next_permutation(b , b + n));
        printf("%d\n" , res);

    }
    return 0;
}