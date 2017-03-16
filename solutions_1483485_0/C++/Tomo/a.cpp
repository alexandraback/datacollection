#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
using namespace std;

#define REP(i, n)      for (int (i) = 0, __n = (int)(n); (i) < __n; ++(i))
#define REPS(i, s, n)  for (int (i) = (s), __n = (int)(n); (i) < __n; ++(i))
#define REPD(i, n)     for (int (i) = (n); (i) >= 0; --(i))
#define FOREACH(i, x)  for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define SIZE(x)        (int)((x).size())

const int A[] = { 24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 
                  19, 13, 22, 9, 15, 5, 12, 0, 16 };

struct translator : unary_function<char, char> {
  char operator()(char const& b) const {
    if (!isalpha(b)) return b;
    else             return A[b - 'a'] + 'a';
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  string S;
  int    T; 

  cin >> T; getline(cin, S);
  REP(tc, T) {
    getline(cin, S);
    transform(S.begin(), S.end(), S.begin(), translator());
    cout << "Case #" << tc+1 << ": " << S << "\n";
  }

  return EXIT_SUCCESS;
}
