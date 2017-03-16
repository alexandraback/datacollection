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
	ifstream in("input.txt");
	ofstream out("out.put.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		int D;
		in >> D;
		vector<int> pancakes(D);
		copy_n(istream_iterator<int>(in), D, pancakes.begin());
		int minutes = 1000;
		for (int i = 1; i < 1000; i++) {
			minutes = min(minutes, i + divide_down_to(i, pancakes));
		}

		out << "Case #" << test << ": " << minutes << endl;
	}

	return 0;
}