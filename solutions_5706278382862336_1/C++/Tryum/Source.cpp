#include <iostream>
#include <vector>

using namespace std;

struct Fraction{
	long long P;
	long long Q;
};

int main(int argc, char** argv){
	vector<long> primes;
	primes.reserve(100);
	primes.push_back(2);
	int testCaseCount;
	cin >> testCaseCount;
	Fraction fractions[100];

	int num = 3;
	while (primes.size() != 1000){
		bool isPrime = true;
		for (size_t i = 0; i < primes.size(); ++i){
			if (num % primes[i] == 0){
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			primes.push_back(num);
		++num;
	}

	for (int i = 0; i < testCaseCount; ++i){
		char c;
		cin >> fractions[i].P;
		cin >> c;
		cin >> fractions[i].Q;
	}

	for (int i = 0; i < testCaseCount; ++i){
		for (int j = primes.size() - 1; j >= 0; --j){
			if (primes[j] > fractions[j].Q)
				continue;
			if (fractions[i].P % primes[j] == 0 && fractions[i].Q % primes[j] == 0){
				fractions[i].P /= primes[j];
				fractions[i].Q /= primes[j];
			}
		}
		Fraction parent = fractions[i];
		bool found = false;
		int gen = -1;
		for (int j = 0; j < 41; ++j){
			parent.P *= 2;
			if (parent.P == parent.Q){
				found = true;
				if (gen == -1)gen = j + 1;
				cout << "Case #" << i + 1 << ": " << gen << endl;
				break;
			}
			else if (parent.P > parent.Q){
				parent.P -= parent.Q;
				if (gen == -1)
					gen = j + 1;
			}

			for (int j = primes.size() - 1; j >= 0; --j){
				if (primes[j] > parent.Q)
					continue;
				if (parent.P % primes[j] == 0 && parent.Q % primes[j] == 0){
					parent.P /= primes[j];
					parent.Q /= primes[j];
				}
			}

		}
		if (!found){
			cout << "Case #" << i+1 << ": impossible" << endl;
		}
	}
}