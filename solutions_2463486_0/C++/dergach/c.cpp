#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

long long a[1005];

bool check(long long n)
{
	long long k = 0;
	long long tmp = n;
	while(tmp)
	{
		k = k * 10 + tmp % 10;
		tmp /= 10;
	}
	return k == n;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int n = 0;
	for(long long i = 1; i <= 10000000; i++)
		if(check(i) && check(i * i))
		{
			a[n++] = i * i;
		}
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		long long A, B;
		scanf("%lld %lld", &A, &B);
		int cnt = 0;
		for(int i = 0; i < n; i++)
			if(A <= a[i] && a[i] <= B)
				cnt++;
		printf("Case #%d: %d\n", t, cnt);
	}
	return 0;
}