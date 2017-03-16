#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int totalw;
int totals;
int maxc;

int countw(string &current, string &target) {
	int i = 0;
	int count = 0;
	while (i >= 0) {
		i = current.find(target, i);
		if (i >= 0) {
			++i;
			++count;	
		} 
	}
	return count;
}

void gen(string &keys, string &target, string &current, int left) {
	if (left == 0) {
		int count = countw(current, target);
		totalw += count;
		maxc = max(maxc, count);
		return;
	}
	for(int i = 0; i < keys.size(); ++i) {
		current.push_back(keys[i]);
		gen(keys, target, current, left-1);
		current.pop_back();
	}
}

int main() {
	int t;
	cin >> t;
	for (int cas = 1; cas < t+1; ++cas) {
		totalw = 0;
		maxc = 0;
		int k, l, s;
		cin >> k >> l >> s;
		string keys;
		cin >> keys;
		string target;
		cin >> target;
		string current = "";
		gen(keys, target, current, s);
		double res = 0;
		int totals = pow(k, s);
		if (totals > 0) {
			res = totalw/double(totals);
		}
		res = maxc-res;
		cout << std::setprecision(7);
 		cout << fixed;
		cout << "Case #" << cas << ": " << res << endl;
	}
}