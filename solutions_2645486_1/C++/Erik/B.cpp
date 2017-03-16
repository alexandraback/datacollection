#include <cstdio>
#include <cmath>
#include <iostream>
#include <inttypes.h>
#include <algorithm>

using namespace std;

int64_t E,N;
int64_t v[10000];
int64_t maxi[10000][10001];

int64_t maxE, R;

int64_t gain(int64_t E, int64_t needE, int64_t a, int64_t b) {
  int64_t ret = 0;

  // cout << a << " " << b << endl;
  if (a >= b)
    return 0;

  int64_t m = maxi[a][b];
  // cout << "max " << m << endl;
  int64_t E_at_m = min(E + (m-a)*R, maxE);
  int64_t min_E_at_m = max(needE-(b-m)*R, (int64_t)0);
  int64_t spend_at_m = E_at_m - min_E_at_m;
  if (spend_at_m < 0)
    cerr << "spend at m < 0" << endl;

  // cout << "spend at m " << spend_at_m << endl;
  // printf("::%d %d\n", E_at_m, min_E_at_m);
  ret += v[m]*spend_at_m;

  ret += gain(E, E_at_m, a, m);
  if (min_E_at_m == 0) {
    ret += gain(R, needE, m+1, b);
  }

  return ret;
}

int main() {
  int T;
  cin >> T;

  for (int t_ = 0; t_ < T; t_++) {
    cin >> E >> R >> N;
    maxE = E;
    for (int i = 0; i < N; i++) {
      cin >> v[i];
    }

    for (int i = 0; i < N; i++) {
      maxi[i][i+1] = i;
      for (int j = i+2; j <= N; j++) {
        if (v[j-1] > v[maxi[i][j-1]])
          maxi[i][j] = j-1;
        else
          maxi[i][j] = maxi[i][j-1];

      }
    }
    //    return 0;

    cout << "Case #" << t_+1 << ": " << gain(E, 0, 0, N);
    cout << endl;
  }


  return 0;
}
