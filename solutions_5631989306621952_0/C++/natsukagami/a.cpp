#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;

string s;

int main() {
	int T; cin >> T;
	for (int Tc = 1; Tc <= T; ++Tc) {
		cin >> s; deque<char> d;
		printf("Case #%d: ", Tc);
		for (int i = 0; i < (int)s.length(); ++i) if (!d.size() || d.front() <= s[i]) d.push_front(s[i]); else d.push_back(s[i]);
		for (int i = 0; i < (int)s.length(); ++i) printf("%c", d[i]); printf("\n");
		cerr << "Case " << Tc << endl;
	}
}