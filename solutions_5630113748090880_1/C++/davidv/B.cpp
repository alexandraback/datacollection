#include <bits/stdc++.h>

using namespace std;

void doCase(int t) {
	int N;
	cin >> N;
	
	map<int, int> count;
	for (int i=0; i<2*N-1; i++) {
		for (int j=0; j<N; j++) {
			int c;
			cin >> c;
			count[c]++;
		}
	}
	cout << "Case #" << t << ":";
	for (auto kv : count) {
		if (kv.second % 2 == 1) cout << " " << kv.first;
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i=0; i<t; i++) doCase(i+1);
	return 0;
}
