#include<iostream>

using namespace std;

int G[52][52];

int main()
{
	ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++)
	{
		long long n;
		long long m;
		cin >> n >> m;
		long long q = (1ll << (n - 2));
		if (m > q)
		{
			cout << "Case #" << t << ": IMPOSSIBLE\n";
			continue;
		}
		
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				G[i][j] = 1;
				
		long long e = n - 3;
		while(q > m)
		{
			while(q - (1ll << e) < m)
				e--;
			G[1][n-1-e] = 0;
			q -= (1 << e);
		}
		cout << "Case #" << t << ": POSSIBLE\n";
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << G[i][j];
			cout << "\n";
		} 
	}
	
	
	return 0;
}
