#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <sstream>
#include <algorithm>

#define INF 2e9
#define mp make_pair
#define pb push_back

using namespace std;

int get_ans(long long p, long long q)
{
	long long a = (1LL << 40);
	if ((a * p % q) != 0) return -1;
	long long b = a * p / q;
	int res = 40;
	while (b)
	{
		res--;
		b >>= 1;
	}
	return res + 1;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t, ans;
	int p, q;
	cin >> t;
	string ts;
	getline(cin, ts);
	for (int tt = 0; tt < t; tt++)
	{
		cout << "Case #" << tt + 1 << ": ";
		getline(cin, ts);
		for (int i = 0; i < ts.size(); i++)
		{
			if (ts[i] == '/') ts[i] = ' ';
		}
		stringstream ss(ts);
		ss >> p >> q;
		ans = get_ans(p, q);
		if (ans == -1)
		{
			cout << "impossible";
		}
		else
		{
			cout << ans;
		}
		cout << endl;
	}
	return 0;
}