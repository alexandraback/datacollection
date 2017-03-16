#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++)
	{
		int x, r, c;
		cin >> x >> r >> c;
		int ansb = 2;
		if (x >= 7)
			ansb = 0;
		else if ((r%x == 0 || c%x == 0) && (r>(x - 2) && c > (x - 2)))
		{
			ansb = 1;
		}
		else
			ansb = 0;
		string ans = "RICHARD";
		if (ansb) ans = "GABRIEL";
		cout << "Case #" << cs << ": " << ans << endl;
	}
}