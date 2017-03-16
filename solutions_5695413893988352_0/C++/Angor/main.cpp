#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

long long stringToNum(string s)
{
	long long ans = 0;
	for (int i = 0; i < s.length(); i++)
	{
		long long d = (s[i] - '0');
		ans = ans * 10 + d;
	}

	return ans;
}

tuple<long long, string, string> getVar(string first, string second)
{
	long long d1 = stringToNum(first);
	long long d2 = stringToNum(second);
	long long diff = abs(d1 - d2);

	return make_tuple(diff, first, second);
}

tuple<long long, string, string> solve(string first, string second, int start, bool tryMaxFirst)
{
	int n = first.length();
	string first_var = first;
	string second_var = second;
	for (int i = start; i <= n; i++)
	{
		if (first_var[i] == '?')
		{
			if (tryMaxFirst)
			{
				first_var[i] = '9';
			}
			else
			{
				first_var[i] = '0';
			}
		}
		if (second_var[i] == '?')
		{
			if (tryMaxFirst)
			{
				second_var[i] = '0';
			}
			else
			{
				second_var[i] = '9';
			}
		}
	}

	tuple<long long, string, string> ans = getVar(first_var, second_var);
	return ans;
}

int main()
{
	cin.sync_with_stdio(0);
	freopen( "..\\input.txt", "r", stdin );
	freopen( "..\\output.txt", "w", stdout );

	int t;
	cin >> t;
	for( int tt = 1; tt <= t; tt++ )
	{
		tuple<long long, string, string> ans;
		bool hasAns = false;

		string first;
		string second;
		cin >> first >> second;
		int n = first.length();

		for (int pref = 0; pref <= n; pref++)
		{
			bool isEq = true;
			string first_var = first;
			string second_var = second;
			for (int i = 0; i < pref; i++)
			{
				if (first_var[i] == '?' && second_var[i] == '?')
				{
					first_var[i] = '0';
					second_var[i] = '0';
					continue;
				}

				if (first_var[i] == '?')
				{
					first_var[i] = second_var[i];
				}

				if (second_var[i] == '?')
				{
					second_var[i] = first_var[i];
				}

				if (first_var[i] != second_var[i])
				{
					isEq = false;
					break;
				}
			}

			if (!isEq)
			{
				continue;
			}

			if (pref == n)
			{
				ans = getVar(first_var, second_var);
				hasAns = true;
				continue;
			}

			if (first_var[pref] == '?' && second_var[pref] == '?')
			{
				first_var[pref] = '0';
				second_var[pref] = '1';
				tuple<long long, string, string> ans1 = solve(first_var, second_var, pref, true);
				if (!hasAns || ans1 < ans)
				{
					ans = ans1;
					hasAns = true;
				}

				first_var[pref] = '1';
				second_var[pref] = '0';
				tuple<long long, string, string> ans2 = solve(first_var, second_var, pref, false);
				if (!hasAns || ans2 < ans)
				{
					ans = ans2;
					hasAns = true;
				}

				continue;
			}

			if (first_var[pref] == '?')
			{
				if (second_var[pref] > '0')
				{
					first_var[pref] = second_var[pref] - 1;
					tuple<long long, string, string> ans1 = solve(first_var, second_var, pref, true);
					if (!hasAns || ans1 < ans)
					{
						ans = ans1;
						hasAns = true;
					}
				}

				if (second_var[pref] < '9')
				{
					first_var[pref] = second_var[pref] + 1;
					tuple<long long, string, string> ans1 = solve(first_var, second_var, pref, false);
					if (!hasAns || ans1 < ans)
					{
						ans = ans1;
						hasAns = true;
					}
				}

				continue;
			}

			if (second_var[pref] == '?')
			{
				if (first_var[pref] > '0')
				{
					second_var[pref] = first_var[pref] - 1;
					tuple<long long, string, string> ans1 = solve(first_var, second_var, pref, false);
					if (!hasAns || ans1 < ans)
					{
						ans = ans1;
						hasAns = true;
					}
				}

				if (first_var[pref] < '9')
				{
					second_var[pref] = first_var[pref] + 1;
					tuple<long long, string, string> ans1 = solve(first_var, second_var, pref, true);
					if (!hasAns || ans1 < ans)
					{
						ans = ans1;
						hasAns = true;
					}
				}

				continue;
			}

			if (first_var[pref] == second_var[pref])
			{
				continue;
			}
			if (first_var[pref] > second_var[pref])
			{
				tuple<long long, string, string> ans1 = solve(first_var, second_var, pref, false);
				if (!hasAns || ans1 < ans)
				{
					ans = ans1;
					hasAns = true;
				}
			}
			else
			{
				tuple<long long, string, string> ans1 = solve(first_var, second_var, pref, true);
				if (!hasAns || ans1 < ans)
				{
					ans = ans1;
					hasAns = true;
				}
			}
		}

		//printf( "Case #%d: ", tt );
		cout << "Case #" << tt << ": " << get<1>(ans) << " " << get<2>(ans) << endl;
	}
	return 0;
}