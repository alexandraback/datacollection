#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	cin >> T;
	for(int tk = 0; tk < T; ++tk)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; ++i) cin >> v[i];
		int ans = 10000;
		for(int t = 1; t < 1005; ++t)
		{
			int temp = t;
			for(int i = 0; i < n; ++i)
			{
				temp += (v[i] - 1) / t;				
			}
			ans = min(ans, temp);
		}
		printf("Case #%d: %d\n", tk + 1, ans);
	}
}
