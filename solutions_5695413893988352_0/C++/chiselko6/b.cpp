#include <bits/stdc++.h>

#define ll long long
#define __(x) cout << #x << " : " << x << endl;
#define out(a, i, n) for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define INF 1000000000

#define INOUT
#define TIME	

using namespace std;

int cur;

void print(int test, int ans1, int ans2, int n)
{
	string res1 = "", res2 = "";
	while (ans1)
	{
		res1 += (char) '0' + ans1 % 10;
		ans1 /= 10;
	}
	while (ans2)
	{
		res2 += '0' + ans2 % 10;
		ans2 /= 10;
	}
	reverse(res1.begin(), res1.end());
	reverse(res2.begin(), res2.end());

	for (int i = res1.length(); i < n; i++)
	{
		res1 = "0" + res1;
	}
	for (int i = res2.length(); i < n; i++)
	{
		res2 = "0" + res2;
	}
	cout << "Case #" << test << ": " << res1 << " " << res2 << endl;
	//printf("Case #%d: %d\n", test, ans);
}

int next()
{
	return cur++;
}

bool check(int val, string pat)
{
	ll t = 10;
	for (int i = 0; i < pat.length(); i++)
	{
		if (pat[pat.length() - 1 - i] != '?' && val % 10 != pat[pat.length() - 1 - i] - '0')
			return false;
		val /= 10;
	}
	return true;
}

int len(int a)
{
	int ans = 0;
	while (a)
	{
		ans++;
		a /= 10;
	}
	return ans;
}

int main()
{
#ifdef INOUT
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{	
		string team1, team2;
		cin >> team1 >> team2;
		int ans1 = 1000, ans2 = -1000;
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				if (check(i, team1) && check(j, team2) && len(i) <= team1.length() && len(j) <= team2.length())
				{ 
					if (abs(ans1 - ans2) == abs(i - j))
					{
						if (ans1 > i) 
						{
							ans1 = i;
							ans2 = j;
						}
					}
					if (abs(ans1 - ans2) > abs(i - j))
					{
						ans1 = i;
						ans2 = j;
					}
				}
			}
		}
		print(test, ans1, ans2, team1.length());
	}

#ifdef TIME
	cerr << (double) clock() / CLOCKS_PER_SEC;
#endif 
	return 0;
}
