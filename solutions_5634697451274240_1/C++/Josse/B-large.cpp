#include <iostream>
#include <cassert>
#include <string>

using namespace std;

char c[] = {'+', '-'};

int solve() {
	string S;
	cin >> S;
	assert(S.size() >= 1 && S.size() <= 100);
	int ans = -1; // +'s occurring at the end are free :-)
	int l = S.size();
	int mode = 0;
	while (l > 0) {
		ans++;
		while (l > 0 && S[l - 1] == c[mode]) l--;
		mode = 1 - mode;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	assert(T >= 1 && T <= 100);
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
