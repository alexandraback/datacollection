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

int isV(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return 1;
    return 0;
}
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
        char s[1000100];
        scanf("%s %d" , s , &n);
        i64d res = 0;
        int L = strlen(s);
        for (int i = 0; i < L; i ++)
            for (int j = i; j < L; j ++)
            {
                int tot = 0;
                int ok = 0;
                for (int k = i; k <= j; k ++)
                {
                    if (isV(s[k]))
                    {
                        tot = 0;
                    }
                    else
                    {
                        tot ++;
                        if (tot >= n) {ok = 1; break;}
                    }
                }
                if (ok == 1) res ++;
            }
        printf("%lld\n" , res);
            
    }
    return 0;
}