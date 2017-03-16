#include <iostream>
using namespace std;

bool isPal(int num) {
	int reverse = 0;

	for (int i=num; i!=0; i/=10)
		reverse = reverse * 10 + i % 10;
	if (num == reverse)
		return true;
	else
		return false;
}

int main() {
	int n;

	cin >> n;
	for (int i=1; i<=n; i++) {
		int a, b;
		int countAns = 0;

		cin >> a >> b;
		for (int j=1;; j++) {
			int square;

			if (isPal(j)) {
				square = j * j;
				if (square >= a && square <= b) {
					if (isPal(square))
						countAns++;
				}
				else if (square > b)
					break;
			}
		}
		cout << "Case #" << i << ": " << countAns << endl;
	}
	return 0;
}
