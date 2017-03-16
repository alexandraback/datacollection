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

#pragma warning(disable : 4996)

map<string, int> ss;

int len;

string temp;

void gen(string &s, int pos) {
	if (pos >= len) {
		ss[string(s)]++;
		return;
	}
	for (int i = 0; i < temp.length(); i++) {
		s += temp[i];
		gen(s, pos + 1);
		s = s.substr(0, s.length() - 1);
	}
	return;
}

bool ch(string a, string b) {
	bool rr[300];
	memset(rr, 0, sizeof(rr));
	for (int i = 0; i < a.length(); i++) {
		rr[a[i]] = true;
	}
	for (int i = 0; i < b.length(); i++) {
		if (!rr[b[i]])
			return false;
	}
	return true;
}

int count(string a, string b) {
	int ans = 0;
	for (int i = 0; i <= a.length() - b.length(); i++) {
		if (a.substr(i, b.length()) == b) {
			ans++;
		}
	}
	return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cout << fixed << setprecision(6);
	int T, TT = 0;
	cin >> T;
	while (T-- && ++TT) {
		ss.clear();
		cout << "Case #" << TT << ": ";
		int k, l, s;
		cin >> k >> l >> s;
		string board, w, kk = "";;
		cin >> board >> w;
		temp = board;
		len = s;
		if (!ch(board, w) || l > s) {
			cout << "0.0\n";
			continue;
		}
		gen(kk, 0);
		kk = kk;
		int mm = 0, sum = 0;
		int nn = 0;
		for (map<string, int>::iterator it = ss.begin(); it != ss.end(); it++) {
			nn += (*it).second;
			int r = count((*it).first, w);
			if (r) {
				mm = max(mm, r);
				r *= (*it).second;
				sum += r;
			}
		}
		long double ans = mm;
		ans -= (sum * 1.0) / (nn);
		cout << ans << "\n";
	}
	return 0;
}