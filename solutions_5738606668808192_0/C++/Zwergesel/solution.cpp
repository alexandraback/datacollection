#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORVEC(it,v) for (auto it=(v).begin(); it != (v).end(); ++it)
#define NUL(arr) memset(arr, 0, sizeof(arr));
#define SORT(x) sort((x).begin(), (x).end());

const ll MAX = 500;
vector<ll> primes;
bool isprime[MAX];

void sieve()
{
	fill(isprime, isprime+MAX, true);
	isprime[0] = isprime[1] = false;
	
	ll m = (ll) ceil(sqrt(MAX));
	for (ll i=2; i<m; i++) {
		if (isprime[i]) {
			for (ll j=i*i; j<MAX; j+=i) isprime[j] = false;
		}
	}
	for (ll i=2; i<MAX; i++) {
		if (isprime[i]) primes.push_back(i);
	}
}

bool test(ll n)
{
	string bits;
	stringstream ss;
	ss << bitset<16>(n);
	ss >> bits;
	ll divs[11] = {0};
	bool correct = true;
	for (ll b=2; b<=10; ++b) {
		n = 0;
		ll m = 1;
		for (int p=bits.size() - 1; p>=0; --p) {
			if (bits[p] == '1') n += m;
			m *= b;
		}
		//cout << bits << " in base " << b << " is " << n << endl;
		divs[b] = 0;
		for (ll p : primes) {
			if (n % p == 0) {
				divs[b] = p;
				//cout << "Divisor of " << n << " is " << p << endl;
				break;
			}
		}
		if (divs[b] == 0) {
			correct = false;
			break;
		}
	}
	if (correct) {
		cout << bits;
		for (int b=2; b<=10; ++b) {
			cout << " " << divs[b];
		}
		cout << endl;
	}
	return correct;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	
	int op = 0;
	cout << "Case #1:\n";
	for (ll i=(1<<15)+1; i<(1<<16); i+=2) {
		if (test(i)) {
			if (++op == 50) break;
		}
	}
	
	return 0;
}
