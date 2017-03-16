#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
using namespace std;

const int inf = 1e9;
int dp[5000][6];
set<string> dict;

int change1(string w, int st)
{
	if (st > 0)
		st--;
	for (int i = st; i < w.size(); i++)
	{
		char was = w[i];
		
		for (char c = 'a'; c < 'z'; c++)
		{
			w[i] = c;
			if (dict.find(w) != dict.end())
				return i;
		}

		w[i] = was;
	}
	return -1;
}

int change2(string w, int st)
{

	for (int i = st + 1; i < w.size(); i++)
	{
		char wasi = w[i];		
		for (char c = 'a'; c <= 'z'; c++)
		{
			w[i] = c;
			
			for (int j = st; j + 4 < i; j++)
			{
				char wasj = w[j];
				for (char q = 'a'; q <= 'z'; q++)
				{
					w[j] = q;
					if (dict.find(w) != dict.end())
						return i;
				}
				w[j] = wasj;
			}
		}

		w[i] = wasi;
	}
	return -1;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	#endif

	int dictsz = 521196;
	//dictsz = 3;

	for (int i = 0; i < dictsz; i++)
	{
		string t;
		cin >> t;
		dict.insert(t);
	}


	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string s;
		cin >> s;
		int n = s.size();		
		dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = dp[0][5] = 0;

		for (int i = 1; i <= n; i++)
			for (int p = 0; p < 6; p++)
				dp[i][p] = inf;

		for (int i = 0; i < n; i++)
		{
			for (int p = 4; p >= 0; p--)
				dp[i][p] = min(dp[i][p], dp[i][p + 1]);

			for (int change = 0; change < 6; change++)
				for (int lw = 1; lw <= 10; lw++)
				{
					string word = s.substr(i, lw);
					if (dict.find(word) != dict.end())
					{
						int d = min(5, change + (int)word.size());
						dp[i + lw][d] = min(dp[i + lw][d], dp[i][change]);
						continue;
					}

					int d = change1(word, 5 - change);
					if (d != -1)
					{
						d = word.size() - d - 1;
						dp[i + lw][d] = min(dp[i + lw][d], dp[i][change] + 1);
					}

					d = change2(word, 5 - change);
					if (d != -1)
					{
						d = word.size() - d - 1;
						dp[i + lw][d] = min(dp[i + lw][d], dp[i][change] + 2);
					}
				}
		}

		for (int p = 4; p >= 0; p--)
			dp[n][p] = min(dp[n][p], dp[n][p + 1]);			

		cout << "Case #" << t + 1 << ": ";
		cout << dp[n][0];		
		cout << endl;
	}
}
































