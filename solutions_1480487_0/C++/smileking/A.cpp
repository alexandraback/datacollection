/*
 * A.cpp
 *
 *  Created on: 2012-5-6
 *      Author: jesliwang
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int idx, value;
};
bool cmp(node l, node r)
{
	return l.value > r.value;
}
int main(int argc, char* argv[])
{
	int T = 0;
	scanf("%d",&T);
	for(int x = 1; x <= T; x ++)
	{
		int n = 0;
		scanf("%d",&n);
		double sum = 0;
		node data[220];
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &data[i].value);
			data[i].idx = i;
			sum += data[i].value;
		}
		double base = sum;
		sum = sum*2.0;
		double aver = sum/n;
		double ans[220];
		sort(data, data+n, cmp);
		bool flag=false;
		for(int i = 0; i < n; i++)
		{
			if(!flag && data[i].value  >= aver )
			{
				ans[data[i].idx] = 0.0;
				sum -= data[i].value;
			}
			else
			{
				if(!flag)
				{
					aver = sum/(n-i);
					flag = true;
				}
				ans[data[i].idx] = (aver - data[i].value)/base;

			}
		}
		printf("Case #%d:", x);
		for(int i = 0; i < n; i++)
		{
			printf(" %.6lf", 100.0*ans[i]);
		}
		printf("\n");
	}

	return 0;
}


