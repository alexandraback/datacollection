#include <bits/stdc++.h>

using namespace std;

int n;
string w[20][2];

int test(int mask)
{
	//printf("testing mask %d\n", mask);
	int m = mask;
	set<string> fi, se;
	while(m)
	{
		int i = __builtin_ctz(m);
		fi.insert(w[i][0]);
		se.insert(w[i][1]);
		//cout << w[i][0] << " " << w[i][1] << " is true\n";
		m -= m&(-m);
	}
	bool ok = true;
	for (int i = 0; i < n; i++)
	{
		if ((mask>>i)&1) continue;
		string cfi = w[i][0], cse = w[i][1];
		//cout << cfi << " " << cse << " ";
		if (!fi.count(cfi) or !se.count(cse))
		{
			//cout << "is invalid\n";
			ok = false;
		}
		//else
			//cout << "is valid\n";
	}
	return ok;
}

int solve()
{
	int ans = 0;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		int cur = n - __builtin_popcount(mask);
		if (test(mask) and cur > ans)
			ans = cur;
	}
	return ans;
}

int main()
{
	int T, t = 0;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			cin >> w[i][0] >> w[i][1];	
		}
		printf("Case #%d: %d\n", ++t, solve());
	}
	return 0;
}
