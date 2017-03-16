#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <inttypes.h>
#include <gmpxx.h>

#ifdef LOCAL_BUILD
#include "cout.h"
#endif

typedef mpz_class bigint;

using namespace std;

#define mp make_pair
#define ALL(a) (a).begin(), (a).end()

// Forward declarations.
void CommonInit();
void Input();
void Solve();

int main() {
  int T;
  scanf("%d", &T);

  CommonInit();

  for (int testCase = 1; testCase <= T; ++testCase) {
    printf("Case #%d: ", testCase);

    Input();
    Solve();

    printf("\n");
  }

  return 0;
}


const string Vowels = "aeiou";

const int MAX_L = 100010;

string S;
int N;

int dp[MAX_L];

void CommonInit() {
}

void Input() {
  S = "";
  N = -1;
  memset(dp, 0, sizeof(dp));

  cin >> S >> N;
}

void Solve() {
  int L = S.length();

  for (int i = 0; i < L; i++) {
    if (Vowels.find(S[i]) != string::npos) {
      dp[i] = 0;
      continue;
    }

    if (i == 0) {
      dp[i] = 1;
      continue;
    }

    dp[i] = dp[i - 1] + 1;
  }

  /*
  printf("%d\n  ", L);
  for (int i = 0; i < L; i++) printf("%d", dp[i]);
  printf("\n");
  */

  long long res = 0LL;
  for (int a = 0; a < L; a++) {
    for (int b = a; b < L; b++) {
      for (int c = a; c <= b; c++) {
        if (dp[c] >= N && (c - a + 1) >= N) {
          res++;
          break;
        }
      }
    }
  }
  
  printf("%lld", res);
}
