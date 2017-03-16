#include <iostream>
#include <cmath>

using namespace std;

void fractile() {
	long long K, C, S;
	cin >> K >> C >> S;
	long long m = pow(K, C-1);
	for (long long i=0; i<S; i++) cout << " " << 1 + m*i;
	cout << endl;
	return;
}

int main() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		cout << "Case #" << i+1 << ":";
		fractile();
	}
	return 0;
}