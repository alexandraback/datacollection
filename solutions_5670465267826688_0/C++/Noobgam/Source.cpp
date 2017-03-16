#include <cstdio>
#include <ctime>
#include <cassert>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <random>
#include <set>
using namespace std;
#define mp make_pair

map <string, string> m;
string suff[100000];

string parse(string a, string b)
{
	int a1 = 0;
	if (a[0] == '-')
		a = a.substr(1), a1 = 1 - a1;
	if (b[0] == '-')
		b = b.substr(1), a1 = 1 - a1;
	string q = m[a + b];
	if (q[0] == '-')
		q = q.substr(1), a1 = 1 - a1;
	if (a1)
		q = '-' + q;
	return q;
}

int main()
{
	int t;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	m["11"] = "1";
	m["1i"] = "i";
	m["1j"] = "j";
	m["1k"] = "k";
	m["i1"] = "i";
	m["ii"] = "-1";
	m["ij"] = "k";
	m["ik"] = "-j";
	m["j1"] = "j";
	m["ji"] = "-k";
	m["jj"] = "-1";
	m["jk"] = "i";
	m["k1"] = "k";
	m["ki"] = "j";
	m["kj"] = "-i";
	m["kk"] = "-1";
	for (int test = 1; test <= t; test++)
	{
		cerr << test << endl;
		int n, x;
		string s1;
		cin >> n >> x;
		cin >> s1;
		string s;
		for (int i = 0; i < x; i++) s.append(s1);
		n = n * x;
		if (n < 3)
		{
			printf("Case #%d: NO\n", test);
			continue;
		}
		bool kill = false;
		suff[0] = s[n - 1];
		string empty = "";
		for (int i = 1; i < n; i++)
		{
			empty = "";
			empty.push_back(s[n - i - 1]);
			suff[i] = parse(empty, suff[i - 1]);
		}
		string cur = "";
		cur.push_back(s[0]);
		for (int i = 0; i < n; i++)
		{
			if (i != 0)
			{
				empty = "";
				empty.push_back(s[i]);
				cur = parse(cur, empty);
			}
			string cur2 = "";
			cur2.push_back(s[i + 1]);
			if (cur != "i")
				continue;
			if (kill) break;
			for (int j = i + 1; j < n - 1; j++)
			{
				if (j != i + 1)
				{
					empty = "";
					empty.push_back(s[j]);
					cur2 = parse(cur2, empty);
				}
				if (cur2 != "j")
					continue;
				if (suff[n - j - 2] == "k")
				{
					kill = true;
					printf("Case #%d: YES\n", test);
					break;
				}
			}
		}
		if (!kill)
			printf("Case #%d: NO\n", test);
	}
	system("pause");
	return 0;
}