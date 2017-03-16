#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("in.in");
ofstream fout("out.txt");

int f[3500] = {};
bool u[3500] = {};
bool p[3500] = {};
int pp[3500][2] = {};
int len[3500] = {};
int dest[3500] = {};
int n;
int pairs = 0;

int getCircle(int st)
{
	for (int i = 0; i <= n; i++)
		u[i] = false;
	int res = 0;
	int k = st;
	for (; !u[k]; k = f[k])
	{
		res++;
		u[k] = true;
	}
	if (k == st)
		return res;
	return 0;
}

int getMaxInput(int st1, int st2)
{
	for (int i = 0; i <= n; i++)
	{
		u[i] = false;
		dest[i] = 0;
		len[i] = -1;
	}
	len[st1] = 0;
	len[st2] = 0;
	dest[st1] = st1;
	dest[st2] = st2;
	u[st1] = true;
	u[st2] = true;
	int res1 = 0;
	int res2 = 0;
	stack<int> p;
	for (int i = 1; i <= n; i++)
	{
		int k = i;
		int res = 0;
		for (; !u[k]; k = f[k])
		{
			res++;
			u[k] = true;
			p.push(k);
		}
		if (k == st1)
		{
			res1 = max(res1, res);
		}
		if (k == st2)
		{
			res2 = max(res2, res);
		}
		while (!p.empty())
		{
			u[p.top()] = false;
			p.pop();
		}
		/*if (dest[k] == st1)
		{
			res1 = max(res1, res + len[k]);
			int l = 1;
			while (!p.empty())
			{
				int x = p.top();
				dest[x] = st1;
				len[x] = len[k] + l;
				l++;
				p.pop();
			}
		}
		if (dest[k] == st2)
		{
			res2 = max(res2, res);
			int l = 1;
			while (!p.empty())
			{
				int x = p.top();
				dest[x] = st2;
				len[x] = len[k] + l;
				l++;
				p.pop();
			}
		}
		while (!p.empty())
			p.pop();*/
	}
	return res1 + res2;
}

int main()
{
	int t;
	fin >> t;
	for (int q = 1; q <= t; q++)
	{
		fout << "Case #" << q << ": ";
		fin >> n;
		for (int i = 1; i <= n; i++)
			p[i] = false;
		for (int i = 1; i <= n; i++)
			fin >> f[i];
		pairs = 0;
		for (int i = 1; i <= n; i++)
			if (f[f[i]] == i && !p[i])
			{
				p[i] = true;
				p[f[i]] = true;
				pp[pairs][0] = i;
				pp[pairs][1] = f[i];
				pairs++;
			}
		int max1 = 0;
		for (int i = 1; i <= n; i++)
			max1 = max(max1, getCircle(i));
		int res = 0;
		for (int i = 0; i < pairs; i++)
		{
			res += getMaxInput(pp[i][0], pp[i][1]) + 2;
		}
		fout << max(max1, res) << endl;
	}
	return 0;
}
