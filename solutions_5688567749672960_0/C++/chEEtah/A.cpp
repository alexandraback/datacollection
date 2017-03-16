#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <iostream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;

long long go(long long from, long long to)
{
	// from is 100....
	// to has the same length

	vector<int> to_d;
	long long x = to;
	while(x)
	{
		to_d.push_back(x % 10);
		x /= 10;
	}

	long long res = to - from;

	for(int right = 1; right < to_d.size(); right++)
	{
		// set right of the rightmost digits correctly, then reverse, then finalise
		long long cur = 0;

		for(int i = 0; i < right; i++) cur = cur * 10 + to_d[to_d.size() - right + i];

		cur++; // flip

		long long remaining = to_d.size() - right;
		long long pow10 = 1;
		for(int i = 0; i < remaining; i++) pow10 *= 10;

		cur += to % pow10 - 1;
		if (to % pow10 == 0) continue; // can't do that

		res = min(res, cur);
	}
	return res;
}

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		long long int n;
		cin >> n;

		long long cur = 1;
		long long res = 1;

		while(cur < n)
		{
			// cur is 100....0 here 
			if (cur * 10 <= n)
			{
				// need another 10x jump
				res += go(cur, cur * 10 - 1) + 1;
				cur *= 10;
			}
			else
			{
				// go to n now
				long long go1 = go(cur, n);
				long long go2 = go(cur, n - 1) + 1;
				res += min(go1, go2);
				cur = n;
			}
		}
		
		cout << res << endl;
	}
	return 0;
}