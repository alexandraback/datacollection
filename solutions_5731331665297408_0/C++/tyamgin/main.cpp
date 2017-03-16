#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm> 
#include <iostream> 
#include <string.h> 
#include <stdlib.h> 
#include <sstream> 
#include <fstream>
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

#define N 55

vector<int> g[N];
bool used[N];
string zip[N];
int n;

string dfs(int v, int prev)
{
	used[v] = 1;
	vector<int> to = g[v];
	if (prev != -1)
		to.erase(find(to.begin(), to.end(), prev));
	sort(to.begin(), to.end());
	string res = zip[v];
	do
	{
		string cur = zip[v];
		for (int t : to)
		{
			if (!used[t])
			{
				cur += dfs(t, v);
			}
		}
		if (cur.size() > res.size() || cur.size() == res.size() && cur < res)
			res = cur;
	} while (next_permutation(to.begin(), to.end()));
	used[v] = 0;
	return res;
}

/*
1
5 4
36642
28444
50012
29651
10953
1 4
2 3
2 5
4 5

1
5 5
36642
28444
50012
29651
10953
1 2
1 4
2 3
2 5
4 5
*/


int main()
{
	int tests, m, i, a, b;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++)
			g[i].clear();
		for (i = 0; i < n; i++)
			cin >> zip[i];
		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			a--, b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		string res;
		for (i = 0; i < n; i++)
		{
			auto r = dfs(i, -1);
			if (res == "" || res > r)
				if (r.size() / 5 == n)
					res = r;
		}
		printf("Case #%d: %s\n", test, res.c_str());
	}
}

//int main()
//{
//	int tests, a, b, k;
//	scanf("%d", &tests);
//	for (int test = 1; test <= tests; test++)
//	{
//		scanf("%d %d %d", &a, &b, &k);
//		int res = 0;
//		for (int i = 0; i < a; i++)
//		for (int j = 0; j < b; j++)
//		if ((i & j) < k)
//			res++;
//		printf("Case #%d: %d\n", test, res);
//	}
//}