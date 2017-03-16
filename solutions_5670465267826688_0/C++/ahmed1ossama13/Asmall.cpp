#include <bits/stdc++.h>
using namespace std;

string s;

string neg(string s) {
	if (s[0] == '-')
		return s.substr(1);
	return "-" + s;
}

string mul(string c, string d) {

	if (c[0] == '-' && d[0] == '-')
		return mul(c.substr(1), d.substr(1));
	if (c[0] == '-')
		return neg(mul(c.substr(1), d));
	if (d[0] == '-')
		return neg(mul(c, d.substr(1)));

	if (c == "1")
		return d;
	if (d == "1")
		return c;
	if (c == d)
		return "-1";

	if (c == "i" && d == "j")
		return "k";
	if (c == "i" && d == "k")
		return "-j";

	if (c == "j" && d == "i")
		return "-k";
	if (c == "j" && d == "k")
		return "i";

	if (c == "k" && d == "i")
		return "j";
	if (c == "k" && d == "j")
		return "-i";
	cerr << "here\n";
	//assert(0);
	return "-1";

}

pair<int, int> find(string c, int ind, int copy) {
	map<pair<int, string>, int> mem;
	string v = "1";
	while (c != v) {
		if (mem.find(make_pair(ind, v)) != mem.end())
			return make_pair(-1, -1);
		mem[make_pair(ind, v)] = 1;
		string h = "";
		h += s[ind++];
		v = mul(v, h);
		ind %= int(s.size());
		if (ind == 0)
			copy++;
	}
	return make_pair(ind, copy);
}

string eval() {
	string c = "1";
	for (int i = 0; i < int(s.size()); i++) {
		string h = "";
		h += s[i];
		c = mul(c, h);
	}
	return c;
}

string pow(string c, long long x) {
	if (x == 0)
		return "1";
	string d = pow(c, x / 2);
	d = mul(d, d);
	if (x % 2 == 1)
		d = mul(d, c);
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	freopen("/home/ahmed_ossama/Desktop/Code jam/C/C-small-attempt0.in", "r", stdin);
	freopen("/home/ahmed_ossama/Desktop/Code jam/C/Asmall.out", "w", stdout);
	int t;
	int id = 1;
	pair<int, int> f1, f2;
	cin >> t;
	while (t--) {
		long long n, r;
		cin >> n >> r;
		cin >> s;
		string ans = "YES";
		int i = 0;
		int cnt = 1;
		f1 = find("i", i, cnt);
		//cout << f1.first << " " << f1.second << endl;
		if (f1 == make_pair(-1, -1)) {
			ans = "NO";
			cout << "Case #" << id++ << ": " << ans << endl;
			continue;
		}
		i = f1.first;
		cnt = f1.second;

		f2 = find("j", i, cnt);
		if (f2 == make_pair(-1, -1)) {
			ans = "NO";
			cout << "Case #" << id++ << ": " << ans << endl;
			continue;
		}
		i = f2.first;
		cnt = f2.second;
		//cout << f2.first << " " << f2.second << endl;
		if (i == 0)
			cnt--;
		string c = eval();
		string rem = "1";
		while (i != 0) {
			string h = "";
			h += s[i++];
			rem = mul(rem, h);
			i %= int(s.size());
		}
		//cout << rem << endl;
		if (cnt > r) {
			ans = "NO";
		}
		c = pow(c, r - cnt);
		c = mul(rem, c);
		if (c != "k")
			ans = "NO";
		cout << "Case #" << id++ << ": " << ans << endl;

	}

	return 0;
}

