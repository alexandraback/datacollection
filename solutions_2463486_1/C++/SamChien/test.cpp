#include <iostream>
using namespace std;

bool isPal(long long num) {
	long long reverse = 0;

	for (long long i=num; i!=0; i/=10)
		reverse = reverse * 10 + i % 10;
	if (num == reverse)
		return true;
	else
		return false;
}

int main() {
	long long n;

	cin >> n;
	for (long long i=1; i<=n; i++) {
		long long a, b;
		long long countAns = 0;

		cin >> a >> b;
		for (long long j=1;; j++) {
			long long square;

			square = j * j;
			if (square >= a && square <= b) {
				if (isPal(j) && isPal(square))
					countAns++;
			}
			else if (square > b)
				break;
		}
		cout << "Case #" << i << ": " << countAns << endl;
	}
	return 0;
}
