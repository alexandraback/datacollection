#include <bits/stdc++.h>

using namespace std;

void doCase(int t) {
	cout << "Case #" << t << ":";
	
	long long K, C, S;
	cin >> K >> C >> S;
	
	if (C*S<K) {
		cout << " IMPOSSIBLE" << endl;
		return;
	}
	
	long long idx = 0;
	vector<long long> chosen;
	set<long long> seen;
	bool doneInit=false;
	
	for (int i=0; i<S && !doneInit; i++) {
		long long cur = 0;
		for (int j=0; j<C; j++) {
			cur *= K;
			cur += idx;
			idx++;
			if (idx == K) {
				idx = 0;
				doneInit = true;
			}
		}
		chosen.push_back(cur);
	}
	
	for (auto c : chosen) cout << " " << c+1;
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i=0; i<t; i++) doCase(i+1);
	return 0;
}
