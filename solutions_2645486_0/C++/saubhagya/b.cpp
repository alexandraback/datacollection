#include <cmath>
#include <fstream>
#define MAX 11

using namespace std;

ifstream in("input_b.txt");
ofstream out("output_b.txt");

int e, r, n, v[MAX];

long get_max(int current_energy, int index) {
	if (index == n) {
		return 0;
	}
	
	long max_gain = 0, gain, after_energy;

	for (int i = 0; i <= current_energy; i++) {
		after_energy = current_energy - i + r;
		if (after_energy > e) {
			after_energy = e;
		}

		gain = (v[index] * i) + get_max(after_energy, index + 1);
		if (gain > max_gain) {
			max_gain = gain;
		}
	}
	return max_gain;
}

long compute() {
	return get_max(e, 0);
}

int main() {
	int t;
	in >> t;
	
	for (int i = 0; i < t; i++) {
		in >> e >> r >> n;
		for (int j = 0; j < n; j++) {
			in >> v[j];
		}
		out << "Case #" << (i + 1) << ": " << compute() << endl;
	}
	return 0;
}
