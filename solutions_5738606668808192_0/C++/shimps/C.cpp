#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "gmp.h"

#include <string>
#include <set>

using namespace std;

char chosen_str[64];
bool do_case_prob(int num_bits) {
  for(int i=0;i<num_bits;i++) {
    if (i == 0 || i == num_bits-1) {
      chosen_str[i] = '1';
    } else {
      chosen_str[i] = '0' + (rand()%2);
    }
  }
  chosen_str[num_bits] = 0;
  bool can_choose = true;
  for(int base = 2; base <= 10 && can_choose; base++) {
    mpz_t nu;
    mpz_init(nu);
    mpz_set_str(nu, chosen_str, base);
    if (mpz_probab_prime_p(nu, 25)) can_choose = false;
  }
  return can_choose;
}

int fac[16];
bool build_factors() {
  for(int base=2;base<=10;base++) {
    mpz_t nu;
    mpz_init(nu);
    mpz_set_str(nu, chosen_str, base);
    bool did_find = false;
    for(int i=2;i<=100;i++) {
      mpz_t nnu;
      mpz_init(nnu);
      mpz_set_ui(nnu, i);
      if (mpz_cmp(nu, nnu) == 0) break;
      if (mpz_divisible_ui_p(nu, i)) {
        fac[base] = i;
        did_find = true;
        break;
      }
    }
    if (!did_find) return false;
  }
  return true;
}

void do_case (int num_bits, int num_results) {
  set<string> R;
  while(num_results) {
    if (do_case_prob(num_bits)) {
      if (build_factors()) {
        string r(chosen_str);
        if (R.find(r) == R.end()) {
          R.insert(r);
          cout << r;
          for(int i=2;i<=10;i++) cout << " " << fac[i];
          cout << endl;
          --num_results;
        }
      }
    }
  }
}

int main() {
  srand(time(NULL));
  int cn;
  cin >> cn;
  for(int i=1;i<=cn;i++) {
    int b, j;
    cin >> b >> j;
    cout << "Case #" << i << ":" << endl;
    do_case(b,j);
  }
}
