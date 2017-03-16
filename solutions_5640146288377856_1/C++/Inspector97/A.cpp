#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<string>
#include<sstream>

using namespace std;

#pragma warning (disable : 4996)

int f(int w, int st) {
	vector<bool> vb(w);
	for (int i = st - 1; i < w; i += st) {
		vb[i] = true;
	}
	bool fl = false;
	int i;
	for (i = w - 1; i >= 0; i--) {
		if (!fl) {
			fl = vb[i];
		}
		else {
			if (vb[i])
				break;
		}
	}
	return w - i - 1;
}

int solve(int w, int l) {
	int k = w - l;
	if (k == 0) {
		return w - 1;
	}
	int ans = -1;
	ans += 2 * (l) -w;
	ans += k + 1;
	return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, TT = 0;
	cin >> T;
	while (T-- && ++TT) {
		cout << "Case #" << TT << ": ";
		int h, w, l;
		cin >> h >> w >> l;
		int ans = (w / l) * h;
		ans += solve(f(w, l), l);
		cout << ans << endl;
	}
	return 0;
}