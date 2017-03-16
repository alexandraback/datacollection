#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int T;
	cin >> T;

	for(int t = 0; t < T; t++) {
		int Smax;
		cin >> Smax;
		int count = 0, solution = 0;
		for(int s = 0; s <= Smax; ++s) {
			char c;
			cin >> c;
			int k = c - '0';
			if(not (count >= s)) {
				solution += s - count;
				count += s - count;
			}
			count += k;
		}
		cout << "Case #" << t+1 << ": " << solution << endl;
	}
	return 0;
}
