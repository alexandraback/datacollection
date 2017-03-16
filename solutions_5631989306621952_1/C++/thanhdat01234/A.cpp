#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

string S, ans;
int key = 0, dp[200], pre[200], T, mark[200];

void openFile() {
	freopen("in.inp", "r", stdin);
	freopen("ou.out", "w", stdout);
}

string solve() {
	cin >> S;
	ans = S.substr(0, 1);
	for (int i = 1; i < S.size(); ++i)
		if (S[i] >= ans[0]) ans = S[i] + ans;
		else ans = ans + S[i];
	return ans;
}

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	openFile();
	cin >> T;
	for (int i = 0; i < T; ++i)
		cout << "Case " << "#" << i + 1 << ": " << solve() << endl;

	return 0;
}
