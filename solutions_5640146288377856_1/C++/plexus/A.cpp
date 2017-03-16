#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T; 
	for (int i = 1; i <= T; i++)
	{
		int r, c, w;
		cin >> r >> c >> w;
		long long ans = r * (c / w) + w;
		if (c % w == 0)
			ans--;
		printf("Case #%d: %lld\n", i, ans);
	}
}
