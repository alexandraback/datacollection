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

bool vis[1010];
int f[1010];

int get_length(int start , int target , int another)
{
	memset(vis , 0 , sizeof(vis));
	int ans = 0;
	while (!vis[start] && start != target && start != another)
	{
		vis[start] = true;
		ans ++;
		start = f[start];
	}
	if (start == target)
		return ans;
	else
		return 0;
}

int main()
{
//	freopen("E:\\C-small-attempt1.in" , "r" , stdin);
//	freopen("E:\\out" , "w" , stdout);

	int i , j , t , n , case_num = 1;
	scanf("%d" , &t);
	while (t --)
	{	
		scanf("%d" , &n);
		for (i = 1;i <= n;i ++)
			scanf("%d" , &f[i]);
		int max_length = 0;
		for (i = 1;i <= n;i ++)
		{
			int friend_index = f[i];
			// i and friend_index
			if (f[friend_index] == i)
			{
				int length1 = 0 , length2 = 0;
				for (j = 1;j <= n;j ++)
				{
					if (j != i && j != friend_index)
					{
						int temp = get_length(j , i , friend_index);
						if (temp > length1)
							length1 = temp;	
						temp = get_length(j , friend_index , i);
						if (temp > length2)
							length2 = temp;
					}
				}
				if (length1 + length2 + 2 > max_length)
					max_length = length1 + length2 + 2;	
			}
		}
		// 一个circle
		for (i = 1;i <= n;i ++)
		{
			int cur = i , temp = 1;
			memset(vis , 0 , sizeof(vis));
			while (!vis[cur])
			{
				vis[cur] = true;
				cur = f[cur];
				if (cur == i)
					break;
				temp ++;
			}
			if (cur == i && temp > max_length)
				max_length = temp;
		}
		printf("Case #%d: %d\n" , case_num , max_length);
		case_num ++;
	}
	return 0;
}

