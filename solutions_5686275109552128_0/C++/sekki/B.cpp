#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {

  int ncases;
  cin >> ncases;

  for (int i = 0; i < ncases; i++) {
    int ndiners, n;
    cin >> ndiners;
    vector<int> pancakes;
    
    int max = 0;
    for (int j = 0; j < ndiners; j++) {
      cin >> n; 
      if (n > max) {
        max = n;
      }
      pancakes.push_back(n);
    }
    
    int min_mins = max;
    for (int p = 1; p <= max; p++) {
      int count = p;
      for (int q = 0; q < ndiners; q++) {
        int nmins = (pancakes[q]+p-1)/p - 1;
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
