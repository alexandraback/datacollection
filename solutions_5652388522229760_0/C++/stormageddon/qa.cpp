#include <iostream>
#include <string>

using namespace std;

int main() {
	int cases=0;
	cin >> cases;
	int caseNum=0;
	while (caseNum < cases) {
		caseNum++;
		cout << "Case #" << caseNum << ": ";
		int unseen=0;
		long n=0;
		cin >> n;
		if (n==0) {
			cout << "INSOMNIA" << endl;
		} else {
			unsigned long long last = 0;
			do {
				last+=n;
				unsigned long long temp = last;
				while (temp > 0) {
					unseen|=(1 << (temp%10));
					temp/=10;
				}
			} while (unseen!=1023);
			cout << last << endl;
		}
	}
	return 0;
}

