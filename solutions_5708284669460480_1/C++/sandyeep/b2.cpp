#include <bits/stdc++.h>
using namespace std;
#define int long long

int keyboard[26], n, m, keylen, table[110][26];
double dp[110][110];
string keys, word;

double f(int idx, int matched)	{
	if(idx == n)	{
		return 0;
	}
	double & ret = dp[idx][matched];
	if(ret > -1.0)	{
		return ret;
	}
	ret = 0;
	for(char ch: keys)	{
		bool formed = (matched == m-1 and word[matched] == ch);
		// if(idx >= 2)	cout << formed << " " << matched << " " << table[matched][ch - 'A'] << "\n";
		ret += (f(idx + 1, table[matched][ch - 'A']) + formed);
	}
	ret /= (1.0 * keylen);
	return ret;
}

void pain()	{
	cin >> keylen >> m >> n;
	cin >> keys >> word;
	memset(keyboard, 0, sizeof keyboard);
	for(char c: keys)	{
		keyboard[c - 'A']++;
	}
	for(char ch: word)	{
		if(keyboard[ch - 'A'] < 1)	{
			cout << "0.0000000000\n";
			return;
		}
	}
	for(int i=0; i<110; i++)	{
		for(int j=0; j<110; j++)	{
			dp[i][j] = -2;
		}
	}
	for(int matched = 0; matched < m; matched++)	{
		string temp = "";
		for(int i=0; i<matched; i++)	{
			temp += word[i];
		}
		for(int i=0; i<26; i++)	{
			char ch = 'A' + i;
			string now = temp + ch;
			int ans = 0;
			for(int i = (now == word); i < now.length(); i++)	{
				bool ok = true;
				for(int j=i; j<now.length(); j++)	{
					if(now[j] != word[j - i])	{
						ok = false;
					}
				}
				if(ok)	{
					ans = now.length() - i;
					break;
				}
			}
			table[matched][i] = ans;
		}
	}
	int x = table[m - 1][word[m - 1] - 'A'];
	cout << fixed << setprecision(10) <<  1 + (n - m) / (m - x) - f(0, 0) << "\n";
}

#undef int
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input = "b2i.txt";
	string output = "b2o.txt";
	freopen(input.c_str(), "r", stdin);
	freopen(output.c_str(), "w", stdout);
	int tt; cin >> tt;
	for(int iii=1; iii<=tt; iii++)	{
		cout << "Case #" << iii << ": ";
		pain();
	}
}

