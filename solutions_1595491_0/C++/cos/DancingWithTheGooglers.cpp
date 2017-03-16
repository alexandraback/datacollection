#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

struct Score {
  int sum;
  int score[3];
  int suprise;
  Score() {;}
  Score(int sum, int s1, int s2, int s3, int suprise)
    : sum(sum), suprise(suprise) {
      score[0] = s1;
      score[1] = s2;
      score[2] = s3;
    }
};

vector<Score> scores[40];

void solve();
int main() {
  FOREQ(k, 0, 10) {
    FOREQ(j, 0, k) {
      FOREQ(i, 0, j) {
        if (k - i > 2) { continue; }
        int sum = i + j + k;
        scores[sum].push_back(Score(sum, i, j, k, k - i == 2));
      }
    }
  }
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    //puts("");
    solve();
  }
}

int n, s, p;
int seq[110];
int memo[110][110];
int calc(int depth, int rest) {
  if (rest < 0) { return -1000; }
  if (depth == n) { return 0; }
  int ret = 0;
  if (memo[depth][rest] != -1) { return memo[depth][rest]; }
  FORIT(it, scores[seq[depth]]) {
    int nret = it->score[2] >= p;
    nret += calc(depth + 1, rest - it->suprise);
    ret = max(ret, nret);
  }
  return memo[depth][rest] = ret;
}

void solve() {
  MEMSET(memo, -1);
  scanf("%d %d %d", &n, &s, &p);
  REP(i, n) {
    scanf("%d", &seq[i]);
  }
  printf("%d\n", calc(0, s));
}
