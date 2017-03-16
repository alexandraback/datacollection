#include <bits/stdc++.h>
using namespace std;

const int mn = 1000100;

int s[mn];

long long reverse(long long x) {
	long long r = 0;
	while (x) {
		r = r * 10 + x % 10;
		x /= 10;
	}
	return r;
}

void bfs() {

	static long long q[mn];
	int qh = -1, qt = 0;
	q[0] = 1;

	fill(s, s + mn, -1);
	s[1] = 1;

	while (++qh <= qt) {
		long long x = q[qh];
//		printf("x = %lld\n", x);
		if (x + 1 < mn && s[x + 1] == -1) {
			s[x + 1] = s[x] + 1;
			q[++qt] = x + 1;
		}
		long long r = reverse(x);
		if (r < mn && s[r] == -1) {
			s[r] = s[x] + 1;
			q[++qt] = r;
		}
	}

}

int main() {


	bfs();

	int Tc;
	scanf("%d", &Tc);
	for (int Tn = 1; Tn <= Tc; ++Tn) {
		long long n;
		cin >> n;
		long long ans = s[n];

		printf("Case #%d: ", Tn);
		cout << ans << endl;
	}
	return 0;
}
