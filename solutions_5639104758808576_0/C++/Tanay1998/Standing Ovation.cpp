#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int S;
		cin >> S;
		string P;
		cin >> P;
		int ans = 0;
		int stand = 0;
		for (int shy = 0; shy <= S; shy++)
		{
			int ppl = P[shy] - '0';
			int diff = 0;
			if (shy > stand)
				diff = (shy - stand);
			ans += diff;
			stand += ppl + diff;
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
