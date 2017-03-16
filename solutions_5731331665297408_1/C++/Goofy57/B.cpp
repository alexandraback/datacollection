#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define pb push_back
#define mp make_pair 

using namespace std;

typedef long long ll; 

bool used2[100], used[100]; 
bool a[100][100]; 
string s[100]; 
int n, m; 

void dfs(int v)
{
	if(used2[v]) return; 
	used2[v] = 1; 
	for (int i = 0; i < n; i++)
	{
		if (a[v][i]) dfs(i); 
	}
}

void solve(int tc)
{
	cout << "Case #" << tc << ": "; 

	memset(used, 0, sizeof(used)); 
	memset(a, 0, sizeof(a)); 

	cin >> n >> m; 
	for (int i = 0; i < n; i++)
	{
		cin >> s[i]; 
	}
	for (int j = 0; j < m; j++)
	{
		int x, y; 
		cin >> x >> y; 
		x--, y--; 
		a[x][y] = 1; 
		a[y][x] = 1; 
	}


	int minv = 0; 
	for (int i = 1; i < n; i++)
	{
		if (s[i] < s[minv]) minv = i; 
	}

	used[minv] = 1; 
	vector <int> stack; 
	stack.pb(minv); 
	cout << s[minv]; 
	for (int ii = 0; ii < n - 1; ii++)
	{
		int minvv = -1; 
		int maxt = -1; 
		for (int v = 0; v < n; v++)
		{
			if (used[v]) continue; 
			for (int t = 0; t < stack.size(); t++)
			{
				if (a[stack[t]][v]) 
				{
					a[stack[t]][v] = 0; 
					a[v][stack[t]] = 0; 

					for (int i = 0; i < n; i++)
					{
						used2[i] = used[i]; 
					}
					dfs(v); 
					for (int i = 0; i <= t; i++)
					{
						used2[stack[i]] = 0; 
						dfs(stack[i]); 
					}

					bool ok = 1; 
					for (int i = 0; i < n; i++)
					{
						if (!used2[i]) ok = 0; 
					}

					if (minvv == v && t > maxt) maxt = t; 
					if (ok && (minvv == -1 || s[v] < s[minvv])) minvv = v, maxt = t; 
					

					a[stack[t]][v] = 1; 
					a[v][stack[t]] = 1; 
				}
			}
		}

		int v = minvv; 
		int t = maxt; 
		a[stack[t]][v] = 0; 
		a[v][stack[t]] = 0; 
		stack.resize(t + 1); 
		stack.pb(v); 
		used[v] = 1; 
		cout << s[v]; 

	}

	cout << endl; 
}


int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

	int tst = 0;
	cin >> tst; 
	for (int tc = 0; tc < tst; tc++)
	{
		cerr << tc + 1 << endl;
		solve(tc + 1); 
	}


	return 0; 
}