// g++ -Wall hoge.cpp -lgmpxx -lgmp
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

#include <gmpxx.h>

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

void solve();
int main() {
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

bool ispalin(mpz_class v) {
  string s = v.get_str();
  string rev = s;
  reverse(rev.begin(), rev.end());
  return s == rev;
}

mpz_class A, B;
void solve() {
  mpz_class ans = 0;
  {
    cin >> A >> B;
    // if (A <= 1 && 1 <= B) { ans++; }
    // if (A <= 4 && 4 <= B) { ans++; }
    // if (A <= 9 && 9 <= B) { ans++; }
    // if (B <= 9) { goto end; }
    // A = max(A, mpz_class("10"));
    // B = max(B, mpz_class("10"));

    // for (mpz_class i = sqrt(A) - 2; i <= sqrt(B) + 2; i++) {
    //   if (i <= 0) { continue; }
    //   if (!ispalin(i)) { continue; }
    //   mpz_class v = i * i;
    //   if (v < A || B < v) { continue; }
    //   if (!ispalin(v)) { continue; }
    //   cout << i << " " << v << endl;
    //   ans++;
    // }
    for (mpz_class i = sqrt(A) - 2; i <= sqrt(B) + 2; i++) {
      if (i <= 0) { continue; }
      if (!ispalin(i)) { continue; }
      mpz_class v = i * i;
      if (v < A || B < v) { continue; }
      if (!ispalin(v)) { continue; }
      //cout << i << " " << v << endl;
      ans++;
    }
  }
//end:
  cout << ans << endl;
}
