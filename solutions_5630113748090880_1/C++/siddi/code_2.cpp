#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input3.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int t;
	int county = 0;
	cin >> t;

	while(t--)
	{
		county++;
		int m[2501];
		memset(m,0,sizeof(m));
		int n;
		int x;
		int y;
		cin >> n;

		x = 2*n-1;

		for(int i = 0;i < x;i++)
		{
			for(int i = 0;i < n;i++)
			{
				cin >> y;
				m[y]++;
			}
		}
		cout << "Case #" << county << ": ";
		for(int i = 0;i < 2501;i++)
		{
			if((m[i] != 0) && (m[i]%2 != 0))
			{
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
