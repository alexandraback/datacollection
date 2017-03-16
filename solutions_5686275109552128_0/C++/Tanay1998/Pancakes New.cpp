#include <bits/stdc++.h>
#define MAX 1111

using namespace std;

int A[MAX];

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	cin >> T;	
	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> A[i];
		
		int ans = MAX;
		for (int lo = 1; lo < 10; lo++)
		{
			int extra = 0;
			for (int i = 0; i < N; i++)
				if (A[i] > lo)
					extra += (A[i] / lo - (A[i] % lo == 0 ? 1 : 0));
		//	cout << extra << lo << endl;
			ans = min(ans, extra + lo);
		}
		
		printf("Case #%d: %d\n", t, ans);
	}
}
