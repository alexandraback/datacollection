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

#undef int
int main()
{
#define int long long
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cerr << "Executing Case #" << tt << "\n";
		string s; cin >> s;
		int ct[526] = {};
		for (char c : s) ct[c]++;

		int n[10] = {};
		n[0] = ct['Z'];
		n[2] = ct['W'];
		n[4] = ct['U'];
		n[6] = ct['X'];
		n[8] = ct['G'];
		n[5] = ct['F'] - n[4];
		n[3] = ct['H'] - n[8];
		n[7] = ct['S'] - n[6];
		n[1] = ct['O'] - n[0] - n[2] - n[4];
		n[9] = ct['I'] - n[5] - n[6] - n[8];

		cout << "Case #" << tt << ": ";
		for (int i = 0; i < 10; i++)
			while (n[i]--)
				cout << i;
		cout << "\n";
	}
	return 0;
}