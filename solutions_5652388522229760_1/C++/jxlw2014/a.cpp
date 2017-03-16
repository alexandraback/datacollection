#include <iostream>
#include <stdio.h>
#include <numeric>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <iomanip>
#include <set>
#include <queue>
#include <bitset>
#include <iomanip>
#include <map>
#include <string.h>
#include <stack>
#include <algorithm>

#include <unordered_map>
#include <unordered_set>

using namespace std;

bool vis[10];

int main()
{	
//	freopen("E:\\A-large.in" , "r" , stdin);
//	freopen("E:\\out.txt" , "w" , stdout);

	int i , j , t , case_num = 1;
	while (scanf("%d" , &t) != EOF)
	{
		while (t --)
		{
			long long n , ans = - 1;
			scanf("%I64d" , &n);
			memset(vis , 0 , sizeof(vis));
			for (i = 1;i <= 100000;i ++)
			{	
				long long value = (long long) i * n , v = value;
				while (value > 0)
				{
					vis[value % 10] = true;
					value /= 10;
				}
				for (j = 0;j < 10;j ++)
				{
					if (!vis[j])
						break;
				}
				if (j == 10)
				{
					ans = v;
					break;
				}
			}
			if (ans < 0)
				printf("Case #%d: INSOMNIA\n" , case_num);
			else
				printf("Case #%d: %I64d\n" , case_num , ans);
			case_num ++;
		}
	}
	return 0;
}





