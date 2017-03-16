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

char input[10000];

int main()
{
//	freopen("E:\\A-small-attempt0.in" , "r" , stdin);
//	freopen("E:\\out" , "w" , stdout);

	int i , j , k , t , case_num = 1 , length;
	scanf("%d" , &t);
	while (t --)
	{
		scanf("%s" , input);
		string s = "";
		length = strlen(input);
		for (i = 0;i < length;i ++)
		{
			if (s.empty())
				s = s + input[i];
			else
			{
				if (input[i] < s[0])
					s = s + input[i];
				else
					s = input[i] + s;
			}
		}
		printf("Case #%d: %s\n" , case_num , s.c_str());
		case_num ++;
	}
	return 0;
}