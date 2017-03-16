#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>

#define ALL(v) v.begin(), v.end()

using namespace std;

template< typename T > T next() {  T tmp; cin >> tmp; return tmp; }

void solve() {
  double C = next< double >();
  double F = next< double >();
  double X = next< double >();

  double rate = 2.0;
  double min_t = X / rate;
  double shift = 0;
  
  while (shift < min_t) {
    shift += C / rate;
    rate += F;
    min_t = min(min_t, shift + X / rate);
  }
  printf("%.7lf\n", min_t);  
}

int main() {

//  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);

  int test = next< int >();
  for (int i = 1; i <= test; ++i) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}

