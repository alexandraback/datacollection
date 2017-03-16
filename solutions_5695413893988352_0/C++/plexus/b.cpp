#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define INF (1 << 30)
#define SQR(a) ((a) * (a))

using namespace std;

const int N = 1111;

string solve(string s1, string s2)
{
	string res1, res2;
	int cmp = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == s2[i] && s2[i] != '?')
		{
			res1 += s1[i];
			res2 += s2[i];	
		}
		else if (s1[i] == '?' && s2[i] != '?')
		{
			if (cmp == 0)
			{
				res1 += s2[i];
				res2 += s2[i];
			}
			else if (cmp == 1)
			{
				res1 += '0';
				res2 += s2[i];
			}
			else if (cmp == -1)
			{
				res1 += '9';
				res2 += s2[i];
			}
		}
		else if (s1[i] != '?' && s2[i] == '?')
		{
			if (cmp == 0)
			{
				res1 += s1[i];
				res2 += s1[i];
			}
			else if (cmp == 1)
			{
				res1 += s1[i];
				res2 += '9';
			}
			else if (cmp == -1)
			{
				res1 += s1[i];
				res2 += '0';
			}
		}
		else if (s1[i] == '?' && s2[i] == '?')
		{
			if (cmp == 0)
			{
				res1 += '0';
				res2 += '0';
			}
		       	else if (cmp == 1)
			{
				res1 += '0';
				res2 += '9';
			}
			else if (cmp == -1)
			{
				res1 += '9';
				res2 += '0';
			}
		} else if (s1[i] != '?' && s2[i] != '?')
		{
			res1 += s1[i];
			res2 += s2[i];
			if (s1[i] > s2[i])
				cmp = 1;
			else if (s1[i] < s2[i])
				cmp = -1;
		}
	}
	return res1 + " " + res2;
}

string tostr(int i, string f)
{
	char s[100];
	sprintf(s, "%d", i);
	string res = s;
	while (res.size() < f.size())
		res = "0" + res;
	return res;
}

bool fits(int a, string b)
{
	string s = tostr(a, b);
	if (s.size() != b.size())
		return false;

	for (int i = 0; i < b.size(); i++)
		if (b[i] != '?' && b[i] != s[i])
			return false;
	return true;
}

string naiveSolve(string s1, string s2)
{
	int cur = INF, a, b;
	int k = 1;
	for (int i = 0; i < s1.size(); i++)
		k *= 10;
	
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (fits(i, s1) && fits(j, s2) && cur > abs(i - j))
			{
				cur = abs(i - j);
				a = i;
				b = j;
			}
		}
	}
	return tostr(a, s1) + " " + tostr(b, s2);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out", "w", stdout);

	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		string c, j;	
		cin >> c >> j;
		cout << "Case #" << i + 1 << ": " << flush; 
		cout << naiveSolve(c, j) << endl;
	}

	fprintf(stderr, "\n\n Execution time: %.4fs", double(clock()) / CLOCKS_PER_SEC);
	return 0;
}

