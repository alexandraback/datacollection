#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
	size_t inputCount;
	cin >> inputCount;
	for (size_t inputNumber = 1; inputNumber <= inputCount; ++inputNumber) {
		int jackets, pants, shirts, max;
		map<int, int> combos;
		ostringstream ss;
		cin >> jackets >> pants >> shirts >> max;
		int total = 0;
		for (int j = 1; j <= jackets; ++j) {
			for (int p = 1; p <= pants; ++p) {
				for (int s = 1; s <= shirts; ++s) {
					if ((combos[j + (32*p)] < max ) && (combos[j + (32*32*s)] < max) && (combos[(32*p) + (32*32*s)] < max)) {
						ss << j << ' ' << p << ' ' << s << endl;
						++combos[j + (32*p)];
						++combos[j + (32*32*s)];
						++combos[(32*p) + (32*32*s)];
						++total;
					}
				}
			}
		}
		cout << "Case #" << inputNumber << ": " << total << endl;
		cout << ss.str();
	}
	return 0;
}
