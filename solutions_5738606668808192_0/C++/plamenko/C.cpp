#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#define _SCL_SECURE_NO_WARNINGS

//#define _CRT_RAND_S

//#include <windows.h>
//#include <tchar.h>
//#include <atlbase.h>
//#include <winerror.h>

//#define BOOST_FILESYSTEM_NO_DEPRECATED
//#include <boost/filesystem.hpp>
//#include <boost/filesystem/fstream.hpp>
//#include <boost/regex.hpp>
//#include <boost/algorithm/string.hpp>

#include <type_traits>
#include <stdint.h>
#include <climits>
#include <ctime>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <bitset>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <ppl.h>

#include <unordered_set>
#include <unordered_map>

#include "gmp_helpers.h"

#include "concurrency/concurrency.h"
#include "algorithm/collections/collections.h"
#include "algorithm/math/base.h"
#include "algorithm/math/combinatorics.h"
#include "algorithm/math/comb_primes.h"
#include "algorithm/math/modulos.h"
#include "algorithm/math/polynoms.h"
#include "algorithm/math/primes.h"
#include "algorithm/math/recurrence.h"
#include "algorithm/math/reduce.h"
#include "structure/math/fraction.h"
#include "structure/math/matrix.h"
#include "structure/math/modulo.h"
#include "structure/math/polynom.h"
#include "structure/math/prime_holder.h"
#include "structure/math/quadratic.h"
#include "structure/math/vectorNd.h"

using namespace std;
using namespace tr1;
using namespace concurrency;

using namespace altruct::math;
using namespace altruct::collections;
using namespace altruct::concurrency;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;

typedef moduloX<int> modx;
typedef modulo<int, 1000000007> mod;
typedef polynom<mod> poly;
typedef moduloX<poly> polymod;

// uses my own open source library: https://github.com/plamenko/altruct

mpz to_base(int b, ll n) {
	mpz r = 0, w = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) r += w;
		w *= b;
	}
	return r;
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, j;
		cin >> n >> j;
		printf("Case #%d:\n", t);
		ll r = (1 << (n - 1)) | 1;
		while (j > 0 && r < (1 << n)) {
			vector<mpz> vd;
			for (int b = 2; b <= 10; b++) {
				mpz v = to_base(b, r);
				mpz d = pollard_rho_repeated<mpz>(v, 20, 1000);
				if (d == 0 || d == 1 || d == v || v % d != 0) break;
				vd.push_back(d);
			}
			if (vd.size() == 9) {
				gmp_printf("%Zd", to_base(10, r).get_mpz_t());
				for (const auto& d : vd) {
					gmp_printf(" %Zd", d.get_mpz_t());
				}
				gmp_printf("\n");
				j--;
			}
			r += 2;
		}
	}
	return 0;
}
