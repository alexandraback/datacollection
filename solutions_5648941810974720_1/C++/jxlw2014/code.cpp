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

char input[10010];
int cnt[100];

int main()
{
//	freopen("E:\\things for work\\google\\A-large.in" , "r" , stdin);
//	freopen("E:\\things for work\\google\\out.txt" , "w" , stdout);

	int i , j , t , case_num = 1;
	scanf("%d" , &t);
	while (t --)
	{
		memset(cnt , 0 , sizeof(cnt));

		scanf("%s" , input);
		int length = strlen(input);
		for (i = 0;i < length;i ++)
		{
			int index = input[i] - 'A';
			cnt[index] ++;
		}
		int ans[10];

		ans[0] = cnt['Z' - 'A'];
		ans[6] = cnt['X' - 'A'];
		ans[7] = cnt['S' - 'A'] - ans[6];
		ans[5] = cnt['V' - 'A'] - ans[7];
		ans[2] = cnt['W' - 'A'];
		ans[4] = cnt['F' - 'A'] - ans[5];
		ans[3] = cnt['R' - 'A'] - ans[0] - ans[4];
		ans[1] = cnt['O' - 'A'] - ans[0] - ans[2] - ans[4];
		ans[8] = cnt['T' - 'A'] - ans[2] - ans[3];
		ans[9] = cnt['I' - 'A'] - ans[5] - ans[6] - ans[8];

		printf("Case #%d: " , case_num);
		for (i = 0;i < 10;i ++)
		{
			for (j = 0;j < ans[i];j ++)
				printf("%d" , i);
		}
		printf("\n");

		case_num ++;
	}
	return 0;
}





