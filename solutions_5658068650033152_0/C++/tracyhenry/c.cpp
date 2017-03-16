#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);	
#endif	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		int N, M, K;
		cin >> N >> M >> K;
		
		if (N == 1 || M == 1)
		{
			cout << K << endl;
			continue;
		}
		
		int ans = 10000;
		for (int x1 = 2; x1 < N; x1 ++)
			for (int y1 = 2; y1 < M; y1 ++)
				for (int x2 = x1; x2 < N; x2 ++)
					for (int y2 = y1; y2 < M; y2 ++)
					{
						int lo = x2 - x1 + 1;
						int hi = y2 - y1 + 1;
						if (lo * hi + lo * 2 + hi * 2 >= K)
							ans = min(ans, lo * 2 + hi * 2);
					}
		if (ans == 10000)
		{
			int lo = N - 2;
			int hi = M - 2;
			ans = K - lo * hi;
		}
		ans = min(ans, K);
		cout << ans << endl;
	}
	return 0;
}
