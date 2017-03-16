#include <bits/stdc++.h>
using namespace std;

typedef long long int intt;
vector<intt> primes;
intt prime(intt in) {
	for(intt i = 0; i < primes.size() && primes[i] * primes[i] <= in; i++) {
		if(in % primes[i] == 0) return false;
	}
	return true;
}

intt parse(int m, int b) {
	intt res = 0;
	intt p = 1;
	for(int i = 0; i < 16; i++) {
		if(m & (1 << i)) {
			res += p;
		}
		p *= b;
	}
	return res;
}

int main() {
	primes.push_back(2);
	intt counter = 3;
	for(int i = 1; i < 100000; i++) {
		if(prime(counter)) {
			primes.push_back(counter);
		}
		counter += 2;
	}
	cerr << "done primegen" << endl;
	int j = 0;
	cout << "Case #1:" << endl;
	for(int m = 0x8001; m < 0x10000 && j < 50; m += 2) {
		for(int b = 2; b <= 10; b++) {
			intt val = parse(m, b);
			if(prime(val)) goto next;
		}

		for(int i = 15; i >= 0; i--) {
			if(m & (1 << i)) {
				cout << '1';
			} else {
				cout << '0';
			}
		}
		for(int b = 2; b <= 10; b++) {
			intt val = parse(m, b);
			for(int i = 0; i < primes.size(); i++) {
				if(val % primes[i] == 0) {
					cout << " " << primes[i];
					break;
				}
			}
		}
		cout << endl;
		j++;

		next:;
	}
}
