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

int perev(string s)
{
	int cop = 0;
	reverse(all(s));
	while (s[s.size() - 1] == '0')
	{
		s.pop_back();
		if (s.size() == 0)
			return 0;
	}
	reverse(all(s));
	for (int i = 0; i < s.size(); i++)
		cop = cop * 10 + s[i] - '0';
	return cop;

}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	forn(qq, t)
	{
		string s, j;
		cin >> s >> j;
		string sl = s + j;
		vector<int> kal;
		for (int i = 0; i < sl.size(); i++)
			if (sl[i] == '?')
				kal.pk(i);
		string ans1 = "1000000";
		string ans2 = "0";
		if (kal.size() == 1)
		{
			for (int a = 0; a <= 9; a++)
			{
				sl[kal[0]] = char('0' + a);
				string one = "";
				string two = "";
				for (int i = 0; i < s.size(); i++)
					one += sl[i];
				for (int i = 0; i < s.size(); i++)
					two += sl[i + s.size()];
				if (abs(perev(one) - perev(two)) < abs(perev(ans1) - perev(ans2)))
				{
					ans1 = one;
					ans2 = two;
				}
			}
		}
		if (kal.size() == 2)
		{
			for (int a = 0; a <= 9; a++)
				for (int b = 0; b <= 9; b++)
				{
					sl[kal[0]] = char('0' + a);
					sl[kal[1]] = char('0' + b);
					string one = "";
					string two = "";
					for (int i = 0; i < s.size(); i++)
						one += sl[i];
					for (int i = 0; i < s.size(); i++)
						two += sl[i + s.size()];
					if (abs(perev(one) - perev(two)) < abs(perev(ans1) - perev(ans2)))
					{
						ans1 = one;
						ans2 = two;
					}
				}

		}
		if (kal.size() == 3)
		{
			for (int a = 0; a <= 9; a++)
				for (int b = 0; b <= 9; b++)
					for (int c = 0; c <= 9; c++)
					{
						sl[kal[0]] = char('0' + a);
						sl[kal[1]] = char('0' + b);
						sl[kal[2]] = char('0' + c);
						string one = "";
						string two = "";
						for (int i = 0; i < s.size(); i++)
							one += sl[i];
						for (int i = 0; i < s.size(); i++)
							two += sl[i + s.size()];
						if (abs(perev(one) - perev(two)) < abs(perev(ans1) - perev(ans2)))
						{
							ans1 = one;
							ans2 = two;
						}
					}

		}
		if (kal.size() == 4)
		{
			for (int a = 0; a <= 9; a++)
				for (int b = 0; b <= 9; b++)
					for (int c = 0; c <= 9; c++)
						for (int d = 0; d <= 9; d++)
						{
							sl[kal[0]] = char('0' + a);
							sl[kal[1]] = char('0' + b);
							sl[kal[2]] = char('0' + c);
							sl[kal[3]] = char('0' + d);
							string one = "";
							string two = "";
							for (int i = 0; i < s.size(); i++)
								one += sl[i];
							for (int i = 0; i < s.size(); i++)
								two += sl[i + s.size()];
							if (abs(perev(one) - perev(two)) < abs(perev(ans1) - perev(ans2)))
							{
								ans1 = one;
								ans2 = two;
							}
						}

		}

		if (kal.size() == 5)
		{
			for (int a = 0; a <= 9; a++)
				for (int b = 0; b <= 9; b++)
					for (int c = 0; c <= 9; c++)
						for (int d = 0; d <= 9; d++)
							for (int e = 0; e <= 9; e++)
							{
								sl[kal[0]] = char('0' + a);
								sl[kal[1]] = char('0' + b);
								sl[kal[2]] = char('0' + c);
								sl[kal[3]] = char('0' + d);
								sl[kal[4]] = char('0' + e);
								string one = "";
								string two = "";
								for (int i = 0; i < s.size(); i++)
									one += sl[i];
								for (int i = 0; i < s.size(); i++)
									two += sl[i + s.size()];
								if (abs(perev(one) - perev(two)) < abs(perev(ans1) - perev(ans2)))
								{
									ans1 = one;
									ans2 = two;
								}
							}

		}

		if (kal.size() == 6)
		{
			for (int a = 0; a <= 9; a++)
				for (int b = 0; b <= 9; b++)
					for (int c = 0; c <= 9; c++)
						for (int d = 0; d <= 9; d++)
							for (int e = 0; e <= 9; e++)
								for (int f = 0; f <= 9; f++)
								{
									sl[kal[0]] = char('0' + a);
									sl[kal[1]] = char('0' + b);
									sl[kal[2]] = char('0' + c);
									sl[kal[3]] = char('0' + d);
									sl[kal[4]] = char('0' + e);
									sl[kal[5]] = char('0' + f);
									string one = "";
									string two = "";
									for (int i = 0; i < s.size(); i++)
										one += sl[i];
									for (int i = 0; i < s.size(); i++)
										two += sl[i + s.size()];
									if (abs(perev(one) - perev(two)) < abs(perev(ans1) - perev(ans2)))
									{
										ans1 = one;
										ans2 = two;
									}
								}

		}
		cout << "Case #" << qq + 1 << ": " << ans1 << ' ' << ans2 << "\n";
	}
}