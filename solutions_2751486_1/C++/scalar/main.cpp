#include <iostream>
#include <string>
#include <algorithm>
#include <boost\algorithm\string.hpp>
using namespace std;

long long solve(const string &str, int n)
{
	long long int res = 0;
	auto f = boost::is_any_of("aeiou");
	int cur = 0, last = -1;
	for(int i = 0; i < str.length(); i++)
	{
		if(!f(str[i])) cur++;
		else cur = 0;
		if(cur == n)
		{
			res += (i - n - last + 1) * 1ll * (str.length() - i);
			last = i - n + 1;
			cur--;
		}
	}
	return res;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		string str;
		int n;
		cin >> str >> n;
		cout << "Case #" << i + 1 << ": " << solve(str, n) << endl;
	}
	fclose(stdout);
}
