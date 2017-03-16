//be naame khodaa

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int it = 1; it <= t; it++)
	{
		int x, r, c;
		cin >> x >> r >> c;
		cout << "Case #" << it << ": ";
		int ans = 0;
		if (x == 3)
			ans = (r+c <= 4);
		if (x == 4)
			ans = (r+c <= 6);
		if (x == 5)
			ans = (r+c <= 8);
		if (x == 6)
			ans = (r+c <= 9);
		if (x == 7)
			ans = (min(r, c) < 4 || (min(r, c) == 4 && max(r, c) == 7));
		if (r*c%x > 0 || x >= 8)
			ans = 1;
		cout << (ans ? "RICHARD" : "GABRIEL") << endl;
	}
    return 0;
}
