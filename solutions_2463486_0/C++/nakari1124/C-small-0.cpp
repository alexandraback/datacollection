#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <cmath>
#include <set>

using namespace std;

typedef long long i64;
typedef int int_t;
typedef vector<int_t> vi;
typedef vector<vi> vvi;

typedef pair<int_t, int_t> pi;

#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i < (c).end(); i++)
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define REP(s, e, i) for(i=(s); i < (e); ++i)

bool is_palindrome(i64 n) {
  vi digits;
  while(n != 0) {
    i64 d = n % 10;
    digits.pb(d);
    n -= d;
    n /= 10;
  }
  i64 i;
  REP(0, sz(digits), i) {
    if(digits[i] != digits[sz(digits)-1-i])
      return false;
  }
}

i64 count(i64 A) {
  if(A == 0)
    return 0;

  i64 ct = 0;
  i64 n = 1;
  i64 n2 = 1;
  while(n2 <= A) {
    if(is_palindrome(n) && is_palindrome(n2)) {
      ct++;
    }

    ++n;
    n2 = n * n;
  }

  return ct;
}

int main(int argc, char *argv[]) {

  i64 C;
  cin >> C;
  i64 n;
  i64 i, j;
  getchar();

  REP(0, C, n) {
    cout << "Case #" << n + 1 << ": ";

    i64 A, B;
    cin >> A >> B;
    cout << count(B) - count(A - 1);
    cout << endl;
  }

  return 0;
}
