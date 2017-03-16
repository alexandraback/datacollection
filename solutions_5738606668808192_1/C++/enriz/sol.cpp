#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int nn, nj;

bool isPrime(int n){
	for (int i = 2; i * i <= n; ) {
		if (!(n % i)) {return false;}
		i += ((i == 2) ? 1 : 2);
	}
	return true;
}

int nextPrime(int i) {
	int j;
	for (j = i + 1; !isPrime(j); j += 2) {
	}
	return j;
}

std::vector<bool> vc(nn, false);
int maxN = 12345;

int divide(int b, int j){
	int r = 0;
	for (int q = 0; q < nn; ++q) {
		r = (r * b + vc[q]) % j;
	}
	return r;
}

int notPrime(int b) {
	for (int j = 2;j < maxN; ++j) {
		if (isPrime(j) && divide(b, j) == 0) {

			// for (int i = 0; i < nn; ++i) {
			// 	cerr << (vc[i] ? '1' : '0');
			// }
			// cerr << "Base " << b << " root" << j;
			// cerr << endl;
			return j;
		}
		j += (j != 2);
	}
	return 0;
}

bool inc(int pos) {
	if (pos > 0) {
		vc[pos] = !vc[pos];
		return (!vc[pos] ? inc(pos - 1) : true);
	}
	return false;
}

int testCase(){
	vc[0] = true;
	vc[nn - 1] = true; //jamicons end with 1
	std::vector<int> r(11, 0); //base 2 to 10;
	int c = 0;
	
	for (int c = 0; c < nj; ) {
		int count = 0;
		for (int base = 2; base < r.size(); ++base) {
			r[base] = notPrime(base);
			if (!r[base])
				break;
			++count;
		}
		// for (int q = 0; q < nn; ++q) {
		// 	for (int base = 2; base < r.size(); ++base) {
		// 		r[base] = r[base] * base + vc[q];
		// 	}
		// }

		//change vc somehow
		if (count == 9) {
			for (int i = 0; i < nn; ++i) {
				cout << (vc[i] ? '1' : '0');
			}
			for (int b = 2; b < r.size(); ++b) {
				cout << ' ' << r[b];			
			}
			cout << endl;
			++c;
		}
		if (!inc(nn - 2)) {
			cerr << "finished" << endl;
		}
	}
}

int main(){
	int l;

	cin >> l;
	//cerr << "nt " << l;
	for (int i = 0; i < l; ++i) {
		cin >> nn >> nj;
		cout << "Case #" << (i + 1) << ": "<< endl;
		testCase();
	}
	return 0;
}