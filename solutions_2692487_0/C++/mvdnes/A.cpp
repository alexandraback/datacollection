#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> motes;
long long A, N;

int dfs(int nextmote, int myval, int depth, bool nodel = false) {
	if (nextmote == N) return 0;
	if (depth > N) return 0;
	if (motes[nextmote] < myval) {
		return dfs(nextmote + 1, myval + motes[nextmote], depth);
	} else {
		int val1 = 1 + dfs(nextmote, myval + myval-1, depth+1, true);
		if (!nodel) {
			int val2 = 1 + dfs(nextmote + 1, myval, depth+1);
			return min(val1, val2);
		}

		return val1;
	}
}

void doit(int casenum) {
	int ans = 0;
	
	cin >> A >> N;
	motes.clear();
	
	for (int i = 0; i < N; ++i) {
		int val;
		cin >> val;
		motes.push_back(val);
	}
	
	sort(motes.begin(), motes.end());
	
	ans = dfs(0, A, 0);
	
	cout << "Case #" << casenum << ": " << ans << endl;
}

#include <cstdlib>

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) { doit(i); }
	return 0;
}