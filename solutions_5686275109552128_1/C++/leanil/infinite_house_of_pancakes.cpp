#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int divide_down_to(int num, const vector<int>& pencakes) {
	int sum = 0;
	for (int p : pencakes) {
		sum += (p - 1) / num;
	}
	return sum;
}

int main() {
	ifstream in("small_input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		int D;
		in >> D;
		vector<int> pancakes(D);
		int max_count = 0;
		for (int i = 0; i < D; i++) {
			in >> pancakes[i];
			max_count = max(max_count, pancakes[i]);
		}
		int minutes = max_count;
		for (int i = 1; i < max_count; i++) {
			minutes = min(minutes, i + divide_down_to(i, pancakes));
		}

		out << "Case #" << test << ": " << minutes << endl;
	}

	return 0;
}