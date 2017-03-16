#include <iostream>
using namespace std;

int db = 0;
bool used[10];

void parse(long long x) {
	while(x) {
		if(!used[x%10]) {
			used[x%10] = true;
			++db;
		}
		x /= 10;
	}
}

int main() {
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i) {
		long long s;
		cin >> s;
		for(int j = 0; j < 10; ++j) used[j] = false;
		db = 0;
		if(s == 0) {
			cout << "Case #" << i << ": INSOMNIA\n";
			continue;
		}
		long long r = s;
		while(db < 10) {
			parse(r);
			r += s;
		}
		r -= s;
		cout << "Case #" << i << ": " << r << "\n";
	}
	return 0;
}