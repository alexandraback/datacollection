#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <iterator>
#include <queue>
#include <cassert>

using namespace std;

#define MAXSIZE 10000

int E, R, N, v[MAXSIZE];

int spend(int current_energy, int n) {
  int best_gain = 0, gain = 0;
  
  if (n >= N) return 0;
  for (int i = 0; i <= current_energy; ++i) {
    gain = v[n] * i + spend(min(current_energy - i + R, E), n+1);
    if (gain > best_gain) best_gain = gain;
  }
  return best_gain;
}

int main() {
  int T;
  
  cin >> T;
  for (int trial = 1; trial <= T; ++trial) {
    cin >> E >> R >> N;
    for (int i = 0; i < N; ++i) {
      cin >> v[i];
    }
    
    cout << "Case #" << trial << ": " << spend(E, 0) << endl;
  }
  
  return 0;
}
