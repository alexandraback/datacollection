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


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	#endif

	int T;
	cin >> T;
	for (int tt = 0; tt < T; tt++)
	{
		long long R, t;
		cin >> R >> t;

		long long l = 0, r = 1e18;
		while (l < r)
		{
			long long m = (l + r + 1) / 2;
			double k = (m + 1);
			k *= m;
			k *= 2;
			k += (double)2 *(double)m * (double)R - (double)m * (double)3;

			if (k > t)
				r = m - 1;
			else
				l = m;
		}

		cout << "Case #" << tt + 1 << ": " << l;		
		cout << endl;
	}
}
































