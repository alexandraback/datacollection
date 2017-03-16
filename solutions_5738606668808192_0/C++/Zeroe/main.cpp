// Vladimir Burian, 2016 (vladaburian@gmail.com)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include <algorithm>
#include <cmath>

#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#undef NDEBUG
#include <assert.h>

using namespace std;

typedef long long int ll;

ifstream in;
ofstream out;

std::vector<ll> primes;

std::vector<ll> get_primes(ll n)
{
	std::vector<ll> primes;
	std::vector<bool> sieve(n+1, false);

	for (ll i=2; i<=n; ++i) {
		if (!sieve[i]) {
			primes.push_back(i);

			for (ll j=i; j<=n; j+=i) {
				sieve[j] = true;
			}
		}
	}

	return primes;
}

ll get_divisor(ll n)
{
	for (ll p: primes) {
		if (n % p == 0) {
			return p;
		}
	}

	return 0;
}

ll coin_in_base(ll n, ll base)
{
	if (base == 2) return n;

	ll r = 0;
	for (ll d=1; n; n>>=1, d*=base) r += (n&1) ? d : 0;
	return r;
}

std::string coin_to_string(ll coin, int N)
{
	std::string r(N,' ');
	for (int i=N-1; i>=0; --i, coin>>=1) {
		r[i] = (coin&1) ? '1' : '0';
	}
	return r;
}


void solve()
{
	out << "\n";

	int N, J;
	in >> N;
	in >> J;

	ll min_coin = 1 + (1LL << (N-1));
	ll max_coin = (1LL << N) - 1;
	int n_coins = 0;

	ll max_prime = sqrt((double)max_coin) + 10;
	primes = get_primes(max_prime);

	cout << "primes up to " << max_prime << " done (" << primes.size() << ")\n";

	ll coin = max_coin;
	ll proof[11];

	for (; coin >= min_coin; coin -= 2) {
		//cout << coin << "\n";

		bool valid = true;

		for (int b=2; b<=10; ++b) {
			proof[b] = get_divisor(coin_in_base(coin, b));

			if (!proof[b]) {
				valid = false;
				break;
			}
		}

		if (!valid) continue;
		cout << "BINGO!\n";

		std::string coin_str = coin_to_string(coin, N);
		out << coin_to_string(coin, N);

		assert(coin_str.front() == '1');
		assert(coin_str.back() == '1');

		for (int b=2; b<=10; ++b) {
			out << " " << proof[b];
			assert(coin_in_base(coin,b) % proof[b] == 0);
		}

		out << "\n";

		if (++n_coins >= J) break;
	}
}

int main()
{
	string name = "C-small-attempt0";

	in.open((name + ".in").c_str());
	out.open((name + ".out").c_str());

    int T;
    in >> T;
    for (int i = 1; i <= T; i++) {
    	cout << "Case #" << i << "\n";

        out << "Case #" << i << ": ";
        solve();
        out << '\n';

        cout << " DONE\n";
    }

    in.close();
    out.close();

    return 0;
}
