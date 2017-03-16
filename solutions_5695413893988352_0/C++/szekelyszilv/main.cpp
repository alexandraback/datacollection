#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool calc(const string& s, int& a, int& b)
{
	string p1 = s.substr(0, s.length() / 2);
	string p2 = s.substr(s.length() / 2, string::npos);
	int na = stoi(p1);
	int nb = stoi(p2);

	if(abs(na - nb) <= abs(a - b)) {
		if(abs(na - nb) < abs(a - b)) {
			a = na;
			b = nb;
			return true;
		}
		if(na <= a) {
			if(na < a) {
				a = na;
				b = nb;
				return true;
			}
			if(nb <= b) {
				if(nb < b) {
					a = na;
					b = nb;
					return true;
				}
			}
		}
	}
	return false;
}

void solve(string& s, int pos, int& a, int& b, string& sol)
{
	if(pos == s.length()) {
		if(calc(s, a, b)) {
			sol = s;
		}
		return;
	}
	if(s[pos] == '?') {
		for(char c = '0'; c <= '9'; c++) {
			s[pos] = c;
			solve(s, pos + 1, a, b, sol);
		}
		s[pos] = '?';
	} else {
		solve(s, pos + 1, a, b, sol);
	}
}

int main()
{
	int c;
	cin >> c;
	for (int i = 1; i <= c; i++) {
		int n;
		string s1, s2;
		cin >> s1 >> s2;
		string sol;
		int a, b;
		a = 0;
		b = 1000000;
		string s = s1 + s2;
		solve(s, 0, a, b, sol);
		string sol1 = sol.substr(0, sol.size()/2);
		string sol2 = sol.substr(sol.size()/2, string::npos);
		cout << "Case #" << i << ": " << sol1 << " " << sol2 << endl;
	}
}
