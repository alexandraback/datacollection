#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ifstream fin("in.in");
ofstream fout("out.txt");

int main()
{
	int t;
	fin >> t;
	for (int i = 0; i < t; i++)
	{
		string s;
		fin >> s;
		int ans = 0;
		for (int i = 0; i < s.length() - 1; i++)
		{
			if (s[i] != s[i + 1])
				ans++;
		}
		if (s[s.length() - 1] == '-')
			ans++;
		fout << "Case #" << i + 1 << ": " << ans << "\n";
	}
	return 0;
}
