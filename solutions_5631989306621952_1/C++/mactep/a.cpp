#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solve()
{
	string s;
	cin >> s;
	string res;
	for (int i = 0, n = s.length(); i < n; ++i)
	{
		string curr = s.substr(i, 1);
		string s1 = res + curr;
		string s2 = curr + res;
		res = max(s1, s2);
	}
	return res;
}

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		string res = solve();
		cout << "Case #" << i + 1 << ": ";
		cout << res << endl;
	}
	return 0;
}
