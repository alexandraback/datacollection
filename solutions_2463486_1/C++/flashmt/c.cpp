#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int f[10100100];

int isPalin(long long x)
{
	long long y = 0, tmp = x;
	while (tmp) y = y * 10 + tmp % 10, tmp /= 10;
	return x == y;
}

int main()
{
	freopen("clarge1.in", "r", stdin); 
	freopen("clarge1.out", "w", stdout);
	
	for (int i = 1; i <= 10000000; i++)
		f[i] = f[i - 1] + (isPalin(i) && isPalin(1LL * i * i));
	
	int test;
	cin >> test;
	for (int itest = 1; itest <= test; itest++)
	{
		long long A, B;
		cin >> A >> B;
		int L = int(sqrt(A)), R = int(sqrt(B));
		if (1LL * L * L == A) L--;
		printf("Case #%d: %d\n", itest, f[R] - f[L]);
	}
}
