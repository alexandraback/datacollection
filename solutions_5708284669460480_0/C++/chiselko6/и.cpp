#include <bits/stdc++.h>

#define ll long long
#define __(x) cout << #x << " : " << x << endl;
#define out(a, i, n) for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

#define INOUT
#define TIME	

using namespace std;

void print(int test, double ans)
{
	//cout << "Case #" << test << ": " << ans << endl;
	printf("Case #%d: %.9f\n", test, ans);
}

int alph[30];

bool check(string s1, string s2)
{
	for (int i = 0; i < s2.length(); i++)
	{
		bool f = false;
		for (int j = 0; j < s1.length(); j++)
			if (s1[j] == s2[i])
				f = true;
		if (!f)
			return false;
	}
	return true;
}

ll getC(int n, int k)
{
	ll res = 1;
	if (k > n - k) k = n - k;
	for (int i = n - k + 1; i <= n; i++)
		res *= i;
	for (int i = 1; i <= k; i++)
		res /= i;
	return res;
}

void calc(string s)
{
	for (int i = 0; i < 30; i++)
		alph[i] = 0;
	for (int i = 0; i < s.length(); i++)
		alph[s[i] - 'A' + 1]++;
}

double getP(string s1, string s2)
{
	calc(s1);
	double p = 1;
	for (int i = 0; i < s2.length(); i++)
		p *= (double) alph[s2[i] - 'A' + 1] / s1.length();
	return p;
}

int getMin(string s1, int s)
{
	bool f = false;
	for (int i = 0; i < s1.length(); i++)
		if (s1[i] != s1[0]) f = true;
	if (f)
		return s / s1.length();
	return s - s1.length() + 1;
}

int main()
{
#ifdef INOUT
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	
	int tests;
	cin >> tests;
	ll ans = 0;
	for (int test = 1; test <= tests; test++)
	{
		int k, l, s;
		cin >> k >> l >> s;
		string sK, sL;
		cin >> sK >> sL;
		//cout << endl << sK << endl << sL << endl;
		int minBan = getMin(sL, s);
		double ans = 0;
		if (!check(sK, sL))
		{
			print(test, 0.0);
			continue;
		}
		else
		{
			double p = getP(sK, sL);
			//out(alph, i, 30);
			int t = 1;
			int size = s / l;
			for (int i = 1; i <= size; i++)
			{
				ans += pow(p, i) * getC(s - i * l + i, i) * pow((1 - p), size - i) * i;
				//cout << ans << " ";
			}
		}
		print(test, (double) ((double) (minBan) - ans));
	}

#ifdef TIME
	//cout << (double) clock() / CLOCKS_PER_SEC;
#endif 
	return 0;
}
