#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <sstream>

using namespace std;

typedef vector<int> vint;
typedef long long LL;

int T;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(int I = 1; I <= T; ++I)
	{
		LL r, t;
		scanf("%lld%lld", &r, &t);
		printf("Case #%d: ", I);
		
		LL L = 1, R = (t / (r * 2)) + 1;
		R = min(R, (LL)1e9 + 2);
		while (R - L > 1)
		{
			LL M = (L + R) / 2;
			LL cnt = M * (r * 2 + (M - 1) * 2 + 1);
			if (cnt <= t)
				L = M;
			else
				R = M;
		}
		printf("%lld\n", L);
	}
	return 0;
}