#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <memory.h>


using namespace std;

int pref(string s)
{
	int L = s.size();
	int z = 0;
	for (int i = 1; i < L; i++)
	{
		bool ok = true;
		for (int j = 0; j < i; j++)
			if (s[j]!= s[L - i + j])
				ok = false;
		if (ok)
			z = i;
	}
	return z;
}

string sub(string s, int cnt)
{
	string res = "";
	for (int i = 0; i < cnt; i++)
		res += s[i];
	return res;
}

#define MAX 109


int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	cin >> T; 
	for (int t = 0; t < T; t++)
	{
		int K, L, S;
		cin >> K >> L >> S;
		string kb, word;
		cin >> kb >> word;
		bool f = true;
		for (int i = 0; i < L; i++)
		{
			bool p = false;
			for (int j = 0; j < K; j++)
				if (kb[j] == word[i])
					p = true;
			if (!p)
			{
				f = false;
				break;
			}
		}
		double res = 0;
		if (f)
		{
			double required;
			double expected = 0;
			int z = pref(word);
			required = 1 + (S - L) / (L - z);

			int prefs[MAX];
			string subs[MAX];
			subs[0] = "";
			subs[L] = word;
			prefs[0] = 0;
			for (int i = 1; i <= L; i++)
			{
				string s = sub(word, i);
				subs[i] = s;
				prefs[i] = pref(s);
			}

			map<string, int> mp;
			for (int i = 0; i <= L; i++)
			{
				for (char c = 'A'; c <= 'Z'; c++)
				{
					string s = subs[i] + c;
					mp[s] = pref(s);
				}
			}

			double mas[MAX][MAX];
			for (int i = 0; i < MAX; i++)
				for (int j = 0; j < MAX; j++)
					mas[i][j] = 0;
			mas[0][0] = 1;
			double p = 1.0 / K;
			for (int s = 0; s < S;s++)
			{
				for (int k = 0; k < K; k++)
				{
					char c = kb[k];
					
					for (int i = 0; i < L - 1; i++)
					{
						if (word[i] == c)
							mas[s+1][i+1] += mas[s][i] * p;
						else
						{
							string q = subs[i] + c;
							int pre = mp[q];
							mas[s+1][pre] += mas[s][i] * p;
						}
					}
					if (word[L-1] == c)
					{
						expected += mas[s][L-1] * p;
						mas[s+1][prefs[L]] += mas[s][L-1] * p;
					}
					else
					{
						string q = subs[L-1] + c;
						int pre = mp[q];
						mas[s+1][pre] += mas[s][L-1] * p;
					}
				}
			}
			res = required - expected;
		}
		printf("Case #%d: %.7lf\n", t+1, res);
	}
	return 0;
}