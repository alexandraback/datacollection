#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<map>

using namespace std;


int GetMinToDiv(int n, int k)
{

	return ((n / k) + (n % k ? 0 : -1));
}

int main()
{

	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int res = 1000 * 1000 * 1000;
		for(int maxp = 1; maxp < 1003; maxp ++)
		{
			int localres = maxp;
			for(int i = 0; i < n; i++)
			{
				localres += GetMinToDiv(a[i] , maxp);
			}
			res = min(res, localres);
		}

		printf("Case #%d: %d\n", tt+1, res);
	}


	return 0;
}