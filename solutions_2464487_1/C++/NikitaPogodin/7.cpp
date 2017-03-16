#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <memory.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <ctime>
#include <assert.h>

#define FOR(i, n) for (int i = 0; i < n; i++)

#pragma comment(linker, "/STACK:250777216")

using namespace std;

typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
const int MOD = int(1e9) + 7;
const int HMOD = (1 << 22) - 1;
const double eps = 1e-8;

const int N = 1000*1000*1000;

int t;
unsigned long long r, paint;

int Count(unsigned long long x)
{
	int count = 0;
	while (x)
	{
		count++;
		x /= 10;
	}
	return count;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%I64d%I64d", &r, &paint);
		LL L = 1, R = 1000000000ll;
		while (R - L > 1)
		{
			LL M = (L + R)/2;
			if (Count(M) + Count(r) > 19)
			{
				R = M;
				continue;
			}
			if (2*M*r - 3*M + 2*M*(M + 1) <= paint)
				L = M;
			else
				R = M;
		}
		printf("Case #%d: %I64d\n", i + 1, L);
	}
	return 0;
}