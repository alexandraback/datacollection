#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

const int N = 1010;
bool used[N];

string solve()
{
	string s;
	cin >> s;
	string ans = "";
	int n = s.length();
	for (int i = 0; i < n; i++)
		used[i] = false;
	int pos = n;
	for (char c = 'Z'; c >= 'A'; c--)
	{
		for (int i = pos - 1; i >= 0; i--)
		{
			if (s[i] == c)
			{
				ans.push_back(c);
				used[i] = 1;
				pos = i;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (!used[i])
			ans.push_back(s[i]);
	return ans;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		cout << "Case #" << i << ": " << solve() << endl;

	return 0;
}