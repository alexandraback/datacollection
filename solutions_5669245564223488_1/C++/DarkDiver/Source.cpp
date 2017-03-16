#pragma warning (disable : 4996)

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <stack>
#include <algorithm>
#include <ios>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <set>
#include <functional>
#include <cmath>
#include <sstream>
#include <map>
#include <memory.h>
#include <stdio.h>
#include <cassert>
#include <string.h>

#define forn(i , n) for (int i = 0; i < n; ++i)
#define down(i, n) for (int i = n - 1; i >= 0; --i)


using namespace std;

typedef unsigned long long int u64;
typedef long long int i64;
typedef vector<int> vint;
typedef vector<i64> vi64;
typedef pair<int, int> pint;
typedef pair<i64, i64> pi64;

#define FILE_NAME "file"

double sqr(double a)
{
	return a * a;
}

struct Node
{
	int is;
	int used;
	int v;
	int prev, next;
	Node()
	{
		next = prev = -1;
		v = 0;
		used = false;
		is = 0;
	}
};


int check(vector<string> & arr, vector<int> & p)
{
	int used[30];
	forn(i, 30)
		used[i] = 0;
	string s;
	forn(i, arr.size())
	{
		s += arr[p[i]];
	}
	forn(i, s.length() - 1)
	{
		if (s[i] == s[i + 1])
		{
			continue;
		}
		else
		{
			if (used[s[i + 1] - 'a'])
				return 0;
			used[s[i] - 'a'] = 1;
		}
	}
	return 1;

}

string clear(string a)
{
	string str;
	str += a[0];
	forn(i, a.length() - 1)
	{
		if (a[i] != a[i + 1])
		{
			str += a[i + 1];
		}
	}
	return str;
}

i64 factN[200];

i64 fact(int n)
{
	return factN[n];
}

#define MODULE 1000000007


i64 dfs(vector<Node> & g, int v)
{
	i64 ans = 1;
	g[v].used = 1;
	ans *= fact(g[v].v);
	int next = g[v].next;
	if (next == -1)
	{
		g[v].used = 2;
		return ans;
	}
	if (g[next].used == 1)
	{
		g[v].used = 2;
		return 0;
	}
	else if (g[next].used == 2)
	{
		g[v].used = 2;
		return ans;
	}
	else
	{
		ans =  (ans * dfs(g, next)) % MODULE;
		g[v].used = 2;
		return ans;
	}



	return ans;
}


int main()
{
	forn(i, 200)
	{
		if (i == 0)
			factN[i] = 1;
		else
			factN[i] = factN[i - 1] * i;
		factN[i] %= MODULE;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(15);
#ifdef FILE_INPUT
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	int test;
	cin >> test;
	forn(t, test)
	{
		vector<Node> g(30);
		int n;
		cin >> n;
		vector<string> arr(n);
		i64 ans = 1;
		forn(i, n)
		{
			string s;
			cin >> arr[i];
			arr[i] = clear(arr[i]);
			s = arr[i];
			int l = s.length();
			if (l == 1)
			{
				g[s[0] - 'a'].v++;
				continue;
			}
			
			
			forn(j, l - 1)
			{
				
				if (s[j] == s[j + 1])
				{
					continue;
				}
				else
				{
					int prev = s[j] - 'a';
					int next = s[j + 1] - 'a';
					if (g[prev].next != -1 || g[next].prev != -1)
						ans = 0;
					g[prev].next = next;
					g[next].prev = prev;
				}
			}
		}
		int f = 0;
		forn(i, 30)
		{
			if (g[i].prev == -1 && (g[i].v != 0 || g[i].next != -1))
				++f;
			if (!g[i].used)
			{
				//if (g[i].prev == -1)
				{
					ans *= dfs(g, i);
					ans %= MODULE;
				}
			}
		}
		ans *= fact(f);
		ans %= MODULE;

		cout << "Case #" << t + 1 << ": ";
		cout << ans;
		cout << "\n";
	}


	return 0;
}