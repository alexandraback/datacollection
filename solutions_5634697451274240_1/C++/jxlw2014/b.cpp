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

char input[1000];

int main()
{	
//	freopen("E:\\B-small-attempt0.in" , "r" , stdin);
//	freopen("E:\\out.txt" , "w" , stdout);

	int i , j , t , case_num = 1 , length;
	while (scanf("%d" , &t) != EOF)
	{
		while (t --)
		{
			scanf("%s" , input);
			length = strlen(input);
			int ans = 0;
			
			for (i = 0;i < length;i ++)
			{
				j = i;
				while (j < length && input[j] == input[i])
					j ++;
				ans ++;
				i = j - 1;
			}
			if (input[length - 1] == '+')
				ans --;

			printf("Case #%d: %d\n" , case_num , ans);
			case_num ++;
		}
	}
	return 0;
}