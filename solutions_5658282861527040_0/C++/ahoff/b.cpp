//Google Code Jam  2014
//Round 1B
//B

#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int count = 1; count <= T; count++) {
		int a, b, k;
		cin >> a >> b >> k;
		int sol = 0;
		for(int i = 0; i < a; i++) for(int j = 0; j < b; j++) if((i&j) < k) sol++;
		cout << "Case #" << count << ": " << sol << endl;
	}
}
