#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int count, high = 1;
		cin >> count;
		vector<int> plates(count);
		for(int& plate : plates) {
			cin >> plate;
			high = max(high, plate);
		}
		int best = high;
		for(int limit = 1; limit < high; ++limit) {
			int minutes = limit;
			for(int plate : plates) {
				minutes += ceil((float) plate / limit) - 1;
			}
			best = min(best, minutes);
		}
		cout << "Case #" << test << ": " << best << '\n';
	}
	return 0;
}
