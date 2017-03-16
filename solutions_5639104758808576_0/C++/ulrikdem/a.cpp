#include <iostream>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int max, standing = 0, answer = 0;
		cin >> max;
		for(int shyness = 0; shyness <= max; ++shyness) {
			if(standing < shyness) {
				answer += shyness - standing;
				standing = shyness;
			}
			char count;
			cin >> count;
			standing += count - '0';
		}
		cout << "Case #" << test << ": " << answer << '\n';
	}
	return 0;
}
