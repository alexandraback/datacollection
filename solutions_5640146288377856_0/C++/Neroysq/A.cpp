#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int R, C, W;

int calc(int C, int W, int &L)
{
	L = C - (C - W) / W * W;
	return (C - W) / W + 1;
}

int solve(int R, int C, int W)
{
	int L;
	int tmp = calc(C, W, L);
	return (L > W) + W + R * tmp - 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases) {
		scanf("%d%d%d", &R, &C, &W);
		printf("Case #%d: %d\n", cases, solve(R, C, W));
	}
	return 0;
}
