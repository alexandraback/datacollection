//Problem: Google Code Jam 2013 Round 1A A
//Name: Bullseye
//Author: Bruce K. B. Tong
//Tag: Maths

#include <cstdio>
#include <iostream>
//#include <vector>
//#include <algorithm>

using namespace std;

#define SMALL
//#define LARGE

int solve(int r, int t) {
	int ans = 0;
	while (t > 0) {
		t -= 2*r+1;
		r += 2;
		if (t < 0) break;
		ans++;
	}
	return ans;
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

	int T;				//1 <= T <= 1,000 (or 6,000)
	int r;				//1 <= r <= 1,000 (or 10^18)
	int t;				//1 <= t <= 1,000 (or 2x10^18)
	
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> r >> t;
		//cout << r << " " << t << " " << endl;
		cout << "Case #" << i << ": ";
		cout << solve(r, t);
		cout << endl;
	}
	return 0;
}