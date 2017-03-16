#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int best_answ(int a, const vector<int> &motes, int from = 0) {
	// motes should be sorted!
	// cout << a << "\n";
	if (motes.size() == 0) return 0;
	int i = from;
	while (i < motes.size() && a > motes[i]) {
		// cout << i << "\n";
		a += motes[i];
		i++;
	}
	// cout << "\n";
	if (i == motes.size()) {
		return 0;
	}
	if (a == 1) {
		// We cannot do anything
		return motes.size() - i;
	}
	// return 0;
	int add_cost = best_answ(a + (a - 1), motes, i) + 1;
	int remove_cost = motes.size() - i;
	return min(add_cost, remove_cost);
}

int main() {
	int T, a, n;
	std::ifstream fin;
	fin.open("A-large.in");
	std::ofstream fout;
	fout.open("output.txt");
	fin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		fin >> a >> n;
		vector<int> motes(n);
		for (int i = 0; i < n; i++) {
			fin >> motes[i];
		}
		sort(motes.begin(), motes.end());

		// for (int i = 0; i < n; i++) {
		// 	cout << motes[i] << "\n";
		// }
		// cout << "\n";
		fout << "Case #" << test_case + 1 << ": " << best_answ(a, motes) << std::endl;
	}
	fin.close();
	fout.close();

	return 0;
}