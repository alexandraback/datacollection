#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <fstream>
using namespace std;


bool check(long long x, string a)
{
	string h = to_string(x);
	long long l = a.length();
	long long need = l - h.length();
	if (need < 0)
		return false;
	string cmp = "";
	for (long long i = 0; i < need; i++)
		cmp += '0';
	cmp += h;
	for (long long i = 0; i < l; i++)
	{
		if (a[i] != '?')
		{
			if (a[i] != cmp[i])
				return false;
		}
	}
	return true;
}

string to_srt(long long x, long long l)
{
	string h = to_string(x);
	long long need = l - h.length();
	string cmp = "";
	for (long long i = 0; i < need; i++)
		cmp += '0';
	cmp += h;
	return cmp;
}

long long to_int(string x)
{
	long long res = 0;
	for (long long i = 0; i < x.length(); i++)
	{
		res *= 10;
		res += (x[i] - '0');
	}
	return res;
}

long long ans = 2e18;
long long t1 = 2e18;
long long t2 = 2e18;
string a, b;

string a_cur,b_cur;

void dfs(long long pos, long long f)
{
	if (pos == a.length())
	{
		long long i = to_int(a_cur);
		long long j = to_int(b_cur);
		long long cur = abs(i - j);
		if (cur < ans)
		{
			ans = cur;
			t1 = i;
			t2 = j;
		}
		if (cur == ans)
		{
			if (i < t1)
			{
				t1 = i;
				t2 = j;
			}
			if (t1 == i)
				t2 = min(t2, j);
		}
	}
	else
	{
		if (f < 0)
		{
			if (a_cur[pos] == '?')
				a_cur[pos] = '0';
			if (b_cur[pos] == '?')
				b_cur[pos] = '9';
			dfs(pos + 1, -1);
			a_cur[pos] = a[pos];
			b_cur[pos] = b[pos];
		}
		if (f > 0)
		{
			if (a_cur[pos] == '?')
				a_cur[pos] = '9';
			if (b_cur[pos] == '?')
				b_cur[pos] = '0';
			dfs(pos + 1, 1);
			a_cur[pos] = a[pos];
			b_cur[pos] = b[pos];
		}
		if (f == 0)
		{
			if (a_cur[pos] == '?')
			{
				if (b_cur[pos] == '?')
				{
					a_cur[pos] = '0';
					b_cur[pos] = '0';
					dfs(pos + 1, 0);
					a_cur[pos] = '1';
					b_cur[pos] = '0';
					dfs(pos + 1, -1);
					a_cur[pos] = '0';
					b_cur[pos] = '1';
					dfs(pos + 1, 1);
					a_cur[pos] = a[pos];
					b_cur[pos] = b[pos];
				}
				else
				{
					a_cur[pos] = b_cur[pos];
					dfs(pos + 1, 0);
					if (b_cur[pos] != '0')
					{
						a_cur[pos] = b_cur[pos] - 1;
						dfs(pos + 1, 1);
					}
					if (b_cur[pos] != '9')
					{
						a_cur[pos] = b_cur[pos] + 1;
						dfs(pos + 1, -1);
					}
					a_cur[pos] = a[pos];
					b_cur[pos] = b[pos];
				}
			}
			else
			{
				if (b_cur[pos] == '?')
				{
					b_cur[pos] = a_cur[pos];
					dfs(pos + 1, 0);
					if (a_cur[pos] != '0')
					{
						b_cur[pos] = a_cur[pos] - 1;
						dfs(pos + 1, -1);
					}
					if (a_cur[pos] != '9')
					{
						b_cur[pos] = a_cur[pos] + 1;
						dfs(pos + 1, 1);
					}
					a_cur[pos] = a[pos];
					b_cur[pos] = b[pos];
				}
				else
				{
					if (a_cur[pos] < b_cur[pos])
						dfs(pos + 1, 1);
					if (a_cur[pos] == b_cur[pos])
						dfs(pos + 1, 0);
					if (a_cur[pos] > b_cur[pos])
						dfs(pos + 1, -1);
				}
			}
		}
		a_cur[pos] = a[pos];
		b_cur[pos] = b[pos];
	}
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");


	long long qq;
	cin >> qq;
	for (long long qqq = 0; qqq < qq; qqq++)
	{
		cout << "Case #" << qqq + 1 << ": ";
		cin >> a >> b;
		a_cur = a;
		b_cur = b;
		ans = 2e18;
		t1 = 2e18;
		t2 = 2e18;
		dfs(0, 0);
		cout << to_srt(t1, a.length()) << " " << to_srt(t2, a.length()) << endl;
		
	}






	return 0;
}