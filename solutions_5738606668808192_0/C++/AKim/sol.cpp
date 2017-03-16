#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

bool check(ll u) {
	for(int i = 2; i <= 10; i++) {
		bool ok = 0;
		for(int j = 0; j < 30; j++) {
			ll v = u;
			ll c = 0, st = 1;
			while(v) {
				if(v & 1) {
					c += st;
					c %= primes[j];
				}
				st *= i;
				st %= primes[j];
				v >>= 1;
			}
			if(c == 0) {
				ok = 1;
				break;
			}
		}
		if(!ok) {
			return(0);
		}
	}
	return(1);
}

string bin(ll u) {
	string s;
	while(u) {
		s.pb('0' + (u & 1));
		u >>= 1;
	}
	reverse(s.begin(), s.end());
	return(s);
}

void chprprimes(ll u) {
	for(int i = 2; i <= 10; i++) {
		bool ok = 0;
		for(int j = 0; j < 30; j++) {
			ll v = u;
			ll c = 0, st = 1;
			while(v) {
				if(v & 1) {
					c += st;
					c %= primes[j];
				}
				st *= i;
				st %= primes[j];
				v >>= 1;
			}
			if(c == 0) {
				ok = 1;
				printf("%lld ", primes[j]);
				break;
			}
		}
		if(!ok) {
			return;
		}
	}
	return;
}

int main() {

	#ifdef SOL
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	printf("Case #1:\n");
	ll cnt = 0;
	for(ll i = 0; i < (1 << 14) && cnt < 50; i++) {
		ll j = (1ll << 15) | (i << 1) | (1ll << 0);
		if(check(j)) {
			cnt++;
			printf("%s ", bin(j).c_str());
			chprprimes(j);
			printf("\n");
		}
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim
