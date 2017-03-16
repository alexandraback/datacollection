#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
#define ll long long


set <string> has[11];

void preload()
{
	int max_len = 0;
	ifstream in("garbled_email_dictionary.txt");
	string s, t;
	int ss;
	while (in >> s)
	{
		ss = s.size();
		has[ss].insert(s);
		t = s;
		for (int i = 0; i < ss; i++)
		{
			t[i] = '*';
			has[ss].insert(t);
			for (int j = i + 5; j < s.size(); j++)
			{
				t[j] = '*';
				has[ss].insert(t);
				t[j] = s[j];
			}
			t[i] = s[i];
		}
	}
	in.close();
}
const int inf = 100000000;
int was[5000][6];
int dp[5000][6];
int n;
int usd;
string str;

void load()
{
	int c;
	str = "";
	while ((c = getchar()) != 10 && c != EOF)
		str += c;
	cerr << str << endl;
	n = str.size();
}

int f(int i, int j)
{
	if (i == n) return 0;
	if (was[i][j] == usd) return dp[i][j];
	was[i][j] = usd;
	dp[i][j] = inf;
	string tt;
	for (int k = 1; k <= 10 && i + k <= n; k++)
	{
		tt += str[i + k - 1];
		bool ok = false;
		int last_p = n + 1;
		if (has[tt.size()].find(tt) != has[tt.size()].end())
		{
			dp[i][j] = min(dp[i][j], f(i + k, min(4, k + j)));
		}
		for (int l = 4 - j; l < k; l++)
		{
			tt[l] = '*';
			if (has[tt.size()].find(tt) != has[tt.size()].end())
			{
				dp[i][j] = min(dp[i][j], f(i + k, k - l - 1) + 1);
				// ok = true;
				// last_p = min(last_p, l);
			}
			for (int m = l + 5; !ok && m < k; m++)
			{
					tt[m] = '*';
					if (has[tt.size()].find(tt) != has[tt.size()].end())
					{
						dp[i][j] = min(dp[i][j], f(i + k, k - m - 1) + 2);
						// ok = true;
						// last_p = min(last_p, m);
					}
					tt[m] = str[i + m];
			}
			tt[l] = str[i + l];
		}
		// if (ok)
		// 	dp[i][j] |= f(i + k, k - last_p - 1);
	}
	return dp[i][j];
}
void solve(int test_number)
{
	cout << "Case #" << test_number << ": ";
	usd++;
	cout << f(0, 4) << "\n";
}
int main()
{
	preload();
	int t;
	cin >> t;
	int c;
	while ((c=getchar()) != 10 && c != EOF);
	for (int i = 0; i < t; i++)
	{
		load();
		solve(i + 1);
	}
}