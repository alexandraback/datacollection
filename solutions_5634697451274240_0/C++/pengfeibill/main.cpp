#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		string s;
		cin >> s;
		int p = s.size() - 1;
		while (p >= 0 && s[p] != '-')
			p--;
		if (p < 0) {
			cout << 0 << endl;
			continue;
		}
		int res = 1;
		for (int i = 0; i < p; i++)
			if (s[i] != s[i + 1])
				res++;
		cout << res << endl;
	}
	return 0;
}