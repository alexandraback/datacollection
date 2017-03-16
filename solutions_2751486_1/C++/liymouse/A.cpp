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
char s[1000100];
int f[1000001];
int main()
{
	freopen("A-large.in" , "r" , stdin);
	freopen("A-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n;
        
        scanf("%s %d" , s , &n);
        i64d res = 0;
        int L = strlen(s);
        int t = 0;
        int Len = 0;
        f[0] = 0;
        for (int i = 0; i < L; i ++)
        {
            if (isV(s[i]) == 0) Len ++;
            else Len = 0;
            f[i] = f[i-1];
            if (Len >= n)
            {
                f[i] += i - (n-1) - t + 1;
                t = i-(n-1) + 1;
            }
        }
        for (int i = 0; i < L; i ++) res = res + (i64d)f[i];
        printf("%lld\n" , res);
            
    }
    return 0;
}