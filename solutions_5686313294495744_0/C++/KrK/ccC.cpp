#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 16;

int t;
int n;
string A[Maxn], B[Maxn];

bool Check(int mask)
{
	for (int i = 0; i < n; i++)
		if (!(mask & 1 << i)) {
			bool founda = false, foundb = false;
			for (int j = 0; j < n; j++)
				if (mask & 1 << j) {
					founda |= A[i] == A[j];
					foundb |= B[i] == B[j];
				}
			if (!founda || !foundb) return false;
		}
	return true;
}

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			cin >> A[i] >> B[i];
		int res = Maxn;
		for (int i = 0; i < 1 << n; i++)
			if (Check(i)) res = min(res, __builtin_popcount(i));
		printf("Case #%d: %d\n", tc, n - res);
	}
	return 0;
}