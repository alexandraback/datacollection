#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

const int MAX = 1000;
int arr[MAX];
int n;

int main() {
	int ts;
	cin >> ts;
	loop(ti, ts) {
		int best = 1000000000;
		cin >> n;
		loop(i, n) {
			cin >> arr[i];
		}
		for (int t = 1; t <= MAX; t++) {
			int c = 0;
			loop(i, n) {
				c += (arr[i]-1) / t;
			}
			best = min(best, t + c);
		}
		printf("Case #%d: %d\n", ti+1, best);
	}
}
