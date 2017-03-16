#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int64_t Ncase;
	cin >> Ncase;
	ostringstream output;
	vector<int64_t> Bmax(50);
	Bmax[0] = 1;
	Bmax[1] = 1;
	for (int i = 2; i < 50; ++i) {
		Bmax[i] = 2 * Bmax[i-1];
	}
	for (int64_t i1 = 1; i1 <= Ncase; ++i1){
		int64_t B, M;
		cin >> B >> M;
		output << "Case #" << i1 << ": ";
		if (M > Bmax[B-1]) {
			output << "IMPOSSIBLE" << endl;
			continue;
		} else {
			output << "POSSIBLE" << endl;
		}
		vector<int> slide(B-1,0);
		for (int i = B-2; i >= 0; --i) {
			if (M >= Bmax[i]) {
				slide[i] = 1;
				M -= Bmax[i];
			}
		}
		output << 0;
		for (int i = B-2; i >= 0; --i) {
			output << slide[i];
		}
		output << endl;
		for (int i = 1; i < B; ++i) {
			for (int j = 0; j <= i; ++j) output << 0;
			for (int j = i+1; j < B; ++j) output << 1;
			output << endl;
		}
	}
	cout << output.str();
	return 0;
}
