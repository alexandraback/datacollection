#include <iostream>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int count;
		cin >> count;
		if(count == 1) {
			cout << "Case #" << test << ": 0\n";
			continue;
		}
		long long position1, time1, position2, time2, one;
		cin >> position1 >> one >> time1 >> position2 >> one >> time2;
		if((360 - position1) * time1 < (360 - position2) * time2) {
			swap(position1, position2);
			swap(time1, time2);
		}
		cout << "Case #" << test << ": " << ((360 - position1) * time1 - (360 - position2) * time2 >= time2 * 360) << '\n';
	}
	return 0;
}
