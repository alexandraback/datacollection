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
using namespace std;
int reverse(int x,int &digit)
{
	if (x == 0)
	{
		digit = 0;
		return 0;
	}
	else {
		int m = x % 10;
		int n = x / 10;
		int res = reverse(n, digit);
		int res1 = m;
		for (int i = 0; i < digit; i++)
		{
			res1 = res1 * 10;
		}
		digit++;
		return res + res1;
	}
}
int work(int n)
{
	set<int> st;
	struct data{
		int val, dist;
		data(int _val, int _dist) :val(_val), dist(_dist)
		{

		}
	};
	queue<data> que;
	st.insert(1);
	que.push(data(1, 1));
	while (st.count(n) == 0)
	{
		int val = que.front().val;
		int val1 = val+1;
		if (val1 == n)
		{
			return que.front().dist + 1;
		}
		int digit = 0;
		int val2 = reverse(val, digit);
		if (val2 == n)
		{
			return que.front().dist + 1;
		}
		if (st.count(val1) == 0)
		{
			que.push(data(val1, que.front().dist + 1));
			st.insert(val1);
		}
		
		if (st.count(val2) == 0 && val2<=n)
		{
			que.push(data(val2, que.front().dist + 1));
			st.insert(val2);
		}
		que.pop();
	}
	return 1;
}
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0_out.txt", "w", stdout);
	int tk, tk1 = 0;
	cin >> tk;
	while (tk--)
	{
		tk1++;
		int n;
		cin >> n;
		cout << "Case #" << tk1 << ": " << work(n) << endl;
	}
	return 0;
}