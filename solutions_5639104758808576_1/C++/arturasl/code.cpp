#include      <iostream>
#define endl '\n'
using namespace std;

int solve() {
	int S, sCur = 0, r = 0;
	string cnts;
	cin >> S >> cnts;
	for (int i = 0; i < (int) cnts.size(); i += 1) {
		if (cnts[i] != '0') {
			while (i > sCur) r += 1, sCur += 1;
			sCur += cnts[i] - '0';
		}
	}
	return r;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) cout << "Case #" << t << ": " << solve() << endl;
	return 0;
}
