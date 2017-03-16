#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#define rep(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

int main ()
{
	freopen ("1.in", "r", stdin); freopen ("1.out", "w", stdout);
	int ti;
	cin >> ti;
	rep (cnt, 1, ti)
	{
		string s0;
		cin >> s0;
		int n = s0.length ();
		string s;
		s = s0[0];
		rep (i, 1, n - 1)
			if (s0[i] >= s[0])
				s = s0[i] + s;//, cout << i << ' ' << s;
			else
				s = s + s0[i];//, cout << i << ' ' << s;
		printf ("Case #%d: ", cnt);
		cout << s << endl;
	}
	return 0;
}
