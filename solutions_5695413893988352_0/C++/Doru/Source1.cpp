#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int n;
string s1, s2;
string sa;
int minim = 9999;
string ansa, ansb;

void fill_b(string s) {
	if (s.size() == s2.size()) {
		//somethingsomething
		int diff = abs(stoi(s) - stoi(sa));
		if (diff < minim) {
			minim = diff;
			ansa = sa;
			ansb = s;
		}
		else {
			if (diff == minim) {
				if (sa < ansa) {
					ansa = sa;
					ansb = s;
				}
				else {
					if (sa==ansa && s < ansb) {
						ansa = sa;
						ansb = s;
					}
				}
			}
		}
		return;
	}

	int i = s.size();

	if (s2[i] == '?') {
		for (int j = 0; j <= 9; j++) {
			s.push_back(j + '0');
			fill_b(s);
			s.pop_back();
		}
	}
	else {
		s.push_back(s2[i]);
		fill_b(s);
	}
}
void fill_a(string s) {
	if (s.size() == s1.size()) {
		sa = s;
		fill_b("");
		return;
	}

	int i = s.size();

	if (s1[i] == '?') {
		for (int j = 0; j <= 9; j++) {
			s.push_back(j + '0');
			fill_a(s);
			s.pop_back();
		}
	}
	else {
		s.push_back(s1[i]);
		fill_a(s);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;

	for (int t = 1; t <= tests; t++) {
		minim = 999999;
		ansa = "a";
		ansb = "a";
		cin >> s1 >> s2;
		
		fill_a("");

		cout << "Case #" << t << ": " << ansa << " " << ansb << "\n";
	}

	return 0;
}