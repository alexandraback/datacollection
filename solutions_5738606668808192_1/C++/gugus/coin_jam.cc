#include <pe.h>

vector<ll> primes;

ll is_composite(ll k) {
	ll i = 0;
	while (i < primes.size() and (k%primes[i++]) != 0) {}
	return primes[--i];
}

ll to_base(ll x, ll b) {
	ll res = 0;
	for (ll i = 0; i < 32; i++) {
		if ((x >> i) & 0x1 == 0x1) {
			res += (ll) pow(b, i);
		}
	}
	return res;
}

vector<ll> composite_in_all_bases(ll k) {
	vector<ll> result(9);
	for (ll b = 2; b < 11; b++) {
		ll kb = to_base(k, b);
		ll comp = is_composite(kb);
		if (kb == comp or comp == primes[primes.size()-1]) {
			result[0] = -1;
			return result;
		} else {
			result[b-2] = is_composite(kb);
		}
	}
	return result;
}

void print_base_2(ll k, ll n) {
	for (ll i = n-1; i > -1; i--) {
		printf("%Ld", (k & (0x1 << i)) >> i);
	}
}

int main() {
	ll t;
	scanf("%Ld\n", &t);
	for (ll i = 0; i < t; i++) {
		printf("Case #%Ld:\n", t);
		ll n, j, count = 0;
		scanf("%Ld %Ld\n", &n, &j);
		primesieve::generate_primes(2, (int) pow(2, 20)+1, &primes);
		// printf("isprime(tobase(37, 2)) = %Ld\n", is_prime(to_base(37, 2)));
		ll k = (ll) (pow(2, n-1) +1); // minimum for a jam coin of length n (first and last bit can't be 0)
		while (count != j) {
			vector<ll> res = composite_in_all_bases(k);
			// printf("k = %Ld and res[0] = %Ld\n", k, res[0]);
			if (res[0] != -1) {
				print_base_2(k, n);
				for (ll f : res) {
					printf(" %Ld", f);
				}
				printf("\n");
				count++;
			}
			k+=2;
		}
	}
	
	return 0;
}

