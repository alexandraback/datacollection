#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int nc; cin >> nc;
	for (int cs = 1; cs <= nc; cs++) {
		int smax; cin >> smax;
		int maxdiff = 0;
		int sum = 0;
		for (int i = 0; i <= smax; i++) {
			char c; cin >> c;
			int x = (int)(c - '0');
			if (sum < i) {
				maxdiff = max(maxdiff, i - sum);
			}
			sum += x;
		}
		cout << "Case #" << cs << ": " << maxdiff << endl;
	}
}
