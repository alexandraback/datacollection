#include <iostream>
#include <etc/cppformat/format.cc>

using namespace std;

int prime[7000000], prime_cnt;
void initPrime();
int isPrime(long long);

void makeJamCoin(int, int);

int main() {
	ios::ios_base::sync_with_stdio(false);
	initPrime();

	int tc;
	cin >> tc;

	for(int i = 1 ; i <= tc ; ++i) {
		int l, n;
		cin >> l >> n;
		cout << fmt::format("Case #{}:", i) << endl;
		makeJamCoin(l, n);
	}

	return 0;
}

void initPrime() {
	const int P_MAX = 11111111;

	prime[0] = 2;
	prime[1] = 3;
	prime_cnt = 2;

	for(int i = 5 ; i < P_MAX ; i += 4) {
		if( !isPrime(i) ) {
			prime[prime_cnt] = i;
			++prime_cnt;
		}
		i += 2;
		if( i >= P_MAX ) break;
		if( !isPrime(i) ) {
			prime[prime_cnt] = i;
			++prime_cnt;
		}
	}
}

int isPrime(long long x) {
	for(int i = 0 ; i < prime_cnt && prime[i] * (long long)prime[i] <= x ; ++i) {
		if( x % prime[i] == 0 ) {
			return prime[i];
		}
	}

	return 0;
}

int lmax;
int d[17], cnt;

void maker(int p) {
	if( cnt <= 0 ) return;

	if( p == lmax - 1 ) {
		int arr[11];

		for(int k = 2 ; k <= 10 ; ++k) {
			long long x = 0;
			for(int i = 0 ; i < lmax ; ++i) {
				x *= k;
				x += d[i];
			}

			arr[k] = isPrime(x);
			if( !arr[k] ) {
				return;
			}
		}

		for(int i = 0 ; i < lmax ; ++i) {
			cout << d[i];
		}
		for(int i = 2 ; i <= 10 ; ++i) {
			cout << " " << arr[i];
		}
		cout << endl;
		--cnt;

		return;
	}

	d[p] = 0;
	maker(p+1);
	d[p] = 1;
	maker(p+1);
}

void makeJamCoin(int l, int n) {
	cnt = n;
	lmax = l;
	d[0] = 1;
	d[lmax-1] = 1;
	maker(1);
}