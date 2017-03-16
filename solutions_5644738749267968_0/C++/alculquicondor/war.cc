#include <iostream>
#include <algorithm>
#include <set>
#define MAXN 1001

using namespace std;

int A[MAXN], B[MAXN], n;

int play1() {
  int ini = 0, fin = n - 1, f;
  for (int i = n - 1; i >= 0; --i) {
    if (A[fin] > B[i]) {
      ++f;
      --fin;
    } else {
      ++ini;
    }
  }
  return f;
}

int play2() {
  int f = 0, j = 0;
  set<int> S;
  for (int i = 0; i < n; ++i)
    S.insert(B[i]);
  set<int>::iterator it;
  for (int i = 0; i < n; ++i) {
    it = S.upper_bound(A[i]);
    if (it == S.end())
      ++f;
    else
      S.erase(it);
  }
  return f;
}

int main() {
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  for (int caso = 1; caso <= tc; ++caso) {
    cin >> n;
    double x;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      A[i] = x * 100000;
    }
    for (int i = 0; i < n; ++i) {
      cin >> x;
      B[i] = x * 100000;
    }
    sort(B, B+n);
    sort(A, A+n);
    cout << "Case #" << caso << ": ";
    cout << play1() << " " << play2() << endl;
  }
}
