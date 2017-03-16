#include <iostream> 
#include <stdlib.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int sMax;
		cin >> sMax;
		string level;
		cin >> level;
		long long count = 0;
		long long need = 0;
		for (int j = 0; j < level.length(); j++) {
			int n = (int)(level[j]) - 48;
			if (count >= j) {
				count += n;
			} else {
				need += j - count;
				count = j + n;
			}
		}
		cout << "Case #" << i + 1 << ": " << need << "\n";
	}
	return 0;
}