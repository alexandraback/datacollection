#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1000 * 1000 * 1000 + 7;
bool check(const vector<int>& p, const vector<string>& vs)
{
	string s;
	char c;
	vector<int> was(int('a') + 26, 0);
	for (int i = 0; i < p.size(); ++i)
		s += vs[p[i]];
	for (int i = 0; i < s.size(); ++i)
	{
		if (i != 0)
		{
			if (s[i] != c && was[s[i]])
				return false;
		}
		was[s[i]] = 1;
		c = s[i];
	}
	return true;
}

void solve()
{
	ll ans = 0;
	vector<int> p;
	vector<string> s;
	int n;

	cin >> n;
	s.resize(n);
	for (int i = 0; i < n; ++i)
	{
		string tmp, res;
		cin >> tmp;
		for (int j = 0; j < tmp.size(); ++j)
		{
			if (j == 0 || tmp[j] != tmp[j-1])
				res += tmp[j];
		}
		s[i] = res;
	}
	for (int i = 0; i < n; ++i)
		p.push_back(i);

	ans += check(p, s);
	while(next_permutation(p.begin(), p.end()))
		ans += check(p, s);
	cout << ans << endl;
}

int main()
{
	int t;
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}	
	return 0;
}