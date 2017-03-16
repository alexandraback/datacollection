#include <cstdio>

long long lowbit(long long a) {
	return a & -a;
}

long long gcd(long long a, long long b) {
	if (b < a)
		return gcd(b, a);
	if (b % a == 0)
		return a;
	else
		return gcd(b % a, a);
}
int highorder(long long a) {
	long long tmp = 1;
	int ans = 1;
	while (a > tmp * 2) {
		tmp <<= 1;
		ans++;
	}
	return ans;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, TC;
	scanf("%d", &T);
	TC = T;
	while (TC--) {
		long long P, Q, PQgcd;
		scanf("%lld/%lld", &P, &Q);
		PQgcd = gcd(P, Q);
		P /= PQgcd;
		Q /= PQgcd;
		if (Q == lowbit(Q)) {
			printf("Case #%d: %d\n", T - TC, highorder(Q) - highorder(P) + 1);
		}
		else {
			printf("Case #%d: impossible\n", T - TC);
		}
	}
}