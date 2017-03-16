#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int have(string s, string t)
{
	int ans = 0;
	for (int i = 0; i + t.length() - 1 < s.length(); i++)
	{
		if (s.substr(i, t.length()) == t) ans++;
	}
	return ans;
}
int pow(int n, int k)
{
	int ans = 1;
	for (int i = 1; i <= k; i++)
	{
		ans *= n;
	}
	return ans;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int k, l, s;
		string key, t;
		cin >> k >> l >> s >> key >> t;
		int take=0,sum=0;
		for (int i = 0; i < pow(k, s); i++)
		{
			string cur;
			int tmp = i;
			for (int j = 1; j <= s; j++)
			{
				cur += key[tmp%k];
				tmp /= k;
			}
			take = max(take, have(cur, t));
		}
		for (int i = 0; i < pow(k, s); i++)
		{
			string cur;
			int tmp = i;
			for (int j = 1; j <= s; j++)
			{
				cur += key[tmp%k];
				tmp /= k;
			}			
			sum += take - have(cur, t);
		}
		double ans = sum;
		for (int i = 1; i <= s; i++)
		{
			ans = 1.0*ans / k;
		}
		cout.precision(9);
		cout << "Case #"<<tt<<": "<<ans << endl;
	}
}