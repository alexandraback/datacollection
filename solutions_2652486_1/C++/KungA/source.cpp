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

int r, n, m, k;
int a[100];

bool div(int x)
{
	int res = 0;
	for (int i = 0; i < k; i++)
		if (a[i] % x == 0)
		{
			res = 1;
			a[i] /= x;
		}
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	#endif

	cout << "Case #1:\n";
	cin >> r >> r >> n >> m >> k;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < k; j++)
			cin >> a[j];
		int n2 = n;

		for (int j = m; j > 1; j--)
			while (div(j) && n2)
			{
				n2--;
				cout << j;
			}

		while (n2)
		{
			cout << 2;
			n2--;
		}
		cout << endl;
	}


	
}
































