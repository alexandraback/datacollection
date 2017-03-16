// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#pragma warning(disable:4996)
#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include<string>
#include <set>
#include <vector>
#define eps 1e-12
using namespace std;
struct data{
	int d;
	double v;
	data(int _d, double _v) :d(_d), v(_v)
	{

	}
	bool operator < (const data &cmp) const
	{
		return d < cmp.d;
	}
};
int dist(data qian, data hou, data user)
{
	//double time = (double)vec[i].v * (360 - vec[i].d) / 360;
	if (qian.d < hou.d)
	{
		hou.d -= 360;
		hou.d -= qian.d;
		qian.d = 0;
	}
	else {
		hou.d = hou.d - qian.d;
		qian.d = 0;
	}
	double q = qian.d + user.v/qian.v*(360.0-user.d);
	double h = hou.d + user.v/hou.v*(360.0-user.d);
	return (int)((ceil((h-q) / 360.0))+0.5);
}
int sign(double x)
{
	if (x>eps)
	{
		return 1;
	}
	if (x < -eps)
	{
		return -1;
	}
	return 0;
}
int main()
{
	freopen("C-small-1-attempt5.in", "r", stdin);
	freopen("C-small-1-attempt5_out.txt", "w", stdout);
	int tk, tk1 = 0;
	cin >> tk;
	while (tk--)
	{
		tk1++;
		int n;
		cin >> n;
		
		vector<data> vec;
		for (int i = 0; i < n; i++)
		{
			int d, h, m;
			cin >> d >> h >> m;
			for (int j = 0; j < h; j++)
			{
				vec.push_back(data(d, (double)(j + m)));
			}
			sort(vec.begin(), vec.end());
		}
		n = vec.size();
		int ans = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			int res = 0;
			for (int j = 0; j < n; j++)
			{
				if (vec[j].d < vec[i].d)
				{
					res++;
				}
				if (vec[j].d == vec[i].d && vec[j].v > vec[i].v)
				{
					res++;
				}
			}
			double time = (double)vec[i].v * (360 - vec[i].d) / 360;
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (sign(vec[i].v-vec[j].v)==0)
				{
					res += 0;
				}
				else if (sign(vec[i].v - vec[j].v)>0)
				{
					res += dist(vec[i], vec[j], vec[i]);
				}
				else {
					res += dist(vec[j], vec[i], vec[i]);
				}
			}
			ans = min(ans, res);
		}
		cout << "Case #" << tk1 << ": " << ans << endl;
	}
	return 0;
}