#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <set>

using namespace std;

int main() {
	int cases;

	cin >> cases;

	for (int caseid = 1; caseid <= cases; ++caseid) {
		cout << "Case #" << caseid << ": ";
		int maxshy;
		cin >> maxshy;
		string s;
		cin >> s;
		assert((int )s.size() == maxshy + 1);

		int cnt = 0;
		int add = 0;
		for (int i = 0; i <= maxshy; ++i) {
			if (s[i] != '0' && i > cnt) {
				int tmp = i - cnt;
				add += tmp;
				cnt += tmp;
			}
			cnt += s[i] - '0';
		}
		cout << add << endl;
	}
	return 0;
}

