#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int tests;
string s;

int ans(int st, int en, char p) {
    if (st == en) return (p != s[st]);
    if (s[en] == p) return ans(st, en - 1, p);
    else return 1 + ans(st, en - 1, p == '+' ? '-' : '+');
}

int main() {
    cin >> tests;
    for (int t = 0 ; t < tests ; t ++) {
	cin >> s;
	cout << "Case #" << t + 1 << ": " << ans(0, s.length() - 1, '+') << endl;
    }
    return 0;
}
