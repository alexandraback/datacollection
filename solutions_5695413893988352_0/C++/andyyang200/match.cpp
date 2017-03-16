//Andrew Yang
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>	
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

string a, b;
string x1, x2;
string bestx1, bestx2;
int best;
void dfs2(int index)
{
	if (index == b.length())
	{
		int a1 = 0;
		int a2 = 0;
		int pow = 1;
		RFOR(i, a.length() -1, -1)
		{
			a1 += pow * (x1[i] - '0');
			a2 += pow * (x2[i] - '0');
			pow *= 10;
		}
		if (abs(a1 - a2) < best)
		{
			best = abs(a1 - a2);
			bestx1 = x1;
			bestx2 = x2;
		}
		else if (abs(a1 - a2) == best)
		{
			if (x1 < bestx1)
			{
				bestx1 = x1;
				bestx2 = x2;
			}
			else if (x1 == bestx1)
			{
				if (x2 < bestx2)
				{
					bestx1 = x1;
					bestx2 = x2;
				}
			}
		}
		return;
	}
	if (b[index] == '?')
	{
		FOR(i, 0, 10)
		{
			x2[index] = '0' + i;
			dfs2(index + 1);
		}
	}
	else
	{
		x2[index] = b[index];
		dfs2(index + 1);
	}
}

void dfs(int index)
{
	if (index == a.length())
	{
		dfs2(0);
		return;
	}
	if (a[index] == '?')
	{
		FOR(i, 0, 10)
		{
			x1[index] = '0' + i;
			dfs(index + 1);
		}
	}
	else
	{
		x1[index] = a[index];
		dfs(index + 1);
	}
}

int main(void)
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int sets;
	cin >> sets;
	FOR(set, 1, sets + 1)
	{
		cin >> a >> b;
		x1.resize(a.size());
		x2.resize(b.size());
		best = INF;
		dfs(0);
		cout << "Case #" << set << ": " << bestx1 << " " << bestx2 << endl;
	}
}