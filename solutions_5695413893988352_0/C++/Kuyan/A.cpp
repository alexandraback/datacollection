#include <iostream>
#include <sstream>
#include <string>
#include <array>

using namespace std;

string to_str(int x) {
	stringstream ss;
	ss << x;
	string ans;
	ss >> ans;
	return ans;
}

bool equal(string t, string s) {
	for (int i = 0; i < int(s.size()); i++) {
		if (s[i] != '?') {
			if (t[i] != s[i]) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	freopen("B-small-attempt3.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	for (int it = 0; it < t; it++) {
		string s1, s2;
		cin >> s1 >> s2;
		int n = int(s1.size());
		string ans1, ans2; int ansdiff;
		ansdiff = 1000000;
		array<int, 4> pows = { 0, 10, 100, 1000 };
		for (int i = 0; i < pows[n]; i++) {
			if (ansdiff == 0) break;
			for (int j = 0; j < pows[n]; j++) {
				if (ansdiff == 0) break;
				string i1 = to_str(i);
				string j1 = to_str(j);
				while (i1.size() < n) i1 = '0' + i1;
				while (j1.size() < n) j1 = '0' + j1;
				if (!equal(i1, s1)) break;
				if (equal(j1, s2)) {
					if (abs(i - j) < ansdiff) {
						ansdiff = abs(i - j);
						ans1 = i1;
						ans2 = j1;
					}
				}
			}
		}
		cout << "Case #" << it + 1 << ": ";
		cout << ans1 << " " << ans2 << endl;
	}
    return 0;
}

