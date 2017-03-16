#include <bits/stdc++.h>
using namespace std;

string s;
int tt;
int c[100];
int rs[20];

int main()
{
	string a[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> tt;
	for(int t = 1; t <= tt; t++)
	{
		cin >> s;
		memset(c, 0, sizeof c);
		memset(rs, 0, sizeof rs);
		int n = s.length();
		for(int i = 0; i < n; i++)
			c[s[i] - 'A']++;
		if(c['Z'-'A'] > 0)
		{
			int u = 0;
			int d = c['Z' - 'A'];
			for(int i = 0; i < a[u].length(); i++) c[a[u][i]-'A']-= d;
			rs[u] += d;
		}
		if(c['W'-'A'] > 0)
		{
			int u = 2;
			int d = c['W' - 'A'];
			for(int i = 0; i < a[u].length(); i++) c[a[u][i]-'A']-= d;
			rs[u] += d;
		}
		if(c['U'-'A'] > 0)
		{
			int u = 4;
			int d = c['U' - 'A'];
			for(int i = 0; i < a[u].length(); i++) c[a[u][i]-'A']-= d;
			rs[u] += d;
		}
		if(c['X'-'A'] > 0)
		{
			int u = 6;
			int d = c['X' - 'A'];
			for(int i = 0; i < a[u].length(); i++) c[a[u][i]-'A']-= d;
			rs[u] += d;
		}
		if(c['G'-'A'] > 0)
		{
			int u = 8;
			int d = c['G' - 'A'];
			for(int i = 0; i < a[u].length(); i++) c[a[u][i]-'A']-= d;
			rs[u] += d;
		}
		if(c['O'-'A'] > 0)
		{
			int u = 1;
			int d = c['O' - 'A'];
			for(int i = 0; i < a[u].length(); i++) c[a[u][i]-'A']-= d;
			rs[u] += d;
		}
		if(c['R'-'A'] > 0)
		{
			int u = 3;
			int d = c['R' - 'A'];
			for(int i = 0; i < a[u].length(); i++) c[a[u][i]-'A']-= d;
			rs[u] += d;
		}
		if(c['F'-'A'] > 0)
		{
			int u = 5;
			int d = c['F' - 'A'];
			for(int i = 0; i < a[u].length(); i++) c[a[u][i]-'A']-= d;
			rs[u] += d;
		}
		if(c['S'-'A'] > 0)
		{
			int u = 7;
			int d = c['S' - 'A'];
			for(int i = 0; i < a[u].length(); i++) c[a[u][i]-'A']-= d;
			rs[u] += d;
		}
		if(c['I'-'A'] > 0)
		{
			int u = 9;
			int d = c['I' - 'A'];
			for(int i = 0; i < a[u].length(); i++) c[a[u][i]-'A']-= d;
			rs[u] += d;
		}
		cout << "Case #" << t << ": ";
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < rs[i]; j++) cout << i;
		cout << "\n";
	}
	return 0;
}