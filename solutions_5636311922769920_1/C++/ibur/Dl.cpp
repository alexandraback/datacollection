#include <bits/stdc++.h>

using namespace std;

typedef long long int intt;

void code() {
	intt K, C, S;
	cin >> K >> C >> S;

	vector<intt> locs;
	intt counter = 0;
	for(int i = 0; i < S && counter < K; i++) {
		intt val = 0;
		for(int j = 0; j < C; j++) {
			val = val * K + (counter >= K ? 0 : counter);
			counter++;
		}
		val++;
		locs.push_back(val);
	}

	if(counter < K) {
		cout << " IMPOSSIBLE";
	} else {
		for(int i = 0; i < locs.size(); i++) {
			cout << " " << locs[i];
		}
	}
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ":";
		code();
		cout << endl;
	}
}

