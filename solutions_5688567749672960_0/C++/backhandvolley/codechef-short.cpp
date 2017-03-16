// codechef-short.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
#include <queue>
#include <fstream>
using namespace std;

int reverse(int num)
{
	int rev_num = 0;
	while (num > 0)
	{
		rev_num = rev_num * 10 + num % 10;
		num = num / 10;
	}
	return rev_num;
}

int solve(int x)
{
	queue<int> q;
	q.push(1);
	vector<int> vis(1005001, 0);
	vis[1] = 1;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (v == x)
		{
			return vis[v];
			break;
		}
		if (v + 1 <= 1e6 && !vis[v + 1]) {
			vis[v + 1] = vis[v] + 1;
			q.push(v + 1);
		}
		int r = reverse(v);
		if(r <= 1e6 && !vis[r]) {
			vis[r] = vis[v]+1;
			q.push(r);
		}

	}

	return -1;
}

int main()
{
	int t;
	ifstream in("in.txt");
	in >> t;
	ofstream out("out.txt");
	
	for (int tc = 1; tc<= t; tc++)
	{
		int n;
		in >> n;
		int x = solve(n);
		out << "Case #" << tc  << ": " << x << endl;
	}

	return 0;
}

