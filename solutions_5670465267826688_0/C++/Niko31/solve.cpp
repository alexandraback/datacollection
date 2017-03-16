#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int go[8][8] = {
{0, 1, 2, 3, 4, 5, 6, 7, }, 
{1, 4, 3, 6, 5, 0, 7, 2, },
{2, 7, 4, 1, 6, 3, 0, 5, },
{3, 2, 5, 4, 7, 6, 1, 0, },
{4, 5, 6, 7, 0, 1, 2, 3, },
{5, 0, 7, 2, 1, 4, 3, 6, },
{6, 3, 0, 5, 2, 7, 4, 1, },
{7, 6, 1, 0, 3, 2, 5, 4, },
};

map<char, int> m;

int main()
{
	int t;
	cin >> t;
	m['i'] = 1;
	m['j'] = 2;
	m['k'] = 3;

	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		int n, l;
		string s;
		cin >> n >> l >> s;
		string t = "";
		for (int i = 0; i < l; i++)
			t += s;
		int cur = 0;
		int c = 0;
		for (size_t i = 0; i < t.length(); i++) {
			cur = go[cur][m[t[i]]];
			if (cur == 1 && c == 0) c++;
			if (cur == 3 && c == 1) c++;			
		}
		if (c < 2 || cur != 4) cout << "NO" << endl;
		else cout << "YES" << endl;

	}
}