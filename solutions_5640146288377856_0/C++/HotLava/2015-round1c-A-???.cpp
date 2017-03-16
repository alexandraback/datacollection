#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T> std::ostream& operator<<(std::ostream& str, const std::vector<T>& v) { str << "["; for(auto n : v) str << n << ", "; str << "]"; return str; }

#define debug(x) cout <<  #x  << ": " << x << endl

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int t;
	cin >> t;

	for(int ncase=1; ncase<=t; ++ncase) {
		int r,c,w;
		cin >> r >> c >> w;

		int scanpoints = c/w;
		int scan = scanpoints*r;
		int right = c;
		int left = max(0, (scanpoints-1)*w);
		int wiggle = right - left;

		/*debug(scanpoints);
		debug(wiggle);
		debug(w);*/

		int score;
		if(wiggle > w)
			score = scan - 1 + w + 1;
		else
			score = scan - 1 + w;

		cout << "Case #" << ncase << ": " << score << endl;
	}	
}