#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <cstdio>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int k, l, s;
string word;
vector <char> q;
string current;
long double sum = 0;
long double mx = 0;

void generate()
{
	if (current.length() == s)
	{
		long double cur = 0;
		for (int i = 0; i <= s - l; i++)
			for (int j = 0; j < l; j++)
			{
				if (current[i + j] != word[j]) break;
				if (j == l - 1)
					cur++;
			}
		sum += cur;
		mx = max(cur, mx);
		return;
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			current.push_back(q[i]);
			generate();
			current.pop_back();
		}
	}
}

int main()
{
	int t;
	::ios_base::sync_with_stdio(false);
	cin.tie(false);
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cerr << i << endl;
		mx = 0;
		sum = 0;
		cin >> k >> l >> s;
		q.resize(k);
		for (int i = 0; i < k; i++)
			cin >> q[i];
		cin >> word;
		generate();
		long double q1 = 1;
		for (int i = 0; i < s; i++)
			q1 = q1 * k;
		long double q2 = q1;
		long double result = (q1 * mx - sum) / q2;
		printf("CASE #%d: %Lf\n", i, result);
	}
	return 0;
}	