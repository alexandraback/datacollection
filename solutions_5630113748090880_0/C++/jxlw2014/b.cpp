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

int input[100][100];
int cnt[10000];

int main()
{
//	freopen("E:\\B-small-attempt0.in" , "r" , stdin);
//	freopen("E:\\out" , "w" , stdout);

	int i , j , t , n , case_num = 1;
	scanf("%d" , &t);
	while (t --)
	{
		vector<int> ans;
		memset(cnt , 0 , sizeof(cnt));
		scanf("%d" , &n);
		for (i = 1;i <= 2 * n - 1;i ++)
			for (j = 1;j <= n;j ++)
			{
				scanf("%d" , &input[i][j]);
				cnt[input[i][j]] ++;
			}
		for (i = 1;i <= 2600;i ++)
		{
			if (cnt[i] % 2 == 1)
				ans.push_back(i);
		}
		printf("Case #%d:" , case_num);
		case_num ++;
		for (i = 0;i < ans.size();i ++)
			printf(" %d" , ans[i]);
		printf("\n");
	}
	return 0;
}