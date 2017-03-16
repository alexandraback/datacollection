#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {

  long long ncases;
  cin >> ncases;

  for (long long i = 0; i < ncases; i++) {
    long long ndiners, n;
    cin >> ndiners;
    vector<long long> pancakes;
    
    long long max = 0;
    for (long long j = 0; j < ndiners; j++) {
      cin >> n; 
      if (n > max) {
        max = n;
      }
      pancakes.push_back(n);
    }
    
    long long min_mins = max;
    for (long long p = 1; p <= max; p++) {
      long long count = p;
      for (long long q = 0; q < ndiners; q++) {
        long long nmins = (pancakes[q]+p-1)/p - 1;
        if (nmins > 0) 
          count += nmins;
      }
      if (count < min_mins) {
        min_mins = count;
      }
    }
    cout << "Case #" << i+1 << ": " << min_mins << endl;
  }

  return 0;
}
