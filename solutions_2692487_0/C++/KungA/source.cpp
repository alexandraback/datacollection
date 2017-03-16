#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
using namespace std;

int a[100];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	#endif

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n, sz;
		cin >> sz >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);

		int ans = n, add = 0;
		if (sz > 1)
		{
			for (int i = 0; i < n; i++)
			{
				while (sz <= a[i])
				{
					sz += sz - 1;
					add++;
				}
				sz += a[i];

				ans = min(ans, add + n - i - 1);
			}
		}

		cout << "Case #" << t + 1 << ": ";
		cout << ans;		
		cout << endl;
	}
}
































