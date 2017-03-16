#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define N 1000006
int STEPS[N];

void solve_case(int casen) {
	int n;
	cin >> n;
	cout << "Case #" << casen << ": " << STEPS[n] << endl;
}

int rever(int a) {
	int b = 0;
	while(a) {
		b = b * 10 + a % 10;
		a /= 10;
	}
	return b;
}

void init() {
	for(int i=0;i<N-1;i++) STEPS[i] = N;
	for(int i=0;i<20;i++) {
		STEPS[i] = i;
	}
	// cout << "HERE\n";
	for(int i=20;i<N-1;i++) {
		// cout << i << endl;
		if (i % 10 != 0 && rever(i) < N) {
			// cout << i << ' ' << rever(i) << endl;
			STEPS[i] = min(STEPS[i-1] + 1, STEPS[rever(i)] + 1);
		}
		else {
			STEPS[i] = STEPS[i-1] + 1;
		}
	}
}

int main() {
	int cases;
	init();
	cin >> cases;
	for(int i=1;i<=cases;i++) solve_case(i);

	return 0;
}