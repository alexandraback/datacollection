#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

void solve()
{
	long long int A, B, K,i,j,count=0,temp;

	scanf("%lld%lld%lld", &A, &B, &K);
	for (i = 0; i < A; i++)
	{
		for (j = 0; j < B; j++){
			temp = i & j;
			if (temp < K)
				count++;
		}
	}
	printf("%lld\n", count);
}

int main()
{
	int T;

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}