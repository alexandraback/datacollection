#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <strings.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <strings.h>
#include <string.h>

#define isOn(S, j) (S & (1ll << j))

using namespace std;

unsigned long long modpow(unsigned long long base, unsigned long long exp, unsigned long long modulus) {
  base %= modulus;
  unsigned long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

bool isPrime(vector<bool> &rep, unsigned long long base, unsigned long long &factor){
	unsigned long long limit = 1000;//Enough to generate 500 numbers in every case
	if (rep.size() <= 13){
		limit = 0;
		for (int i = rep.size() - 1; i >= 0; i--){
			limit = limit * base;
			if (rep[i]){
				limit++;
			}
		}
	}
	for (unsigned long long i = 2; i * i <= limit; i++){
		unsigned long long ac = 0;
		for (unsigned long long j = 0; j < rep.size(); j++){
			if (rep[j]){
				ac = (ac + modpow(base, j, i)) % i;
			}
		}
		if (ac == 0){
			factor = i;
			return false;
		}
	}
	return true;
}

int main(){
	unsigned long long tests;
	cin >> tests;
	for (unsigned long long t = 0; t < tests; t++){
		cout << "Case #" << (t+1) << ": " << endl;
		unsigned long long N, J;
		cin >> N >> J;
		int printed = 0;
		for (unsigned long long current = (1ull << N) - 1; current > 1; current-=2){
			if (isOn(current, N - 1) == false){
				break;
			}
			vector<bool> rep(N);
			for (unsigned long long i = 0; i < N; i++){
				if (isOn(current, i)){
					rep[i] = true;
				} else {
					rep[i] = false;
				}
			}
			bool failed = false;
			vector<unsigned long long> factors;
			for (unsigned long long base = 2; base <= 10; base++){
				unsigned long long factor;
				if (isPrime(rep, base, factor)){
					failed = true;
					break;
				} else {
					factors.push_back(factor);
				}	
			}
			if (!failed){
				for (int i = rep.size() - 1; i >= 0; i--){
					if (rep[i]){
						cout << "1";
					} else {
						cout << "0";
					}
				}
				cout << " ";
				for (int j = 0; j < factors.size(); j++){
					cout << factors[j] << " ";
				}
				cout << endl;
				printed++;
				if (printed == J){
					break;
				}
			}
		}
	}
}
