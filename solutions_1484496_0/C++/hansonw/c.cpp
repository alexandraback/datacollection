#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int ti = 1; ti <= T; ti++) {
    int N; cin >> N;
    int A[21];
    map<int, int> x;
    int a = -1, b;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < (1<<N); i++) {
      int s = 0;
      for (int j = 0; j < N; j++) if (i&(1<<j)) s += A[j];
      if (x.count(s)) {
        a = x[s];
        b = i;
      }
      x[s] = i;
    }

    printf("Case #%d:\n", ti);
    if (a == -1) puts("Impossible");
    else {
      bool f = true;
      for (int i = 0; i < N; i++) {
        if (a & (1<<i)) {
          if (!f) cout << " "; f = false;
          cout << A[i];
        }
      }
      cout << endl;
      f = true;
      for (int i = 0; i < N; i++) {
        if (b & (1<<i)) {
          if (!f) cout << " "; f = false;
          cout << A[i];
        }
      }
      cout << endl;
    }
  }
}
