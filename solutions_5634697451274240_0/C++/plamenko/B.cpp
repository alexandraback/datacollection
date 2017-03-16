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

int calc(const char* w) {
	int r = 0;
	for (int i = 0; w[i]; i++) {
		if (w[i] != w[i + 1]) r++;
	}
	return r;
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		string w; cin >> w;
		while (w.back() == '+') w.pop_back();
		printf("Case #%d: %d\n", t, calc(w.c_str()));
	}
	return 0;
}
