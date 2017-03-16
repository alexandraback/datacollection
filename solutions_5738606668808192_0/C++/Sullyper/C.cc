#include <stdio.h>

const int N = 16;
const int J = 50;

int number[N];

bool check(int prime, int base) {
  int n = 0;
  for (int i = 0; i < N; i++) n = ((n * base) + number[i]) % prime;
  return n == 0;
}

unsigned long long compute(unsigned long long base) {
  unsigned long long n = 0;
  for (int i = 0; i < N; i++) n = (n * base) + number[i];
  return n;
}

void print(int* prime) {
  for (int i = 0; i < N; i++) printf("%d", number[i]);
  for (int i = 0; i < 9; i++) printf(" %d", prime[i]);
  printf("\n");
}

void inc() {
  for (int i = 1; i + 1 < N; i++) {
    if (number[i] == 0) {
      number[i] = 1;
      return;
    } else {
      number[i] = 0;
    }
  }
  printf("We need to add more prime...\n");
}

int main() {
  printf("Case #1:\n");
  number[0] = number[N-1] = 1;
  int primes[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                    147, 31, 43, 1121, 73, 629, 10101, 513, 217, 629};
  int j = 0;
  while (j < J) {
    int M[10];
    int match = 0;
    for (int base = 2; base <= 10; base++) {
      for (int p = 0; p < 10; p++) {
        if (check(primes[p], base)) {
          M[base - 2] = primes[p];
          match++;
          break;
        }
      }
    }
    if (match == 9) {
      j++; print(M);
    }
    inc();
  }
  return 0;
}
