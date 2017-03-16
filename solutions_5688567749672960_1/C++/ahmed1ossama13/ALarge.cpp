#include<bits/stdc++.h>
using namespace std;

long long num(string s) {
	long long ret = 0;
	for (int i = 0; i < int(s.size()); i++) {
		long long d = s[i] - '0';
		ret = ret * 10 + d;
	}
	return ret;
}

string rev(string s) {
	string ret = "";
	for (int i = 0; i < int(s.size()); i++)
		ret = s[i] + ret;
	return ret;
}

bool bad(string s) {
	for (int i = 1; i < int(s.size()); i++) {
		if (s[i] != '0')
			return false;
	}
	return true;
}

long long apply(string s, string cur) {
//	if (bad(s))
//		return num(s) - num(cur);
	long long best = num(s) - num(cur);
	string curB = cur;
	long long tmp = num(rev(s.substr(0, s.size() / 2))) - num(cur.substr(s.size() / 2 + s.size() % 2));
	cur = cur.substr(0, s.size() / 2 + s.size() % 2) + rev(s.substr(0, s.size() / 2));
	if (num(rev(cur)) <= num(s))
		return min(best, num(s) - num(rev(cur)) + 1 + tmp);
	long long u = 1;
	for (int i = int(s.size()) - 2; i >= int(s.size() / 2 + s.size() % 2); i--) {
		u *= 10;
	}
	for (int i = s.size() / 2 + s.size() % 2; i < int(s.size()); i++) {
		if (cur[i] == curB[i]) {
			tmp += ('9' - curB[i]) * u;
			cur[i] = '9';
			u /= 10;
			continue;
		}
		cur[i]--;
		tmp -= u;
		break;
	}
	return min(best, num(s) - num(rev(cur)) + 1 + tmp);
}

string nine(string cur) {
	string ret = "";
	for (int i = 0; i < int(cur.size()); i++)
		ret += "9";
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	freopen("/home/ahmed_ossama/Desktop/Code jam/A/Large/A-large.in", "r", stdin);
	freopen("/home/ahmed_ossama/Desktop/Code jam/A/Large/A-large.out", "w", stdout);
	int t;
	cin >> t;
	int id = 1;
	while (t--) {
		string s;
		cin >> s;

		if (s.size() == 1) {
			cout << "Case #" << id++ << ": " << s[0] - '0' << endl;
			continue;
		}
		long long ans = 10;
		string cur = "10";
		while (cur.size() < s.size()) {
			ans += apply(nine(cur), cur) + 1;
			cur = cur + "0";
		}
		if (bad(s)) {
			long long best = apply(s, cur);
			string curB = cur;
			cur = s;
			cur[0]--;
			for (int i = 1; i < int(cur.size()); i++)
				cur[i] = '9';
			long long tmp = apply(cur, curB);
			tmp += 1;
			cur = s;
			for (int i = 1; i < int(cur.size()); i++)
				cur[i] = '0';
			tmp += apply(s, cur);
			best = min(best, tmp);
			ans += best;
		}
		else {
			ans += apply(s, cur);
		}
		cout << "Case #" << id++ << ": " << ans << endl;
	}

	return 0;
}


