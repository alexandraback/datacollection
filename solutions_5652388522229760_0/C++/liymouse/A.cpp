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
	//freopen("B-large.in" , "r" , stdin);
	//freopen("B-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
		int n;
		scanf("%d" , &n);
		
		int ok = 1;
		int a[10] = {0};
		for (int k = 1; k <= 10000; k ++)
		{
			i64d t = (i64d)n * (i64d)k;
			while (t)
			{
				a[t%10] = 1;
				t /= (i64d)10;
			}
			ok = 1;
			for (int j = 0; j < 10; j ++) if (a[j] == 0) {ok = 0; break;}
			if (ok) {printf("%lld\n" , (i64d)n*(i64d)k); break;}
		}
		if (ok == 0)printf("INSOMNIA\n");
    }
    return 0;
}