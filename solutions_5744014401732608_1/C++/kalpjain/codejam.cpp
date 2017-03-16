#include <bits/stdc++.h>
using namespace std;


int main(void) {
    freopen("in.txt", "rt", stdin);
    freopen("test.txt", "wt", stdout);
    int t, n;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc)
    {
        cin >> n;
        long long int m;
        cin >> m;
        cout << "Case #" << tc << ": ";
        if(( 1LL << (n - 2)) < m)
        {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << "POSSIBLE\n";
		long long int a[55] = {0}, sum = 0;
		int ans[55][55] = {0};
		if (m >= 1)
        {
			ans[1][n] = 1;
			a[1] = 1;
			sum = 1;
		}
		if (m >= 2 && n > 2)
        {
			ans[1][2] = 1;
			ans[2][n] = 1;
			a[2] = 1;
			sum = 2;
		}
		if (m > 2)
        {
			int cur = 2;
			while (sum < m)
            {
				cur++;
				ans[cur][n] = 1;
				for(int i = cur - 1; i > 0; i--)
                {
					if(a[i] + sum <= m)
                    {
						ans[i][cur] = 1;
						sum += a[i];
						a[cur] += a[i];
					}
				}
			}
		}

		for (int i = 1; i <= n; i++)
        {
			for (int j = 1; j <= n; j++)
				cout << ans[i][j];
			cout << "\n";
		}
    }
    return 0;
}
