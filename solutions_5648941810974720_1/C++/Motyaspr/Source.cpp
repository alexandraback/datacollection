#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:66777216")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <string>
#include <list>
#include <fstream>
#include <cstring>
#include <climits>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;


#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define for1(i, n) for (int i = 1; i <= (int)n; i++)
#define forq(i, s, t) for (int i = s; i <= t; i++)
#define ford(i, s, t) for (int i = s; i >= t; i--)
#define mk make_pair
#define pk push_back
#define outb pop_back
#define ump unordered_map
#define all(v) v.begin(), v.end()
#define X first
#define Y second
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define randint(x,y)
#define randlong(x, y)
#define TASK ""

const double eps = 1e-15;
const double pi = acos(-1.0);

const int MAXN = (int)1e3 + 7;
const int INF = (ll)2e9;
const ll LINF = 2e18;

int a[30];


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	forn(j, t)
	{
		string s;
		cin >> s;
		vector<int> ans;
		for (int i = 0; i < s.size(); i++)
		{
			a[s[i] - 'A']++;
		}
		if (a['Z' - 'A'] > 0)
		{
			while (a['Z' - 'A'] > 0)
			{
				a['Z' - 'A']--;
				a['E' - 'A']--;
				a['R' - 'A']--;
				a['O' - 'A']--;
				ans.pk(0);
			}

		}
		if (a['X' - 'A'] > 0)
		{
			while (a['X' - 'A'] > 0)
			{
				a['X' - 'A']--;
				a['I' - 'A']--;
				a['S' - 'A']--;
				ans.pk(6);
			}

		}

		if (a['W' - 'A'] > 0)
		{
			while (a['W' - 'A'] > 0)
			{
				a['T' - 'A']--;
				a['W' - 'A']--;
				a['O' - 'A']--;
				ans.pk(2);
			}

		}

		if (a['U' - 'A'] > 0)
		{
			while (a['U' - 'A'] > 0)
			{
				a['F' - 'A']--;
				a['O' - 'A']--;
				a['U' - 'A']--;
				a['R' - 'A']--;
				ans.pk(4);
			}
		}

		if (a['F' - 'A'] > 0)
		{
			while (a['F' - 'A'] > 0)
			{
				a['F' - 'A']--;
				a['I' - 'A']--;
				a['V' - 'A']--;
				a['E' - 'A']--;
				ans.pk(5);
			}

		}

		if (a['V' - 'A'] > 0)
		{
			while (a['V' - 'A'] > 0)
			{
				a['S' - 'A']--;
				a['E' - 'A'] -= 2;
				a['V' - 'A']--;
				a['N' - 'A']--;
				ans.pk(7);
			}

		}

		if (a['G' - 'A'] > 0)
		{
			while (a['G' - 'A'] > 0)
			{
				a['E' - 'A']--;
				a['I' - 'A']--;
				a['G' - 'A']--;
				a['H' - 'A']--;
				a['T' - 'A']--;
				ans.pk(8);
			}
		}

		if (a['T' - 'A'] > 0)
		{
			while (a['T' - 'A'] > 0)
			{
				a['T' - 'A']--;
				a['H' - 'A']--;
				a['R' - 'A']--;
				a['E' - 'A']--;
				a['E' - 'A']--;
				ans.pk(3);
			}
		}

		if (a['O' - 'A'] > 0)
		{
			while (a['O' - 'A'] > 0)
			{
				a['O' - 'A']--;
				a['N' - 'A']--;
				a['E' - 'A']--;
				ans.pk(1);
			}
		}

		if (a['N' - 'A'] > 0)
		{
			while (a['N' - 'A'] > 0)
			{
				a['N' - 'A'] -= 2;
				a['I' - 'A']--;
				a['E' - 'A']--;
				ans.pk(9);
			}
		}
		cout << "CASE #" << j + 1 << ": ";
		sort(all(ans));
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
		cout << "\n";
		ans.clear();

	}
}