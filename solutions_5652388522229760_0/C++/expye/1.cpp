#include <iostream>
#include <cstring>
using namespace std;
long long T;
bool occur[10];
int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		long long n;
		cin >> n;
		if (n == 0)
			cout <<"INSOMNIA" << endl;
		else {
			memset(occur, 0, sizeof(occur));
			int rest = 10;
			long long kn = 0;
			while (rest) {
				kn += n;
				for (long long t = kn; t != 0; t = t / 10) {
					if (!occur[t % 10]) rest--, occur[t % 10] = true;
				}
			}
			cout << kn << endl;
		}
	}
	return 0;
}