#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int64_t Ncase;
	cin >> Ncase;
	ostringstream output;
	for (int64_t i1 = 1; i1 <= Ncase; ++i1){
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		output << "Case #" << i1 << ": ";
		int JP = J * P;
		int JS = J * S;
		int PS = P * S;
		int JPS = JP*S;
		int m = min(JP,JS);
		m = min(m,PS);
		m = min(m * K, JPS);
		int count = 1;
		output << m << endl;
		bool cont = true;
		int j = 0;
		int reset = 0;
		while (cont) {
			if (j >= J) {
				j = 0;
				reset += 1;
			}
			for (int p = 0; p < P; ++p) {
				int s = j + p + 2*reset;
				int p2 = p + reset;
				while (s >= S) {
					s -= S;
				}
				if (p2 > P) {
					p2 -= P;
				}
				output << j+1 << ' ' << p2+1 << ' ' << s+1 << endl;
				
				count += 1;
				if (count > m) {
					cont = false;
					break;
				}
			}
			if (!cont) break;
			++j;
		}
	}
	cout << output.str();
	return 0;
}
