#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
#include<map>
using namespace std;

typedef long long int L;
typedef unsigned long long int U;

main()
{
	int tc;
	scanf("%d", &tc);
	int row_o[4],col_o[4], d1_o, d2_o, inc;
	int row_x[4],col_x[4], d1_x, d2_x;
	char arr[6];
	for(int t = 1;t<=tc;t++)
	{
		for(int i =0;i<4;i++)
		{
			row_o[i] = 0;
			col_o[i] = 0;
			row_x[i] = 0;
			col_x[i] = 0;
		}
		d1_o = 0;
		d2_o = 0;
		d1_x = 0;
		d2_x = 0;
		inc = 0;
		for(int i = 0;i<4;i++)
		{
			scanf("%s", &arr);
			for(int j = 0;j<4 && inc <= 1;j++)
			{
				if(arr[j] == '.')
					inc = 1;
				else if(arr[j] == 'T')
				{
					row_o[i]++;
					col_o[j]++;
					row_x[i]++;
					col_x[j]++;
					if(i == j)
					{
						d1_o++;
						d1_x++;
					}
					else if(i+j == 3)
					{
						d2_o++;
						d2_x++;
					}
					if(row_o[i] == 4 || col_o[j] == 4 || d1_o == 4 || d2_o == 4)
						inc = 2;
					else if(row_x[i] == 4 || col_x[j] == 4 || d1_x == 4 || d2_x == 4)
						inc = 3;
				}
				else if(arr[j] == 'X')
				{
					row_x[i]++;
					col_x[j]++;
					if(i == j)
					{
						d1_x++;
					}
					else if(i+j == 3)
					{
						d2_x++;
					}
					if(row_x[i] == 4 || col_x[j] == 4 || d1_x == 4 || d2_x == 4)
						inc = 3;
				}
				else if(arr[j] == 'O')
				{
					row_o[i]++;
					col_o[j]++;
					if(i == j)
					{
						d1_o++;
					}
					else if(i+j == 3)
					{
						d2_o++;
					}
					if(row_o[i] == 4 || col_o[j] == 4 || d1_o == 4 || d2_o == 4)
						inc = 2;
				}
			}
		}
		if(inc == 0)
			printf("Case #%d: Draw\n", t);
		else if(inc == 1)
			printf("Case #%d: Game has not completed\n", t);
		else if(inc == 2)
			printf("Case #%d: O won\n",t);
		else if(inc == 3)
			printf("Case #%d: X won\n",t);
		
	}
}
