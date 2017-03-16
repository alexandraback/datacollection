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
		int first[26], middle[26], last[26];
		int n;
		cin >> n;
		vector<string> arr(n);
		i64 ans = 0;
		forn(i, n)
		{
			string s;
			cin >> arr[i];
			arr[i] = clear(arr[i]);
			/*int l = s.length;
			forn(j, l - 1)
			{
				if (s[j] == s[j + 1])
				{
					continue;
				}
				else
				{
					last[s[j] - 'a'] ++;
					first[s[j + 1] - 'a']++;
				}
			}*/
		}
		vector<int> p(n, 0);
		forn(i, n)
		{
			p[i] = i;
		}
		do
		{
			ans += check(arr, p);
		}
		while (next_permutation(p.begin(), p.end()));

		cout << "Case #" << t + 1 << ": ";
		cout << ans;
		cout << "\n";
	}


	return 0;
}