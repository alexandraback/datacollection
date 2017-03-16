#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

#define MEMO_SIZE 10000000
#define INFINITY 10000000
int solution[MEMO_SIZE];

long long reverse(long long x) {
  string s = to_string(x);
  string rev_s;
  for (int i = s.size() - 1; i >= 0; i--) {
    rev_s.push_back(s[i]);
  }
  string::size_type sz;
  long long answer = stoi(rev_s, &sz);
  return answer;
}

void precompute() {
  for (int i = 0; i < MEMO_SIZE; i++) {
    solution[i] = INFINITY;
  }
  solution [1] = 1;
  for (int i = 0; i < MEMO_SIZE; i++) {
    if (i + 1 < MEMO_SIZE) {
      solution[i+1] = min(solution[i+1], solution[i] + 1);
    }
    long long rev_i = reverse(i);
    if (0 < rev_i && rev_i < MEMO_SIZE) {
      solution[rev_i] = min(solution[rev_i], solution[i] + 1);
    }
  }
}

long long solve(long long x) {
  return solution[x];
}

int main ()
{
  int N;
  scanf("%d", &N);
  precompute();
  for (int i = 1; i <= N; i++) {
    long long x;
    scanf("%lld", &x);
    printf("Case #%d: %lld\n", i, solve(x));
    fflush(stdout);
  }
}