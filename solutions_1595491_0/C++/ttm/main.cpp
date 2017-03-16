#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main (int argc, char *argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int cases;
	cin >> cases;
	
	for (int cas = 1; cas <= cases; ++cas) {
		int n, s, targ;
		cin >> n >> s >> targ;
		vector<int> scores(n);

		int good = 0;

		for (int j = 0; j < n; ++j) {
			cin >> scores[j];
			if (scores[j] == 0) good += targ == 0 ? 1 : 0;
			else if (scores[j] == 1) good += targ <= 1 ? 1 : 0;
			else if (scores[j] % 3 == 0) {
				if (scores[j] / 3 >= targ) good++;
				else if (s > 0 && scores[j] / 3 + 1 >= targ) {
					s--;
					good++;
				}
			}
			else if (scores[j] % 3 == 1) {
				if (scores[j] / 3 + 1 >= targ) good++;
			}
			else {
				if (scores[j] / 3 + 1 >= targ) good++;
				else if (s > 0 && scores[j] / 3 + 2 >= targ) {
					s--;
					good++;
				}
			}
		}

		cout << "Case #" << cas << ": " << good << endl;
	}

	return 0;
}