#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>

using namespace std;

bool isPalindrome(unsigned long long n) {
  unsigned long long temp = n, sum = 0;
  while(temp) {
    sum = 10 * sum + temp % 10;
    temp = temp / 10;
  }
  return (n == sum);
}

int main(int argc, char* argv[]) {
  FILE* f = fopen(argv[1], "r");
  int T;
  fscanf(f, "%d", &T);
  for(int t = 0; t < T; ++t) {
    unsigned long long A, B;
    fscanf(f, "%llu %llu", &A, &B);
    unsigned long long sA = sqrt(A), sB = sqrt(B);
    unsigned long long res = 0;
    for(unsigned long long i = sA; i <= sB; ++i) {
      if(i * i >= A && i * i <= B && isPalindrome(i) && isPalindrome(i * i)) {
        res++;
      }
    }
    printf("Case #%d: %llu\n", t + 1, res);
  }
}

