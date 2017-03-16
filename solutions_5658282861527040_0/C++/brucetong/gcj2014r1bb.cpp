//Problem: Google Code Jam 2014 Round 1B B
//Name: New Lottery Game
//Author: Bruce K. B. Tong
//Tag: Ad Hoc

#include <cstdio>
#include <iostream>

using namespace std;

#define SMALL
//#define LARGE

long long solve(int A, int B, int K) {
	int ans = 0;
	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++)
			if ((i&j) < K) ans++;
	return ans;
}

int main() {
	freopen("B-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("B-small-attempt0.in", "rt", stdin);
		freopen("B-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("B-large.in", "rt", stdin);
		freopen("B-large.out", "wt", stdout);
	#endif

	int T;				//1 <= T <= 100
	int A, B, K;	//0 <= A, B, K <= 1,000 (or 10^9)
	
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> A >> B >> K;
		cout << "Case #" << i << ": ";
		cout << solve(A, B, K);
		cout << endl;
	}
	return 0;
}