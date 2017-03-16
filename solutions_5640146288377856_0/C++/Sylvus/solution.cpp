#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main () {
	size_t numTestCases;
	cin >> numTestCases;
	for (size_t i=0; i<numTestCases; ++i) {
		int T,R,C;
		cin >> R >> T >> C;
		int min_steps = 0;

		min_steps = (T / C + C);
		if (T%C == 0) {
			min_steps--;
		}
		min_steps = R * min_steps;



		cout << "Case #" << (i+1) << ": " << min_steps << endl; 
	}
}
