#include <bits/stdc++.h>

using namespace std;

#define INP "inp.txt"
#define OUT "out.txt"
#define oo 123456789

int T, N, cnt, ans, bit1[65537];
string s1, s2, ans1, ans2, s;
std::vector< pair<int, int> > v;
map<string, int> m;

void pre() {
	for(int i = 0; i <= 1 << 16; i++) {
		int tmp = 0;
		for(int j = i; j > 0; j &= (j - 1)) tmp++;
		bit1[i] = tmp;
	}
}

bool isOn(int val, int p) {
	return (val & (1 << p));
}

bool check(int mask) {
	for(int i = 0; i < N; i++) {
		if(isOn(mask, i)) {
			int found = 0;
			for(int j = 0; j < N; j++) {
				if(isOn(mask, j) || j == i) continue;
				if(v[j].first == v[i]. first) {
					for(int k = 0; k < N; k++) {
						if(isOn(mask, k) || k == i || k == j) continue;
						if(v[k].second == v[i].second) found = 1;
					}
				}
			}
			if(!found) return false;
		}
	}
	return true;
}

void solve() {
	ans = 0;
	for(int i = 0; i < 1 << N; i++) {
		if(check(i)) ans = max(ans, bit1[i]);
	}
}

int main () {
	freopen(INP, "r", stdin);
	freopen(OUT, "w", stdout);

	pre();
	scanf(" %d ", &T);
	for(int tt = 1; tt <= T; tt++) {
		m.clear(); v.clear();
		int tmp1, tmp2;
		cnt = 0;
		scanf(" %d ", &N);
		for(int i = 0; i < N; i++) {
			cin >> s1 >> s2;
			if(!m[s1]) {
				m[s1] = ++cnt;
			}
			if(!m[s2]) {
				m[s2] = ++cnt;
			}
			v.push_back(make_pair(m[s1], m[s2]));
		}
		solve();
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}