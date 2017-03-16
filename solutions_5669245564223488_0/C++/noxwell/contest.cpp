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

pair<string, int> s[1000];

int get_ans(int n)
{
	sort(s, s + n);
	string ts;
	bool en[30], flag;
	int res = 0;
	do
	{
		ts = "";
		for (int i = 0; i < n; i++)
		{
			ts += s[i].first;
		}
		memset(en, 0, sizeof en);
		flag = true;
		for (int i = 1; i < ts.size(); i++)
		{
			if (ts[i] != ts[i - 1])
			{
				en[ts[i - 1] - 'a'] = 1;
				if (en[ts[i] - 'a'])
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
			res++;
	} while (next_permutation(s, s + n));
	return res;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	int n;
	string ts;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cout << "Case #" << tt + 1 << ": ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> ts;
			s[i] = mp(ts, i);
		}
		cout << get_ans(n);
		cout << endl;
	}
	return 0;
}