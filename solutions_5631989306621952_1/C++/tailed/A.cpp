#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;


int TC;
void solve() {
	string s;
	cin >> s;
	string t;
	rep(i, sz(s)) {
		string a, b;
		a = t + s[i];
		b = s[i] + t;
		if (a < b) t = b;
		else t = a;
	}
	cout << t << endl;
}
int main() {
	int T; cin >> T;
	for(int TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

