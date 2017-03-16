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

i64d get(int s , int num , int k)
{
	i64d id = 1;
	i64d b = k;
	for (int i = 0; i < num; i ++)
	{
		int j = s + i;
		id = (id-1)*(i64d)k + (i64d)j; 
	}
	return id;
}
int main()
{
	freopen("D-small-attempt0.in" , "r" , stdin);
	freopen("D-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d:" , ca);
		int k , c , s;
		scanf("%d %d %d" , &k , &c , &s);
		/* only for small */
		int minv = (k / c) + (k % c != 0);
		if (s < minv) printf(" IMPOSSIBLE\n");
		else
		{
			for (int i = 1; i <= k; i += c)
			{
				i64d id = get(i , min(k-i+1 , c) , k);
				printf(" %lld" , id);
			}
			printf("\n");
		}
    }
    return 0;
}