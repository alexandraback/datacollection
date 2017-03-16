#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <ctime>
#include <cassert>
#include <bitset>

using namespace std;

int t, n, l, ans, tans, x;
string s, s1, ps;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> l >> x >> s1;
		s = "";
		ps = "";
		for (int i = 0; i < x; i++)
			s += s1;
		ps += s[0];
		x = 0;
		for (int i = 1; i < s.length(); i++) {
			if (ps == "i" && !x) {
				x++;
				ps = "";
				ps += s[i];
				continue;
			}
			else if (ps == "j" && x == 1) {
				x++;
				ps = "";
				ps += s[i];
				continue;
			}
			if (ps[0] != '-') {
				if (ps[0] == '1') {
					if (s[i] == '1') {
						ps = "1";
					}
					else if (s[i] == 'i') {
						ps = "i";
					}
					else if (s[i] == 'j') {
						ps = "j";
					}
					else {
						ps = "k";
					}
				}
				else if (ps[0] == 'i') {
					if (s[i] == '1') {
						ps = "i";
					}
					else if (s[i] == 'i') {
						ps = "-1";
					}
					else if (s[i] == 'j') {
						ps = "k";
					}
					else {
						ps = "-j";
					}
				}
				else if (ps[0] == 'j') {
					if (s[i] == '1') {
						ps = "j";
					}
					else if (s[i] == 'i') {
						ps = "-k";
					}
					else if (s[i] == 'j') {
						ps = "-1";
					}
					else {
						ps = "i";
					}
				}
				else {
					if (s[i] == '1') {
						ps = "k";
					}
					else if (s[i] == 'i') {
						ps = "j";
					}
					else if (s[i] == 'j') {
						ps = "-i";
					}
					else {
						ps = "-1";
					}
				}
			}
			else {
				if (ps[1] == '1') {
					if (s[i] == '1') {
						ps = "-1";
					}
					else if (s[i] == 'i') {
						ps = "-i";
					}
					else if (s[i] == 'j') {
						ps = "-j";
					}
					else {
						ps = "-k";
					}
				}
				else if (ps[1] == 'i') {
					if (s[i] == '1') {
						ps = "-i";
					}
					else if (s[i] == 'i') {
						ps = "1";
					}
					else if (s[i] == 'j') {
						ps = "-k";
					}
					else {
						ps = "j";
					}
				}
				else if (ps[1] == 'j') {
					if (s[i] == '1') {
						ps = "-j";
					}
					else if (s[i] == 'i') {
						ps = "k";
					}
					else if (s[i] == 'j') {
						ps = "1";
					}
					else {
						ps = "-i";
					}
				}
				else {
					if (s[i] == '1') {
						ps = "-k";
					}
					else if (s[i] == 'i') {
						ps = "-j";
					}
					else if (s[i] == 'j') {
						ps = "i";
					}
					else {
						ps = "1";
					}
				}
			}
		}
		if (ps == "k" && x == 2) {
			cout << "Case #" << j + 1 << ": YES" << endl;
		}
		else {
			cout << "Case #" << j + 1 << ": NO" << endl;
		}
	}

	return 0;
}