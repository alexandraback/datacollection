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
int sufpos = -1;
int prefpos = 1;

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
		prefpos = -1;
		sufpos = -1;
		cerr << test << endl;
		int n;
		long long x;
		cin >> n >> x;
		string s;
		cin >> s;
		string total;
		total.push_back(s[0]);
		for (int i = 1; i < n; i++)
		{
			string empty = "";
			empty.push_back(s[i]);
			total = parse(total, empty);
		}
		if (total == "1")
		{
			printf("Case #%d: NO\n", test);
			continue;
		}
		if (total == "-1" && ((x % 2) == 0))
		{
			printf("Case #%d: NO\n", test);
			continue;
		}
		if (total != "1" && total != "-1" && (x % 4) != 2)
		{
			printf("Case #%d: NO\n", test);
			continue;
		}
		bool kill = false;
		string empty = "";
		string cur;
		cur.push_back(s[n - 1]);
		if (cur == "k")
			sufpos = 0;
		for (int i = 1; i < n * x && i < n * 8; i++)
		{
			if (sufpos != -1)
				break;
			empty = "";
			empty.push_back(s[((-i - 1) % n + n) % n]);
			cur = parse(empty, cur);
			if (cur == "k")
				sufpos = i;
		}
		cur = "";
		cur.push_back(s[0]);
		prefpos = -1;
		if (cur == "i")
			prefpos = 0;
		for (int i = 1; i < n * x && i < n * 8; i++)
		{
			if (prefpos != -1)
				break;
			empty = "";
			empty.push_back(s[i % n]);
			cur = parse(cur, empty);
			if (cur == "i")
				prefpos = i;
		}
		if (prefpos == -1 || sufpos == -1)
			printf("Case #%d: NO\n", test);
		else if ((prefpos + 1) + (sufpos + 1) < n * x)
			printf("Case #%d: YES\n", test);
		else
			printf("Case #%d: NO\n", test);
	}
	return 0;
}