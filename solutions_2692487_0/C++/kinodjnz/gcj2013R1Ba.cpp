#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;

int ms[1000010];

int solve(int A, int N) {
	sort(ms, ms+N);
	int x = A;
	int ans = (1<<29);
	int z = 0;
	for (int i = 0; i < N; i++) {
		if (x > ms[i]) {
			x += ms[i];
		} else {
			ans = min(ans, z+N-i);
			if (ms[i] == 1 || x == 1)
				return ans;
			while (x <= ms[i]) {
				x += x-1;
				z++;
			}
			x += ms[i];
		}
	}
	return min(ans, z);
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int A, N;
		cin >> A >> N;
		for (int j = 0; j < N; j++) {
			cin >> ms[j];
		}
		int ans = solve(A, N);
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
