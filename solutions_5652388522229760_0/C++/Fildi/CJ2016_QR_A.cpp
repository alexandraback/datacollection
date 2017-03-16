// CJ2016_QR_A.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;		
		cout << "case #" << i + 1 << ": ";
		int bits = 0;
		if (n != 0) {
			int result = 0;
			while (bits != (1 << 10) - 1) {
				result += n;
				int k = result;
				while (k > 0) {
					int d = k % 10;
					k /= 10;		
					bits |= 1 << d;
				}
			}
			cout << result;
		}
		else
			cout << "INSOMNIA";
		cout << endl;

	}

	return 0;
}

