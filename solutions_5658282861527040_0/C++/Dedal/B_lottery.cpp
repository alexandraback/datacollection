#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;
typedef long long lint;

lint solve(lint a, lint b, lint k) {
	lint ans = 0;
	for (int aa = 0; aa < a; ++aa) {
		for (int bb = 0; bb < b; ++bb) {
			if ((aa & bb) < k) {
				++ans;
			}
		}
	}
	return ans;
}

int main() {
	// ifstream input("input.txt");
	// ofstream output("output.txt");
	ifstream input("B-small-attempt0.in");
	ofstream output("B-small-attempt0.out");
	int T;
	input >> T;
	for (int t = 1; t <= T; ++t) {
		int a, b, c;
		input >> a >> b >> c;
		output << "Case #" << t << ": " << solve(a, b, c) << endl;
	}
	return 0;
}
