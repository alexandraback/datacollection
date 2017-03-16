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

char input1[100] , input2[100];
vector<int> v1 , v2;

void dfs(char input[] , int cur , int length , int value , vector<int>& v)
{
	if (cur == length)
		v.push_back(value);
	else
	{
		if (input[cur] == '?')
		{
			for (int i = 0;i < 10;i ++)
				dfs(input , cur + 1 , length , value * 10 + i , v);
		}
		else
		{
			value = value * 10 + (input[cur] - '0');
			dfs(input , cur + 1 , length , value , v);
		}
	}
}

int main()
{
//	freopen("E:\\things for work\\google\\B-small-attempt0.in" , "r" , stdin);
//	freopen("E:\\things for work\\google\\out.txt" , "w" , stdout);

	int i , j , t , case_num = 1;
	scanf("%d" , &t);
	while (t --)
	{
		v1.clear();
		v2.clear();
		scanf("%s%s" , input1 , input2);
		int length = strlen(input1) , ans = - 1 , ans1 = 0 , ans2 = 0;

		dfs(input1 , 0 , length , 0 , v1);
		dfs(input2 , 0 , length , 0 , v2);

		for (i = 0;i < v1.size();i ++)
		{
			int cur = v1[i] , close = - 1 , value = 0 , mid = 0 , tot = v2.size();
			// 找最近的
			int low = 0 , high = tot - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (v2[mid] < cur)
					low = mid + 1;
				else 
					high = mid - 1;
			}
			mid = max(mid - 5 , 0);
			while (mid < tot && v2[mid] < cur)
				mid ++;
			mid --;
			if (mid >= 0 && (abs(cur - v2[mid]) < close || close < 0))
			{
				close = abs(cur - v2[mid]);
				value = v2[mid];
			}
			mid ++;
			if (mid < tot)
			{
				if (abs(cur - v2[mid]) < close || close < 0)
				{
					close = abs(cur - v2[mid]);
					value = v2[mid];
				}
			}

			if (close < ans || ans < 0)
			{
				ans = close;
				ans1 = cur;
				ans2 = value;
			}
		}
		if (length == 1)
			printf("Case #%d: %d %d\n" , case_num , ans1 , ans2);
		else if (length == 2)
			printf("Case #%d: %02d %02d\n" , case_num , ans1 , ans2);
		else
			printf("Case #%d: %03d %03d\n" , case_num , ans1 , ans2);
		case_num ++;
	}
	return 0;
}


