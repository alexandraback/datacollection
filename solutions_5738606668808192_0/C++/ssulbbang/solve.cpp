#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
int n, m;
vector<int> primes;		


void run(string coin, vector< vector<int> > digit, vector< vector<int> > r0) {
	if(m == 0) return;

	if(coin.size() == n) {
		vector<int> divisors;
		for(int i = 2; i <= 10; i++) {
			bool found = false;
			for(int j = 0; j < primes.size(); j++) {
				if(r0[i][j] == 0) {
					divisors.push_back(primes[j]);
					found = true;
					break;
				}
			}
			if(!found) break;
		}
		if(divisors.size() == 9) {
			cout << coin << " ";
			for(int i = 0; i < 9; i++) {
				cout << divisors[i] << " ";
			}
			cout << endl;
			m--;
		}
		return;
	}

	vector< vector<int> > r1 = r0;
	for(int i = 2; i <= 10; i++) {
		for(int j = 0; j < primes.size(); j++) {
			r1[i][j] = (r0[i][j] + digit[i][j]) % primes[j];
			digit[i][j] = (digit[i][j] * i) % primes[j];
		}
	}

	run("1" + coin, digit, r1);
	if(coin.size() < n - 1) run("0" + coin, digit, r0);	
}

void find_jamcoins() {
	vector< vector<int> > digit;
	vector< vector<int> > r;
	r.resize(11);
	digit.resize(11);
	for(int i = 2; i <= 10; i++) {
		digit[i].resize(primes.size());
		for(int j = 0; j < primes.size(); j++) {
			digit[i][j] = i % primes[j];
		}
		
		r[i].resize(primes.size(), 1);
	}

	run("1", digit, r);
}

int main(int argc, char** argv) {
	ifstream fin(argv[1]);
	int t;
	fin >> t;

	for(int i = 2; i < 100; i++) {
		bool prime = true;
		for(int j = 2; j < i; j++) {
			if(i % j == 0) {
				prime = false;
				break;
			}
		}

		if(prime) {
			primes.push_back(i);
		}
	}

	for(int i = 1; i <= t; i++) {
		fin >> n >> m;
		cout << "Case #" << i << ":" << endl;
		find_jamcoins();
	}

	return 0;
}