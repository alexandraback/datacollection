//Problem: Google Code Jam 2014 Round 1C A
//Name: Part Elf
//Author: Bruce K. B. Tong
//Tag: Ad Hoc

#include <cstdio>
#include <iostream>

using namespace std;

#define SMALL
//#define LARGE

int solve(long long P, long long Q) {
	int ans = 0;
	for (int k = 0; k <= 40; k++) {
		if (P >= Q) {
			if (ans == 0) ans = k;
			P -= Q;
		}
		if (P == 0) break;
		P *= 2;
	}
	return P == 0? ans: 0;
}

int main() {
	freopen("A-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("A-small-attempt0.in", "rt", stdin);
		freopen("A-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("A-large.in", "rt", stdin);
		freopen("A-large.out", "wt", stdout);
	#endif

	int T;				//1 <= T <= 100
	long long P, Q;			//1 <= P < Q <= 1,000 (or 10^12)

	cin >> T;
	for (int i = 1; i <= T; i++) {
		scanf("%lld/%lld", &P, &Q);
		cout << "Case #" << i << ": ";
		int ans = solve(P, Q);
		if (ans > 0)
			cout << ans;
		else
			cout << "impossible";
		cout << endl;
	}
	return 0;
}