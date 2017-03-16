#include <iostream>

using namespace std;

void inss();

int b;
long long m;

long long k[51];

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) {
		cin >> b >> m;
		long long a = 1;
		k[b] = 1;
		for (int i = 1; i <= b - 1; i++) {
			k[b - i] = a;
			a *= 2;
		}
		cout << "Case #" << z << ": ";
		if (k[1] < m) {
			cout << "IMPOSSIBLE" << endl;
		}
		else if (k[1] == m) {
			cout << "POSSIBLE" << endl;
			a = 1;
			int c = 1;
			
			for (int i = 1; i <= b; i++) {
				for (int j = 1; j <= i; j++) {
					cout << "0";
				}
				for (int j = i + 1; j <= b; j++) {
					cout << "1";
				}
				cout << endl;
			}
		}
		else {
			cout << "POSSIBLE" << endl;
			a = 1;
			int c = 1;

			cout << "0";
			for (int i = 2; i <= b; i++) {
				if (m >= k[i]) {
					m -= k[i];
					cout << "1";
				}
				else {
					cout << "0";
				}
			}
			cout << endl;

			for (int i = 2; i <= b; i++) {
				for (int j = 1; j <= i; j++) {
					cout << "0";
				}
				for (int j = i + 1; j <= b; j++) {
					cout << "1";
				}
				cout << endl;
			}
		}
	}
	return 0;
}