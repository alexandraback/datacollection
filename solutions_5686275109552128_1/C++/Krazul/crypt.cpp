#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    int best = 2000;
    int d; cin >> d;
    vector<int> plates(d);
    for (int i = 0; i < d; ++ i) {
      cin >> plates[i];
    }
    for (int guess = 1; guess <= 1000; ++guess) {
      int cost = guess;
      for (int i = 0; i < plates.size(); ++i) {
        cost += (plates[i] - 1) / guess;
      }
      best = min(best, cost);
    }

    cout << "Case #" << test << ": " << best << endl;
  }
  return 0;
}