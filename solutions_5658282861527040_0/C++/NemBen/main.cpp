#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int main() {
	int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
		unsigned int A, B, K; cin >> A >> B >> K;

		int cnt =  0;
		for (int i = 0; i < A; ++i) {
			for (int j = 0; j < B; ++j) {
				unsigned int C = i&j;
				if (C < K) {
					++cnt;
				}
			}
		}
				
		cout << "Case #" << t << ": " << cnt << endl;
		
    }
}