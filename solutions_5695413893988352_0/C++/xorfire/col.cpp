#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

string conv(int n, int sz)
{
	stringstream ss;
	ss << n;
	string now = ss.str();
	int want = sz - (int)now.size();
	if (want < 0) return "";
	string ret = "";
	for (int i = 0; i < want; i++) ret += "0";
	return ret + now;
}

bool good(int n, string s)
{
	int sz = s.size();
	string ret = conv(n, sz);
	if (ret == "") return false;
	for (int i = 0; i < sz; i++)
		if (s[i] != '?' and ret[i] != s[i])
			return false;
	return true;
}

#undef int
int main()
{
#define int long long
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cerr << "Executing Case #" << tt << "\n";
		string a, b; cin >> a >> b;
		int ansa = -1, ansb = -1;
		for (int aa = 0; aa < 1000; aa++)
			for (int bb = 0; bb < 1000; bb++)
			{
				if (!good(aa, a)) continue;
				if (!good(bb, b)) continue;
				int d1 = abs(aa - bb);
				int d2 = abs(ansa - ansb);
				if (ansa < 0 or d1 < d2 or (d1 == d2 and (aa < ansa or (aa == ansa and bb < ansb))))
					ansa = aa, ansb = bb;
			}
		cout << "Case #" << tt << ": " << conv(ansa, (int)a.size()) << " " << conv(ansb, (int)b.size()) << "\n";
	}
	return 0;
}