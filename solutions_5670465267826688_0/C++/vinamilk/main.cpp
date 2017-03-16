#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

const int nm = 10002;

string s, s2;
int n, x;
map<pair<string, string>, string> u;
string ff[nm];

string f(string x, string y) {
//	cout << x << " " << y << " ";
	int d = 0;
	if (x[0] == '-') {
		d = 1;
		x.erase(0, 1);
	}
	if (y[0] == '-'){
		d = 1 - d;
		y.erase(0, 1);
	}
	string dau = (d ? "-" : "");
	string kq = u[mp(x, y)];
	dau = dau + kq;
	if (dau[0] == '-' && dau[1] == '-')
		dau.erase(0, 2);
//	cout << dau << "\n";
	return dau;
}

void solve(int test) {
	cout << "Case #" << test << ": ";
	cin >> n >> x >> s;
	s2 = "";
	for (int i = 1; i <= x; ++i)
		s2 = s2 + s;
//	cout << s2 << "\n";
	ff[0] = "1";
	string rong = "";
	for (int i = 1; i <= n * x; ++i)
		ff[i] = f(ff[i - 1], rong + s2[i - 1]);
	if (ff[n * x] != "-1") {
		cout << "NO\n";
		return;
	}
	for (int i = 1; i <= n * x; ++i) {
		if (ff[i] == "k") {
			for (int j = 1; j < i; ++j)
				if (ff[j] == "i") {
					cout << "YES\n";
					return;
				}
		}
	}
	cout << "NO\n";
}

int main() {
#ifdef LOCAL
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	u[mp("1", "1")] = "1";
	u[mp("1", "i")] = "i";
	u[mp("1", "j")] = "j";
	u[mp("1", "k")] = "k";
	u[mp("i", "1")] = "i";
	u[mp("i", "i")] = "-1";
	u[mp("i", "j")] = "k";
	u[mp("i", "k")] = "-j";
	u[mp("j", "1")] = "j";
	u[mp("j", "i")] = "-k";
	u[mp("j", "j")] = "-1";
	u[mp("j", "k")] = "i";
	u[mp("k", "1")] = "k";
	u[mp("k", "i")] = "j";
	u[mp("k", "j")] = "-i";
	u[mp("k", "k")] = "-1";
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve(i);
}
