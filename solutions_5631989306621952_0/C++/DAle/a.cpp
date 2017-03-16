#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

int main() {
	ifstream ifs("a.in");
	ofstream ofs("a.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test) {
		string s;
		ifs >> s;
		string t;
		t += s[0];
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] >= t[0]) {
				t = s[i] + t;
			} else {
				t += s[i];
			}
		}
		ofs << "Case #" << test+1 << ": " << t << endl;
	}
	return 0;
}
