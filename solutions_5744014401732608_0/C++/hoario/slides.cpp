#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	size_t inputCount;
	cin >> inputCount;
	for (size_t inputNumber = 1; inputNumber <= inputCount; ++inputNumber) {
		int b, m;
		cin >> b >> m;
		cout << "Case #" << inputNumber << ": ";
		if (m > (b-1)) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << "POSSIBLE" << endl;
			int first = 1+b-m;
			// from building 1
			cout << std::string(first-1,'0');
			cout << std::string(b-first+1,'1');
			cout << endl;
			// useless buildings
			for (int row = 2; row < first; ++row) {
				cout << string(b, '0') << endl;
			}		
			// intermediates
			for (int row = first; row < b; ++row) {
				string s(b, '0');
				s[row] = '1';
				cout << s << endl;
			}
			// last
			cout << string(b, '0') << endl;
		}
	}
	return 0;
}
