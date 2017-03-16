#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	//find some primes
	vi primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
	for (int i = 25; i < 2000; i += 2){
		bool isPrime = true;
		for (int prime : primes){
			if (i % prime == 0){
				isPrime = false;
				break;
			}
			else if (prime * prime > i){
				break;
			}
		}//end testing primeness

		if (isPrime){
			primes.push_back(i);
		}
	}//end prime gathering

	int t;
	cin >> t;

	//for each case
	for (int i = 1; i <= t; ++i){
		cout << "Case #" << i << ":" << endl;
		int n, j;
		cin >> n >> j;

		//represents the coin
		vi jam(n, 0);
		jam[0] = jam[n - 1] = 1;

		//print j coins
		int coins = 0;
		while (coins < j){

			bool mightBePrime = false;
			vi divs;

			//check the jamcoin we have
			for (int base = 2; base < 11; ++base){

				//assemble value in base
				unsigned long long value = 0;
				for (int i = 0; i < jam.size(); ++i){
					value *= base;
					value += jam[i];
				}

				//check primeness
				for (int i = 0; i < primes.size(); ++i){
					if (value % primes[i] == 0){
						divs.push_back(primes[i]);	//found a divisor
						break;
					}
				}

				//see if we found that divisor
				if (divs.size() < base - 1){
					mightBePrime = true;
					break;
				}
			}//end checking bases

			//print if definitely not prime
			if (!mightBePrime){
				for (int i = 0; i < jam.size(); ++i){
					cout << jam[i];
				}
				for (int i = 0; i < divs.size(); ++i){
					cout << " " << divs[i];
				}
				cout << endl;
				++coins;
			}

			//whether or not that succeeded, go to next jamcoin
			int addPlace = jam.size() - 2;
			while (addPlace > 0){
				if (jam[addPlace]){
					jam[addPlace] = 0;
					--addPlace;
				}
				else{
					jam[addPlace] = 1;
					break;
				}
			}
		}//end while haven't printed all coins

	}//end test cases
	return 0;
}
