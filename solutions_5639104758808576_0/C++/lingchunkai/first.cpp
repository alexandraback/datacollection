#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int len;
		string s;

		cin >> len;
		cin >> s;
		len += 1;

		vector<int> peeps;

		for (int i = 0; i < len; i++) {
			peeps.push_back(int(s.c_str()[i]) - 48);
		}

		int added = 0;
		int total = 0;
		for (int i = 0; i < len; i++) {
			// cout << peeps[i] << endl;
			int to_add = 0;
			if (total < i) {
				to_add = i-total;
			}
			added += to_add;
			total += to_add;
			total += peeps[i];
		}

		cout << "Case #" << t+1 << ": " << added << endl;
	}

	return 0;
}