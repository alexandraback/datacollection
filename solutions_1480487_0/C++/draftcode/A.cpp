#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(void) {
  int T;
  cin >> T;
  for (int ncase = 1; ncase <= T; ncase++) {
    cout << "Case #" << ncase << ": ";

    int N; cin >> N;
    int sum = 0;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
      cin >> v[i];
      sum += v[i];
    }

    int total = sum * 2;
    double avg = double(total) / N;

    int sum2 = 0;
    int N2 = 0;
    for (int i = 0; i < N; i++) {
      if (avg > v[i]) {
        sum2 += v[i];
        N2++;
      }
    }

    if (sum2 == 0) {
      for (int i = 0; i < N; i++) {
        if (avg <= v[i]) {
          printf("0.0 ");
        } else {
          printf("%.8f ", double(100)/N2);
        }
      }
    } else {
      double avg2 = double(sum2 + sum) / N;
      for (int i = 0; i < N; i++) {
        if (avg <= v[i]) {
          printf("0.0 ");
        } else {
          double pct = double(avg2 - v[i]) / sum;
          printf("%.8f ", pct * 100);
        }
      }
    }

    cout << endl;
  }
  return 0;
}
