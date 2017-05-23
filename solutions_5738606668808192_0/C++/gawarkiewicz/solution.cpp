#include <vector>
#include <iostream>

using namespace std;

vector<long long> primes;

long long fromBase(long long& num, int base) {
	long long ret = 0;
	for (int i=31; i>=0; --i) {
		ret = ret * base + ((num & (1ll << i)) ? 1 : 0);
	}
	return ret;
}

long long divider(long long num) {
	for (auto& p : primes) {
		if (p >= num) break;
		if (num % p == 0) return p;
	}
	return 1;
}

bool check(long long num, vector<long long>& out) {
	for (int i = 2; i <= 10; ++i) {
		out[i] = divider(fromBase(num, i));
		if (out[i] == 1) return false;
	}
	return true;
}

int main() {
	{
		vector<bool> isPrime(1000000, true);
		for (long long i = 2; i < isPrime.size(); ++i) {
			if (isPrime[i]) {
				primes.push_back(i);
				for (long long j = i*i; j < isPrime.size(); j += i) {
					isPrime[j] = false;
				}
			}
		}
	}

	int T, N, J;
	cin >> T >> N >> J;
	cout << "Case #1:" << endl;
	vector<long long> out(11);
	for (int i = 0; i < (1 << (N-2)) && J; ++i) {
		long long num = (1ll << (N-1)) | (i << 1) | 1;
		long long num10 = fromBase(num, 10);
		if (check(num, out)) {
			cout << num10;
			for (int d = 2; d <= 10; ++d) cout << " " << out[d];
			cout << endl;
			--J;
		}
		else {
			//cout << "\t" << num10 << endl;
		}
	}
	return 0;
}