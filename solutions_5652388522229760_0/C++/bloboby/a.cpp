#include <iostream>
#include <numeric>

using namespace std;

int sheep(int N) {
	if (N == 0) return 0;
	
	bool found[10];
	for (int i=0; i<10; i++) found[i] = false;
	
	int m = N;
	while (accumulate(found, found+10, 0) < 10) {
		int k = m;
		while (k > 0) {
			found[k % 10] = true;
			k /= 10;
		}
		m += N;
	}
	
	return m - N;
}

int main() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		int N;
		cin >> N;
		int s = sheep(N);
		cout << "Case #" << i+1 << ": ";
		if (s == 0) cout << "INSOMNIA" << endl;
		else cout << s << endl;
	}
	return 0;
}