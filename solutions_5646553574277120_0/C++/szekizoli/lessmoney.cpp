#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

void init() {

}

unsigned C, D, V;
bitset<31> coins;
vector<int> vcoins;
int sumit(unsigned bits) {
	int s = 0;
	for (auto i : vcoins) {
		if (bits % 2 == 1) {
			s += i;
		}
		bits /= 2;
	}
	return s;
}

unsigned find_first(bitset<31>& values) {
	for (int i = 1; i < values.size(); ++i) {
		if (!values[i]) return i;
	}
	return values.size();
}

void add_coin(bitset<31>& values, unsigned coin) {
	int flipped = 0;
	vector<int> to_flip;
	for (int i = 0; i + coin < values.size(); ++i) {
		if (values[i] && !values[i + coin]) {
			to_flip.push_back(i + coin);
		}
	}

	for (auto t : to_flip) {
		values[t] = true;
		++flipped;
	}
}

unsigned solve() {
	const int MAX = 31;
	bitset<31> values;
	values[0] = true;
	unsigned max_count = 1 << vcoins.size();
	for (unsigned adder_bits = 1; adder_bits < max_count; ++adder_bits) {
		int i = sumit(adder_bits);
		if (i < MAX)
			values[i] = true;
	}

	int count = 0;
	unsigned first = find_first(values);
	while (first < V) {
		++count;
		coins[first] = true;
		add_coin(values, first);
		first = find_first(values);
	}
	
	return count;
}

void solvecase() {
	cin >> C >> D >> V;
	int d;
	coins.reset();
	vcoins.clear();
	for (int i = 0; i < D; ++i) {
		cin >> d;
		coins[d] = true;
		vcoins.push_back(d);
	}
	cout << solve() << endl;
}

int N;
int main() {
	init();
	cin >> N;
	for (int t = 1; t <= N; ++t) {
		cout << "Case #" << t << ": ";
		solvecase();
	}

	return 0;
}