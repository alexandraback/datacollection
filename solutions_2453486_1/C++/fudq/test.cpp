/*
 * test.cpp
 *
 *  Created on: 2013-04-13
 *      Author: fudq
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
char f[10][10];

void jud()
{
	int sum_x,sum_o,sum_t,flag_x,flag_o,flag;
	flag_x=0;flag_o=0;flag=0;
	//row
	for(int i=0;i<4;i++)
	{
		sum_x=0;sum_o=0;sum_t=0;
		for(int j=0;j<4;j++)
		{
			if(f[i][j] == 'X')
				sum_x++;
			else if(f[i][j] == 'O')
				sum_o++;
			else if(f[i][j] == 'T')
				sum_t++;
			else
				flag=1;
		}
		if(sum_x == 4 || (sum_x == 3 && sum_t == 1))
			flag_x=1;
		if(sum_o == 4 || (sum_o == 3 && sum_t == 1))
			flag_o=1;
	}

	//column
	for(int i=0;i<4;i++)
	{
		sum_x=0;sum_o=0;sum_t=0;
		for(int j=0;j<4;j++)
		{
			if(f[j][i] == 'X')
				sum_x++;
			else if(f[j][i] == 'O')
				sum_o++;
			else if(f[j][i] == 'T')
				sum_t++;
		}
		if(sum_x == 4 || (sum_x == 3 && sum_t == 1))
			flag_x=1;
		if(sum_o == 4 || (sum_o == 3 && sum_t == 1))
			flag_o=1;
	}

	//diagonal_1
	sum_x=0;sum_o=0;sum_t=0;
	for(int i=0;i<4;i++)
	{
		if(f[i][i] == 'X')
			sum_x++;
		else if(f[i][i] == 'O')
			sum_o++;
		else if(f[i][i] == 'T')
			sum_t++;
	}
	if(sum_x == 4 || (sum_x == 3 && sum_t == 1))
		flag_x=1;
	if(sum_o == 4 || (sum_o == 3 && sum_t == 1))
		flag_o=1;

	//diagonal_2
	sum_x=0;sum_o=0;sum_t=0;
	for(int i=0;i<4;i++)
	{
		if(f[i][3-i] == 'X')
			sum_x++;
		else if(f[i][3-i] == 'O')
			sum_o++;
		else if(f[i][3-i] == 'T')
			sum_t++;
	}
	if(sum_x == 4 || (sum_x == 3 && sum_t == 1))
		flag_x=1;
	if(sum_o == 4 || (sum_o == 3 && sum_t == 1))
		flag_o=1;

	//result
	if(flag_x==1 && flag_o==0)
		printf("X won\n");
	else if(flag_x==0 && flag_o==1)
		printf("O won\n");
	else if(flag_x==1 && flag_o==1)
		printf("Draw\n");
	else if(flag==1)
		printf("Game has not completed\n");
	else if(flag==0)
		printf("Draw\n");
}

int main()
{
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<4;i++)
			scanf("%s",f[i]);
		printf("Case #%d: ",cas++);
		jud();
	}
    return 0;
}
