#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

char s[1010];

string gao(string s) {
	char ch = *max_element(s.begin(), s.end());
	string t;
	string ans, pre;
	for (auto c : s) {
		if (c < ch) {
			t += c;
		} else {
			ans += pre.size() ? t : gao(t);
			t = "";
			pre += ch;
		}
	}
	return pre + ans + t;
}

int main() {
	int cas;
	scanf("%d", &cas);
	for (int re = 1; re <= cas; re++) {
		scanf("%s", s);
		printf("Case #%d: %s\n", re, gao(s).c_str());
	}
}