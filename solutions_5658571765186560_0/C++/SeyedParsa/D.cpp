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
		if (x == 2)
			ans = r*c%2;
		else if (x == 3)
			ans = (r*c%3 > 0) || (r+c < 5);
		else if (x == 4)
			ans = (r*c%4 > 0) || (r+c < 7);
		cout << (ans ? "RICHARD" : "GABRIEL") << endl;
	}
    return 0;
}
