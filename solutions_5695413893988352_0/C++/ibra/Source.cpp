#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cassert>
#include <set>
#include <ctime>
#include <stack>
#include <cstring>
#include <fstream>
#include<functional>
#include <sstream>
#include <ctype.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

string s, t;
ll res;
ll rp1, rp2;
void go(ll p1, ll p2, int i)
{
	if (i == s.size())
	{
		ll cur = p1 < p2 ? (p2 - p1) : (p1 - p2);
		if (cur < res)
		{
			res = cur;
			rp1 = p1;
			rp2 = p2;
		}
		return;
	}

	if (s[i] != '?' && t[i] != '?')
	{
		go(p1 * 10LL + s[i] - '0', p2 * 10LL + t[i] - '0', i + 1);
	}
	else if (s[i] == '?' && t[i] == '?')
	{
		if (p1 == p2)
		{
			// if next n/n
			if (i + 1 < s.size() && s[i + 1] != '?' && t[i + 1] != '?')
			{
				if (s[i + 1] < t[i + 1])
				{
					go(p1 * 10LL+1, p2 * 10LL, i + 1);
				}
				else
				{
					go(p1 * 10LL, p2 * 10LL+1, i + 1);
				}
				go(p1 * 10LL, p2 * 10LL, i + 1);
			}
			else
			// else
				go(p1 * 10LL, p2 * 10LL, i + 1);
		}
		else
		{
			if (p1 < p2)
			{
				go(p1 * 10LL + 9, p2 * 10LL, i + 1);
			}
			else
			{
				go(p1 * 10LL, p2 * 10LL + 9, i + 1);
			}
		}
	}
	else // x ?
	{
		// if next n/n
		if (i + 1 < s.size() && s[i + 1] != '?' && t[i + 1] != '?')
		{
			if (s[i + 1] < t[i + 1])
			{
				if (s[i] == '?')
					go(p1 * 10LL + max(9,s[i] - '0' +1), p2 * 10LL + s[i] - '0', i + 1);
				else
					go(p1 * 10LL + max(9, t[i] - '0' + 1), p2 * 10LL + t[i] - '0', i + 1);
			}
			else
			{
				if (s[i] == '?')
					go(p1 * 10LL + s[i] - '0', p2 * 10LL + max(9, s[i] - '0' + 1), i + 1);
				else
					go(p1 * 10LL + t[i] - '0', p2 * 10LL + max(9, t[i] - '0' + 1), i + 1);
			}

			if (s[i] == '?')
				go(p1 * 10LL + s[i] - '0', p2 * 10LL + s[i] - '0', i + 1);
			else
				go(p1 * 10LL + t[i] - '0', p2 * 10LL + t[i] - '0', i + 1);
		}
		else
		{
			if (s[i] != '?')
				go(p1 * 10LL + s[i] - '0', p2 * 10LL + s[i] - '0', i + 1);
			else
				go(p1 * 10LL + t[i] - '0', p2 * 10LL + t[i] - '0', i + 1);
		}
			
	}
}

string make(int sz, int n)
{
	ostringstream os;
	char str[1000];
	string r(_itoa(n, str, 10));
	while (r.size() < s.size())
		r = "0" + r;
	return r;
}

int main()
{
	freopen("C:\\Users\\ibismail\\Downloads\\B-small-attempt0.in", "r", stdin);
	freopen("C:\\Users\\ibismail\\Downloads\\codejam\\out.txt", "w", stdout);
	int ts;
	scanf("%d", &ts);
	for (int test = 1; test <= ts; test++)
	{
		cin >> s;
		cin >> t;
		res = 1LL << 60;
		go(0, 0, 0);



		cout << "Case #" << test << ": " << make(s.size(), rp1) << " " << make(s.size(), rp2) << endl;
	}

	


	return 0;
}