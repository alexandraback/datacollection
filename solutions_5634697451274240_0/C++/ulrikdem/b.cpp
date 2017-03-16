#include <iostream>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		char pancake, previous;
		int count = 0;
		cin >> previous;
		if(previous == '-') {
			++count;
		}
		while((pancake = cin.get()) != '\n') {
			if(pancake == '-' && previous == '+') {
				count += 2;
			}
			previous = pancake;
		}
		cout << "Case #" << test << ": " << count << '\n';
	}
	return 0;
}
