#include <cstdio>
#include <string>
using namespace std;

#define INFINITY 1000000000000000ll

long long reverse(long long x) {
  string s = to_string(x);
  long long rev_x = 0;
  long long pow_10 = 1;
  for (int i = 0; i < s.size(); i++) {
    rev_x += (s[i]-'0') * pow_10;
    pow_10 *= 10;
  }
  return rev_x;
}

long long try_single_reverse(long long start, long long goal, long long bound) {
  long long best_answer = goal - start;
  for (long long i = 0; i <= bound; i++) {
    long long cur_number = reverse(start + i);
    if (cur_number <= goal) {
      long long cur_answer = i + 1 + (goal - cur_number);
      if (cur_answer < best_answer) best_answer = cur_answer;
    }
  }
  return best_answer;
}

long long int_pow(long long a, long long b) {
  if (b == 0) return 1;
  return a * int_pow(a, b-1);
}

long long numToDigit(long long n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 9;
  } else {
    long long p1 = (n-1) / 2;
    long long p2 = n - 1 - p1;
    return int_pow(10, p1) + int_pow(10, p2) - 1;
  }
}

long long numDigits(long long x) {
  long long count = 0;
  while (x > 0) {
    count++;
    x /= 10;
  }
  return count;
}

long long firstDigit(long long x) {
  while (x >= 10) {
    x /= 10;
  }
  return x;
}

long long solve(long long x) {
  long long numd = numDigits(x);
  long long moves = 1;
  for (int i = 2; i <= numd; i++) {
    moves += numToDigit(i);
  }
  long long f = firstDigit(x);
  long long cur_number = int_pow(10, numd-1);
  long long bound = int_pow(10, numd / 2 + 1);
  // printf("%lld\n", moves);
  return moves + try_single_reverse(cur_number, x, bound);
  // if (f == 1) {
  //   long long cur_number = int_pow(10, numd-1);
  //   return moves + x - cur_number;
  // }
  // moves += f + 1;
  // long long cur_number = f * int_pow(10, numd-1) + 1;
  // return moves + x - cur_number;
}

int main ()
{
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    long long x;
    scanf("%lld", &x);
    printf("Case #%d: %lld\n", i, solve(x));
  }
}