#include "cmath"
#include "cstdio"
#include "iostream"
#include "sstream"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"

using namespace std;

typedef long long i64;

vector<int> primes;
const int max_prime = 1000000;
vector<vector<vector<int>>> prime_mods; // prime_mods[base][prime][power]
vector<int> max_check_self;

void init_primes() {
  primes.push_back(2);
  vector<bool> sieve(max_prime);
  for (int i = 3; i < sieve.size(); i += 2) {
    if (!sieve[i]) {
      //fprintf(stderr, "%d ", i);
      primes.push_back(i);
      int j = 3;
      while (i * j < sieve.size()) {
        sieve[i * j] = true;
        j += 2;
      }
    }
  }
  fprintf(stderr, "found %ld primes\n", primes.size());
}

void init_max_check_self() {
  max_check_self = vector<int>(9);
  for (int b = 2; b <= 10; b++) {
    int mm = 1, p = 1;
    while (mm <= max_prime) {
      mm *= b;
      p++;
    }
    max_check_self[b - 2] = p;
  }
}

void init_prime_mods(int l) {
  prime_mods = vector<vector<vector<int>>>(9, vector<vector<int>>(primes.size(), vector<int>(l)));
  for (int b = 2; b <= 10; b++) {
    for (int p = 0; p < primes.size(); p++) {
      int cur_prime = primes[p];
      int cur_mod = 1;
      for (int power = 0; power < l; power++) {
        prime_mods[b - 2][p][power] = cur_mod;
        cur_mod = (cur_mod * b) % primes[p];
      }
    }
  }
}

int first_div_self_possible(vector<bool> &v, int b) {
  int p = 0;
  while (p < primes.size()) {
    int mod = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i])
        mod += prime_mods[b - 2][p][i];
    }
    if (mod % primes[p] == 0)
      return primes[p];
    p++;
  }
  return 1;
}

int first_div(vector<bool> &v, int b) {
  int d = first_div_self_possible(v, b);
  if (d == 1 || max_check_self[b - 2] < v.size())
    return d;
  int value = 0, bb = 1;
  for (int i = 0; i < v.size(); i++) {
    if (v[i])
      value += bb;
    bb *= b;
  }
  return value == d ? 1 : d;
}

bool increment(vector<bool> &v) {
  int p = 1;
  bool done = false;
  while (!done && p < v.size()) {
    if (v[p] == 0) {
      v[p] = 1;
      done = true;
    } else {
      v[p] = 0;
      p++;
    }
  }
  return done;
}

void solve(int n, int j) {
  init_prime_mods(n);
  vector<bool> cur(n);
  cur[0] = true;
  cur[n - 1] = true;
  bool done = false;
  while (!done) {
    //for (int i = 0; i < n; i++)
    //  fprintf(stderr, cur[n - 1 -i] ? "1" : "0");
    ostringstream s;
    bool ok = true;
    for (int b = 2; b <= 10; b++) {
      //i64 to_display = 0, bb = 1;
      //for (int i = 0; i < n; i++) {
      //  if (cur[i])
      //    to_display += bb;
      //  bb *= b;
      //}
      //fprintf(stderr, " %lld ", to_display);
      int d = first_div(cur, b);
      if (d == 1) {
        ok = false;
        break;
      }
      s << " " << d;
    }
    //fprintf(stderr, " -> %s\n", s.str().c_str());
    if (ok) {
      j--;
      fprintf(stderr, "#%d : ", j);
      for (int i = 0; i < n; i++) {
        printf(cur[n - 1 -i] ? "1" : "0");
        fprintf(stderr, cur[n - 1 -i] ? "1" : "0");
      }
      printf("%s\n", s.str().c_str());
      fprintf(stderr, "%s\n", s.str().c_str());
    }
    done = j == 0 || !increment(cur);
  }
}

int main() {
  init_primes();
  init_max_check_self();
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    fprintf(stderr, "Case #%d of %d...\n", Ti, T);
    int n, j;
    scanf("%d %d", &n, &j);
    printf("Case #%d: \n", Ti);
    solve(n, j);
  }
  return 0;
}
