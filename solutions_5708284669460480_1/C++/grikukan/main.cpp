#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
double letprob[257];
int calcbestlen(string& s)
{
	int bestlen = 0;
	for (int goodlen = 1; goodlen < s.length(); goodlen++)
	{
		bool ok = true;
		int diff = s.length() - goodlen;
		for (int i = 0; i < s.length(); i++)
		{
			if (i + diff < s.length() && s[i] != s[i + diff]) ok = false;
		}
		if (ok)
		{
			bestlen = goodlen;
		}
	}
	return bestlen;
}
int maxAppear(string& s, int len)
{
	int bestlen = calcbestlen(s);	
	if (len < s.length()) return 0;
	return 1 + (len - s.length()) / (s.length() - bestlen);
}
double dp[107][107][307];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;	
	for (int tt = 1; tt <= t; tt++)
	{
		int k, l, s;
		cin >> k >> l >> s;
		string key, text;
		cin >> key >> text;
		for (int i = 'A'; i <= 'Z'; i++)
		{
			int have = 0;
			for (int j = 0; j < key.size(); j++)
			{
				if (key[j] == i) have++;
			}
			double cur = have;
			cur = 1.0*cur / key.length();
			letprob[i] = cur;
		}		
		for (int i = 0; i < 107; i++)
		{
			for (int j = 0; j < 107; j++)
			{
				for (int k = 0; k < 307; k++)
				{
					dp[i][j][k] = 0;
				}
			}
		}
		int maxpos = maxAppear(text, s);	
		int bestlen = calcbestlen(text);
		for (int i = 0; i < text.length(); i++)
		{
			bool ok = false;
			for (int j = 0; j < key.length(); j++)
			{
				if (text[i] == key[j]) ok = true;
			}
			if (!ok)
			{
				maxpos = 0;
			}
		}
		dp[0][0][0] = 1;
		for (int i = 0; i < s;i++)
		{
			for (int j = 0; j < text.length(); j++)
			{
				for (int k = 0; k <= maxpos; k++)
				{										
					if (j + 1 == text.length())
					{
						dp[i + 1][bestlen][k + 1] += 1.0*dp[i][j][k] * letprob[text[j]];

					}
					else
					{
						dp[i + 1][j + 1][k] += 1.0*dp[i][j][k] * letprob[text[j]];
					}
					dp[i + 1][0][k] += 1.0 * dp[i][j][k] * 1.0*(1 - letprob[text[j]]);
				}
			}
		}
		double firstans = 0;
		for (int j = 0; j < text.length(); j++)
		{
			for (int k = 0; k <= maxpos; k++)
			{
				firstans += 1.0 * dp[s][j][k] * k;
			}
		}
		double ans = maxpos - firstans;
		cout.precision(9);
		cerr << tt << endl;
		cout <<"Case #"<<tt<<": "<< fixed << ans << endl;
	}
}