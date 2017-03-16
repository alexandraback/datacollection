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
	vint nbr;

	int used;
	string index;
	Node()
	{

		used = false;
	}
};


void dfs(vector<Node> & arr, int v, vector<int> & used)
{
	used[v] = 1;
	forn(i, arr[v].nbr.size())
	{
		int to = arr[v].nbr[i];
		if (!used[to] && arr[to].used != 2)
		{
			dfs(arr, to, used);
		}
	}
}

bool av(vector<Node> & arr, int to, int v)
{
	bool f = false;
	forn(i, arr[v].nbr.size())
	{
		if (arr[v].nbr[i] == to)
		{
			f = true;
			break;
		}
	}
	if (!f)
		return false;
	vector<int> used(arr.size(), 0);
	dfs(arr, v, used);
	forn(i, arr.size())
	{
		if (!used[i] && arr[i].used == 0)
			return false;
	}

	return true;


}


bool check(vector<Node> & arr, int v, stack<int> st, int & d)
{
	vector<int> s;
	while (!st.empty())
	{
		s.push_back(st.top());
		st.pop();
	}
	bool good = false;
	forn(i, s.size())
	{
		if (av(arr, v, s[i]))
		{
			d = i;
			good = true;
			break;
			//return true;
		}
		arr[s[i]].used = 2;
	}
	forn(i, s.size())
	{
		arr[s[i]].used = 1;
	}
	return good;
}

i64 nod(i64 a, i64 b)
{
	if (b == 0)
		return a;
	return nod(b, a % b);
}

int main()
{
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

		i64 p, q;
		char c;
		cin >> p >> c >> q;
		if (p > q)
		{
			cout << "Case #" << t + 1 << ": ";
			cout << "impossible";
			cout << "\n";
			continue;
		}
		i64 n = nod(p, q);
		p /= n;
		q /= n;
		i64 pow = 1;
		int i = 0;
		while (pow != q && i < 50)
		{
			pow <<= 1;
			++i;
		}
		if (i == 50)
		{
			cout << "Case #" << t + 1 << ": ";
			cout << "impossible";
			cout << "\n";
			continue;
		}
		p <<= (40 - i);
		q <<= (40 - i);
		i = 0;
		pow = 1;
		while (pow * 2 <= p && i < 50)
		{
			pow <<= 1;
			++i;
		}
		
		cout << "Case #" << t + 1 << ": ";
		cout << 40 - i;
		cout << "\n";
	}


	return 0;
}