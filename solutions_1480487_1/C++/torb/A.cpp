#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

int main() {
  int TC; cin >> TC;
  for (int t = 1; t <= TC; t++) {
    int N; cin >> N;
    vector<double> scores(N);
    double X = 0;
    for(int i = 0; i < N; ++i) {
      cin >> scores[i];
      X += scores[i];
    }
    vector<double> votes;

    for(int i = 0; i < N; ++i) {
      double l = 0, r = 1, m;
      while(r-l > 1e-10) {
        m = (l+r)/2;
        double score = scores[i] + X*m;
        double used = m;
        for(int j = 0; j < N; ++j) {
          if(i == j) continue;
          if(scores[j] > score) continue;
          used += (score - scores[j]) / X;
        }
        if(used < 1) l = m;
        else r = m; 
      }
      votes.push_back(100 * l);
    }
    printf("Case #%d:", t);
    for(int i = 0; i < N; ++i) {
      printf(" %.6f", votes[i]);
    }
    printf("\n");
  }


  return 0;
}
