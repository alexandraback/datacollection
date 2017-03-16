#include <iostream>

#include "digitsSet.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	int T;
	cin >> T;
	for (int t=0; t<T; ++t) {
		cout << "Case #" << t+1 << ": ";
		
		long long basenumber;
		cin >> basenumber;
		if (basenumber == 0) {
			cout << "INSOMNIA\n";
			continue;
		}
		
		long long number = 0;
		dSet digits;
		
		while (digits.size() < 10) {
			number += basenumber;
			dSet newdigits;
			newdigits = digitsSet(number,10);
			digits.insert(newdigits.begin(), newdigits.end());
		}
		cout << number << "\n";
	}
	return 0;
} 
