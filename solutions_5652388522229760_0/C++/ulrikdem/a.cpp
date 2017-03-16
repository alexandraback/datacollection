#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		cout << "Case #" << test << ": ";
		int n, count = 0;
		cin >> n;
		if(n == 0) {
			cout << "INSOMNIA\n";
			continue;
		}
		vector<bool> seen(10);
		for(int i = 1; true; ++i) {
			int temp = i * n;
			while(temp) {
				if(!seen[temp % 10]) {
					seen[temp % 10] = true;
					++count;
				}
				temp /= 10;
			}
			if(count == 10) {
				cout << i * n << '\n';
				break;
			}
		}
	}
	return 0;
}
