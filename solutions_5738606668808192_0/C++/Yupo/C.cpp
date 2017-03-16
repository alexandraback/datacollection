#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

#define PMAX ((uint)1 << 30)

bool nprimes[PMAX + 1] = {};
uint primes[PMAX / 8];
int primesc = 0;

void push_primes(uint n) {
	primes[primesc++] = n;
}

bool is_prime(ull n) {
	if (n <= PMAX) {
		return !nprimes[n];
	}
	else {
		REP(i, primesc) if (n % primes[i] == 0) return false;
		ull m = sqrt(n) + 1;
		for (ull i = primes[primesc - 1]; i <= m; i += 2) if (n % i == 0) return false;
		return true;
	}
}

void init_primes() {
	nprimes[0] = nprimes[1] = true;
	for (uint i = 2; i <= PMAX; ++i) {
		if (!nprimes[i]) {
			push_primes(i);
			for (uint j = i * 2; j <= PMAX; j += i) {
				nprimes[j] = true;
			}
		}
	}
}

#define SAVE_ARR(var) {ofstream ofs(#var, ios::out | ios::binary); ofs.write((char *)var, sizeof(var));}
#define SAVE(var) {ofstream ofs(#var, ios::out | ios::binary); ofs.write((char *)&var, sizeof(var));}
#define LOAD_ARR(var) {ifstream ifs(#var, ios::in | ios::binary); ifs.read((char *)var, sizeof(var));}
#define LOAD(var) {ifstream ifs(#var, ios::in | ios::binary); ifs.read((char *)&var, sizeof(var));}

void save() {
	SAVE_ARR(nprimes)
	SAVE_ARR(primes)
	SAVE(primesc)
}

void load() {
	LOAD_ARR(nprimes)
	LOAD_ARR(primes)
	LOAD(primesc)
}

ull base(ull v, ull b) {
	if (b == 2) return v;
	ull res = 0, mask = 1, d = 1;
	REP(i, 32) {
		if ((v & mask) != 0) res += d;
		d *= b;
		mask <<= 1;
	}
	return res;
}

string bin(uint v) {
	stringstream res;
	uint mask = ((uint)1) << 31;
	while (mask > 1 && (v & mask) == 0) mask >>= 1;
	while (mask > 0) {
		res << (((v & mask) == 0) ? '0' : '1');
		mask >>= 1;
	}
	return res.str();
}

void solve() {
	int N, J;
	cin >> N >> J;
	ll begin = (1 << (N - 1)) + 1, end = (1 << N) - 1;
	for (ll i = begin; J > 0 && i <= end; i += 2) {
		ull b[11];
		for (uint j = 2; j <= 10; ++j) b[j] = base(i, j);
		for (uint j = 2; j <= 10; ++j) {
			cerr << bin(i) << " base " << j << " is " << b[j] << endl;
		}
		bool jamcoin = true;
		for (uint j = 2; j <= 10; ++j) {
			if (is_prime(b[j])) {
				jamcoin = false;
				break;
			}
		}
		if (jamcoin) {
			cout << bin(i);
			for (uint j = 2; j <= 10; ++j) {
				for (ull k = 2; k < b[j]; ++k) {
					if (b[j] % k == 0) {
						cout << " " << k;
						break;
					}
					if (k == b[j] - 1) {
						cerr << "wrong answer!" << endl;
					}
				}
			}
			cout << endl;
			--J;
		}
	}
}

int main(int argc, char **argv) {
	load();
	//init_primes();
	//save();

	int T;
	cin >> T;

	REP(i, T) {
		cout << "Case #" << (i + 1) << ":" << endl;
		solve();
	}

	return 0;
}
