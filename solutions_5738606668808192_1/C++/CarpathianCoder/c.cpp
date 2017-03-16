#define MAX_PRIME 7
#define MAX_POWER 32
#define NUM_BASES 9

#include <iostream>
#include <random>
#include <set>
#include <vector>

bool not_prime[MAX_PRIME + 1];
int num_primes = 0;

int t[NUM_BASES][MAX_PRIME + 1][MAX_POWER];

void build_primes(std::vector<int>& primes)
{
  int i = 2;

  for (int j = 0; j < i; j++) {
    not_prime[j] = true;
  }

  while (i <= MAX_PRIME) {
    for (int j = 2 * i; j <= MAX_PRIME; j += i) {
      not_prime[j] = true;
    }
    for (++i; i <= MAX_PRIME && not_prime[i]; ++i);
  }

  for (int i = 0; i <= MAX_PRIME; i++) {
    if (!not_prime[i]) {
      primes.push_back(i);
      num_primes++;
    }
  }
}

void solve_case(const std::vector<int>& primes, int case_num)
{
  int n, j;
  std::vector<bool> v;

  std::cin >> n >> j;
  std::cout << "CASE #" << case_num << ":" << std::endl;

  for (int b = 0; b < NUM_BASES; b++) {
    for (int p : primes) {
      t[b][p][0] = 1;
      for (int e = 1; e < n; e++) {
        t[b][p][e] = t[b][p][e - 1] * (b + 2) % p ;
      }
    }
  }

  unsigned int mask = 1U << (n - 2);
  std::set<unsigned int> s;
  std::default_random_engine generator;
  std::uniform_int_distribution<unsigned int> distribution(0, mask - 1);

  int num_solutions = 0;
  int divs[NUM_BASES];
  int digits[MAX_POWER];

  while (num_solutions < j) {
    bool solution = true;

    unsigned int cand = distribution(generator);
    if (s.find(cand) != s.end()) {
      continue;
    } else {
      s.insert(cand);
    }
    for (int i = 0; i < n - 2; cand >>= 1, ++i) {
      digits[i] = cand & 1;
    }

    for (int b = 0; b < NUM_BASES; b++) {
      bool found = false;
      int divisor = 0;
      for (int p : primes) {
        int sum = t[b][p][0] + t[b][p][n - 1];
        int i = 1;
        for (int i = 0; i < n - 2; i++) {
          if (digits[i]) {
            sum += t[b][p][i + 1];
          }
        }
        if (sum % p == 0) {
          found = true;
          divisor = p;
          break;
        }
      }
      if (found) {
        divs[b] = divisor;
      } else {
        solution = false;
        break;
      }
    }
    if (solution) {
      std::cout << "1";
      for (int i = n - 3; i >= 0; i--) {
        std::cout << digits[i];
      }
      std::cout << "1";
      for (int b = 0; b < NUM_BASES; b++) {
        std::cout << " " << divs[b];
      }
      std::cout << std::endl;
      ++num_solutions;
    }
  }
}

int main()
{
  std::vector<int> primes;
  int num_cases;

  build_primes(primes);

  std::cin >> num_cases;
  for (int i = 1; i <= num_cases; i++) {
    solve_case(primes, i);
  }
  
  return 0;
}
