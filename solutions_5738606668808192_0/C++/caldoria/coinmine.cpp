#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef vector<bool> coin_t;

set<coin_t> generated_candidates;

void print_coin(coin_t coin) {
  int n = coin.size();
  for (int i = n-1; i >= 0; i--) {
    cout << coin[i] ? "1" : "0";
  }
}

coin_t generate_coin() {
  coin_t next(16);
  next[0] = next[15] = true;
  for (int i = 1; i < 15; i++) {
    next[i] = (rand() % 2) == 1;
  }
  auto it = generated_candidates.find(next);
  if (it != generated_candidates.end()) {
    return generate_coin();
  } else {
    generated_candidates.insert(next);
    return next;
  }
}

long long in_base(int base, coin_t coin) {
  long long sum = 0;
  for (auto it = coin.begin(); it != coin.end(); it++) {
    if (*it) {
      sum += pow(base, it - coin.begin());
    }
  }
  return sum;
}

vector<int> find_divisors(coin_t coin) {
  vector<int> divisors(11);
  
  for (int i = 2; i <= 10; i++) {
    long long N = in_base(i, coin);
    long long sqrtN = sqrt(N);
    divisors[i] = -1;
    for (int d = 2; d <= sqrtN+1; d++) {
      if ((N % d) == 0) {
	divisors[i] = d;
	break;
      }
    }
    if (divisors[i] == -1) break;
  }

  return divisors;
}

int main(int argc, char** argv) {
  int T, N, J;

  cin >> T >> N >> J;
  
  set<coin_t> found_coins;
  map<coin_t, vector<long long> > divisors;

  cout << "Case #1:" << endl;
  
  for (int i = 0; i < J; i++) {
    bool found = false;

    vector<int> divisors;
    coin_t next;
    
    while (!found) {
      next = generate_coin();
      divisors = find_divisors(next);

      found = true;
      for (auto it = divisors.begin()+2; it != divisors.end(); it++) {
	if (*it == -1) {
	  found = false;
	  break;
	}
      }
    }

    print_coin(next);
    for (int i = 2; i <= 10; i++) {
      cout << " " << divisors[i];
    }
    cout << endl;
  }

  return 0;
}
