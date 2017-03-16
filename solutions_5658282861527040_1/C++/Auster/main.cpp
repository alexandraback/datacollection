#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
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
#include <memory.h>

using namespace std;

typedef long long LL;

int T, A, B, K;

int a[1 << 6];
int b[1 << 6];
int k[1 << 6];

LL dp[1 << 6][1 << 3];

LL go(int bit, int mask)
{
	if (bit == -1)
		return 1;
	LL & res = dp[bit][mask];
	if (res != -1)
		return res;
	res = 0;
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			if ((mask & 1) && (mask & 2))
			{
				if (mask & 4)
					res += go(bit - 1, mask);
				else
				{
					if ((i & j) <= k[bit])
					{
						int next = mask;
						if ((i & j) < k[bit])
							next |= 4;
						res += go(bit - 1, next);
					}
				}
			}
			if ((mask & 1) && !(mask & 2))
			{
				if (j > b[bit])
					continue;
				if (mask & 4)
				{
					int next = mask;
					if (j < b[bit])
						next |= 2;
					res += go(bit - 1, next);
				}
				else
				{
					if ((i & j) <= k[bit])
					{
						int next = mask;
						if ((i & j) < k[bit])
							next |= 4;
						if (j < b[bit])
							next |= 2;
						res += go(bit - 1, next);
					}
				}
			}
			if (!(mask & 1) && (mask & 2))
			{
				if (i > a[bit])
					continue;
				if (mask & 4)
				{
					int next = mask;
					if (i < a[bit])
						next |= 1;
					res += go(bit - 1, next);
				}
				else
				{
					if ((i & j) <= k[bit])
					{
						int next = mask;
						if ((i & j) < k[bit])
							next |= 4;
						if (i < a[bit])
							next |= 1;
						res += go(bit - 1, next);
					}
				}
			}
			if (!(mask & 1) && !(mask & 2))
			{
				if (i > a[bit])
					continue;
				if (j > b[bit])
					continue;
				if (mask & 4)
				{
					int next = mask;
					if (j < b[bit])
						next |= 2;
					if (i < a[bit])
						next |= 1;
					res += go(bit - 1, next);
				}
				else
				{
					if ((i & j) <= k[bit])
					{
						int next = mask;
						if ((i & j) < k[bit])
							next |= 4;
						if (j < b[bit])
							next |= 2;
						if (i < a[bit])
							next |= 1;
						res += go(bit - 1, next);
					}
				}
			}
		}
	}
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(int I = 0; I < T; ++I)
	{
		scanf("%d%d%d", &A, &B, &K);
		A--, B--, K--;
		memset(dp, -1, sizeof(dp));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(k, 0, sizeof(k));
		for(int i = 0; i < 30; ++i)
		{
			a[i] = A & 1;
			A >>= 1;
			b[i] = B & 1;
			B >>= 1;
			k[i] = K & 1;
			K >>= 1;
		}
		printf("Case #%d: %lld\n", I + 1, go(29, 0));
	}
	return 0;
}