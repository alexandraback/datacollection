#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		string s;
		cin >> s;
		string t = "";
		for (int i = 0; i < s.size(); ++i) {
			char ch = s[i];
			string w = string(1, ch);
			if ((t + w) >= (w + t))
				t = t + w;
			else
				t = w + t;
		}
		printf("Case #%d: %s\n", nc, t.c_str());
	}
	return 0;
}
