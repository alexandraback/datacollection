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

int main()
{
//	freopen("E:\\things for work\\google\\B-large.in" , "r" , stdin);
//	freopen("E:\\things for work\\google\\out.txt" , "w" , stdout);

	int i , j , t , case_num = 1 , length;
	scanf("%d" , &t);
	while (t --)
	{
		scanf("%s%s" , input1 , input2);
		length = strlen(input1);
		for (i = 0;i < length;i ++)
		{
			if (input1[i] == input2[i])
			{
				if (input1[i] == '?')
					input1[i] = input2[i] = '0';
			}
			else
			{
				// 如果第一个是?
				if (input1[i] == '?')
					input1[i] = input2[i];
				// 如果第二个是?
				else if (input2[i] == '?')
					input2[i] = input1[i];
				else
					break;
			}
		}	
		bool is_less = false;
		if (i < length)
		{
			if (input1[i] < input2[i])
				is_less = true;
		}
		while (i < length)
		{
			if (input1[i] == '?' && input2[i] == '?')
			{
				if (is_less)
				{
					input1[i] = '9';
					input2[i] = '0';
				}
				else
				{
					input1[i] = '0';
					input2[i] = '9';
				}
			}
			// 如果上面是?
			else if (input1[i] == '?')
			{
				if (is_less)
					input1[i] = '9';
				else
					input1[i] = '0';
			}
			else if (input2[i] == '?')
			{
				if (is_less)
					input2[i] = '0';
				else
					input2[i] = '9';
			}
			i ++;
		}
		printf("Case #%d: %s %s\n" , case_num , input1 , input2);
		case_num ++;
	}
	return 0;
}

