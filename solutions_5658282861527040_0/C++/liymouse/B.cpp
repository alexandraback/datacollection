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
	freopen("B-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int a , b , k;
        scanf("%d %d %d" , &a , &b , &k);
        int num = 0;
        for (int i = 0; i < a; i ++)
            for (int j = 0; j < b; j ++)
            {
                if ((i & j) < k) num ++;
            }
        printf("%d\n" , num);
    }
    return 0;
}