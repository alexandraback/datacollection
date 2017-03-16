#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <bitset>
#include <functional>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

bool cant_be_eliminated(int ind, vector<double> scores, double bonus) {
  int N = scores.size();
  double aim = scores[ind] + bonus;
  if (aim > 2.0 / N) {
    return true;
  }
  // see if everybody else can get more than aim
  double bonus_sum = bonus;
  for (int i = 0; i < N; ++i) {
    if (scores[i] < aim && i != ind) {
      bonus_sum += aim - scores[i];
    }
  }
  return (bonus_sum > 1.000000001);
}

void solve(int ind) {
    int N;
    cin >> N;
    vector<double> scores(N);
    double sum = 0;
    for (int i = 0; i < N; ++i) {
      cin >> scores[i];
      sum += scores[i];
    }
    for (int i = 0; i < N; ++i) {
      scores[i] /= sum;
    }
    //output
    cout << "Case #" << ind << ":";
    for (int i = 0; i < N; ++i) {
      // find for i
      if (cant_be_eliminated(i, scores, 0)) {
        cout << " 0";
        continue;
      } 
      double low = 0, high = 1, med;
      for (int it = 0; it < 30; ++it) {
        med = (low + high) / 2;
        if (cant_be_eliminated(i, scores, med)) {
          high = med;
        } else {
          low = med;
        }
      }
      cout << " " << setprecision(12) << med * 100;
    }
    cout << endl;
}

int main() {
    int i, T;
    cin >> T;
    string st;
    getline(cin, st);
    for (i=1; i<=T; i++) {
        solve(i);
    }
}
