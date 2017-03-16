#include <bits/stdc++.h>
using namespace std;

int ind(int i, int n) {
	return (i + n) % n;
}

void code() {
	int N;
	cin >> N;
	vector<int> BFF(N);
	for(int i = 0; i < N; i++) {
		cin >> BFF[i];
		BFF[i]--;
	}

	vector<int> order;
	for(int i = 0; i < N; i++) {
		order.push_back(i);
	}

	int best = 0;
	do {
		for(int i = N; i > best; i--) {
			for(int j = i-1; j >= 0; j--) {
				if(BFF[order[j]] != order[ind(j-1,i)] && BFF[order[j]] != order[ind(j+1, i)]) goto next;
			}
			best = max(i, best);
			next:;
		}
	} while(next_permutation(order.begin(), order.end()));
	cout << best;
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		code();
		cout << endl;
	}
}
