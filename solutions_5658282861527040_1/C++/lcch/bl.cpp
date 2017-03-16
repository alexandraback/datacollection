#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;


int K;

long long ff(int t, int a, int b)
{
	long long sa = min((1 << t) - 1, a) + 1;
	long long sb = min((1 << t) - 1, b) + 1;
	return (long long)(sa) * sb;
}

long long go(int t, int a, int b)
{
	int s0, s1;
	long long ans;
	s0 = 1 + (a >= (1 << t)) + (b >= (1 << t));
	s1 = ((a>=(1<<t)) && (b>=(1<<t)));
	if (((K >> t) & 1) == 0) {
		if (t == 0) return s0;
		ans = go(t - 1, a, b);
		if (a >= (1<<t)) ans += go(t - 1, a - (1<<t), b);
		if (b >= (1<<t)) ans += go(t - 1, a, b - (1<<t));
	} else {
		if (t == 0) return s1 + s0;
		ans = ff(t, a, b);
		if (a >= (1<<t)) ans += ff(t, a - (1<<t), b);
		if (b >= (1<<t)) ans += ff(t, a, b - (1<<t));
		if ((a >= (1<<t)) && (b >= (1<<t))) ans += go(t - 1, a - (1<<t), b - (1<<t));
	}
	// printf("%d %d %d %lld\n", t, a, b, ans);
	return ans;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B_l.out", "w", stdout);
	int TextN, TT, A, B;
	scanf("%d", &TextN);
	for (int TT = 1; TT <= TextN; TT++) {
		scanf("%d%d%d", &A, &B, &K);
		K -= 1;
		printf("Case #%d: %lld\n", TT, go(30, A-1, B-1));
	}
}