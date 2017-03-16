#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define EPS 1e-8
#define MAXN 1005
#define PI acos(-1.0)

int T, A, B;

int fair_sqr[MAXN];

int palindrome(int x)
{
	int d[5];
	int n = 0;
	while (x) {
		d[n++] = x % 10;
		x /= 10;
	}
	for (int i = 0; i < n; ++i) {
		if (d[i] != d[n - 1 - i]) return 0;
	}
	return 1;
}

void pre()
{
	for (int i = 1; i < 50; ++i) {
		if (i * i > 1000) break;
		if (!palindrome(i)) continue;
		if (!palindrome(i * i)) continue;
		fair_sqr[i * i] = 1;
	}
}

int find()
{
	int cnt = 0;
	for (int i = A; i <= B; ++i) {
		if (fair_sqr[i]) ++cnt;
	}
	return cnt;
}

int main()
{
	pre();
	scanf("%d", &T);
	for (int c = 1; c <= T; ++c) {
		scanf("%d%d", &A, &B);
		printf("Case #%d: %d\n", c, find());
	}
	return 0;
}
