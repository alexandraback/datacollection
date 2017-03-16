#include <cassert>
#include <cstdlib>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

typedef long long ll;

string int2str(int n) {
	stringstream str;
	str << n;
	string ret; str >> ret;
	return ret;
}

int str2int(string s) {
	return atoi(s.c_str());
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		ll ans = 0;
		int a, b; cin >> a >> b;
		for (int n = a; n <= b; ++n) {
			string s = int2str(n);
			set<string> all;
			for (int i = 1; i < (int) s.length(); ++i) {
				string t = s.substr(i) + s.substr(0, i);
				int m = str2int(t);
				if (n < m && m <= b)
					all.insert(s.substr(i) + s.substr(0, i));
			}
//cout << n << " " << all.size() << endl;
			ans += all.size();
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}

