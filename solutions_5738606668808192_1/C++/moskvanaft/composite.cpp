#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
#include <cassert>

#include <boost/multiprecision/cpp_int.hpp>

//typedef unsigned cpp_int __attribute__ ((mode (TI)));

using namespace std;

using namespace boost::multiprecision;

inline cpp_int powmod(cpp_int base, cpp_int power, cpp_int mod) {
  cpp_int res = 1;
  cpp_int fac = base;
  while (power) {
    if (power & 1) {
      res = (res*fac)%mod;
    }
    fac = (fac*fac)%mod;
    power >>= 1;
  }
  return res%mod;
}

inline bool composite(cpp_int n, int tries = 10){
  if (n > 3) {
    for (int i = 0; i < tries; ++i){
      cpp_int x = rand()%(n-1)+1; 
      if (powmod(x, n-1, n) != 1) { 
	return true;
      }
    }
  }
  return false;
}

inline array<cpp_int, 9> convert(cpp_int n) {
  array<cpp_int, 9> res;
  res.fill(0);
  res[0] = n;
  //cpp_int mask = 0x8000000000000000;
  cpp_int mask = 0x80000000;
  while (mask) {
    if (n & mask) {
      for (size_t i = 1; i < 9; ++i) {
	res[i] = res[i]*(i+2)+1; //base 2 to 10
      }
    } else if (res[1] > 0) {
      for (size_t i = 1; i < 9; ++i) {
	res[i] = res[i]*(i+2); //base 2 to 10
      }
    }
    mask >>= 1;
  }
  return res;
}

string to_str(cpp_int x) {
  string s;
  s.reserve(32);
  while (x) {
    s.push_back((x & 1) ? '1' : '0');
    x >>= 1;
  }
  reverse(s.begin(), s.end());
  return s;
}

static array<cpp_int, 168> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };

cpp_int find_divisor(cpp_int n) {
  for (auto p : primes) {
    if (n%p == 0) {
      return p;
    }
  }
  return 0;
}

void test() {
  assert(false == composite(0));
  assert(true == composite(4));
  assert(false == composite(5));
  assert(true == composite(10));
  assert(false == composite(11));

  assert(false == composite(137));
  assert(false == composite(151));
  assert(false == composite(991));

  assert(false == composite(139));
  assert(true == composite(993));

  typedef array<cpp_int, 9> V;
  assert(V({9, 28, 65, 126, 217, 344, 513, 730, 1001}) == convert(9));
}

int main(int argc, char** argv) {
  if (argc == 2 && string(argv[1]) == "-test") {
    test();
    return 0;
  }
  size_t N;
  cin >> N;
  for (size_t i = 1; i <= N; ++i) {
    uint32_t n = 0, j = 0;
    cin >> n >> j;
    cout << "Case #" << i << ":" << endl;
    cpp_int x = (cpp_int(1) << (n-1))+1;
    size_t found = 0;
    //while (x < (1 << n)) {
    while (found < j) {
      auto arr = convert(x);
      array<cpp_int, 9> divs;
      divs.fill(0);
      size_t j = 0;
      for (; j < arr.size(); ++j) {
	if (!composite(arr[j], j+1)) {
	  break;
	}
	divs[j] = find_divisor(arr[j]);
	if (!divs[j]) {
	  break;
	}
      }
      if (j == arr.size()) {
	cout << to_str(x);
	//size_t K = 0;
	for (auto x : divs) {
	  //cout << ' ' << "(" << arr[K++] << ")=" << x;
	  cout << ' ' << x;
	}
	cout << endl;
	++found;
      }
      x += 2;
    }
  }
}
