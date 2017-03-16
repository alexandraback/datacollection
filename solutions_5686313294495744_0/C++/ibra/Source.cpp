#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cassert>
#include <set>
#include <ctime>
#include <stack>
#include <cstring>
#include <fstream>
#include<functional>
#include <sstream>
#include <ctype.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<int> res;

void go(map<char, int> &mp, string digit, char c, int num)
{
	int cnt = mp[c];

	for (int i = 0; i < cnt; i++)
		res.push_back(num);

	for (int i = 0; i < digit.size(); i++)
	{
		mp[digit[i]] -= cnt;
	}
}

int main()
{
	freopen("C:\\Users\\ibismail\\Downloads\\C-small-attempt0.in", "r", stdin);
	freopen("C:\\Users\\ibismail\\Downloads\\codejam\\out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int test = 1; test <= t; test++)
	{
		int n;
		scanf("%d", &n);

		vector<pair<string, string> > v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;

		int res = 0;
		for (int mask = 0; mask < (1 << n); mask++)
		{
			int c = 0;
			for (int i = 0; i < n; i++)
			if (mask&(1 << i))
				c++;

			//'1' are fakes

			set<string> firs, secs;
			for (int i = 0; i < n; i++)
			{
				if (!(mask&(1 << i)))
				{
					firs.insert(v[i].first);
					secs.insert(v[i].second);
				}
			}

			bool ok = true;
			for (int i = 0; i < n; i++)
			{
				if (mask&(1 << i))
				{
					if (firs.count(v[i].first) == 0 || secs.count(v[i].second) == 0)
					{
						ok = false;
						break;
					}
				}
			}

			if (ok)
				res = max(res, c);


		}

		cout << "Case #" << test << ": " << res << endl;
	}

	


	return 0;
}