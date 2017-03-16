#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm>
#include <iostream> 
#include <string.h> 
#include <stdlib.h>
#include <complex>
#include <sstream> 
#include <fstream>
#include <numeric>
#include <ctype.h> 
#include <stdio.h> 
#include <bitset>
#include <vector> 
#include <string> 
#include <math.h> 
#include <time.h> 
#include <queue> 
#include <stack> 
#include <list>
#include <map> 
#include <set> 
#define Int long long 
#define INF 0x3F3F3F3F 
#define eps 1e-9
using namespace std;

#define N 1009

vector<int> g[N];
int pr[N];
bool used[N];

bool kuhn(int v)
{
	if (used[v])
		return false;
	used[v] = true;
	for(auto to : g[v])
	{
		if (pr[to] == -1 || kuhn(pr[to]))
		{
			pr[to] = v;
			return true;
		}
	}
	return false;
}

int main()
{
	int tests, n, i, j;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		scanf("%d", &n);
		vector<pair<string, string> > a(n);
		map<string, int> X1, X2;
		for (i = 0; i < n; i++)
		{
			cin >> a[i].first >> a[i].second;
			X1[a[i].first] = 0;
			X2[a[i].second] = 0;
		}
		int cnt = 0;
		for (auto &p : X1)
			p.second = cnt++;
		cnt = 0;
		for (auto &p : X2)
			p.second = cnt++;
		for (i = 0; i < (int)X1.size(); i++)
			g[i].clear();
		for (auto &p : a)
			g[X1[p.first]].push_back(X2[p.second]);
		memset(pr, -1, sizeof(pr));
		for (i = 0; i < (int)X1.size(); i++)
		{
			memset(used, 0, sizeof(used));
			kuhn(i);
		}
		int common = X2.size() - count(pr, pr + X2.size(), -1);
		printf("Case #%d: %d\n", test, n - (X1.size() + X2.size() - common));
	}
}