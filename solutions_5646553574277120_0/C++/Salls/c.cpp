#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;

  for(int tt = 1; tt <= T; tt++) {
    int C, D, V;
    cin >> C >> D >> V;
    vector<int> v(D);
    for(int i = 0; i < D; i++) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());

    // find the smallest amount we can't pay, add it as a coin, repeat
    int curr_total = 0;
    int num_added = 0;
    for (int i = 0; i < D; i++) {
      if(curr_total >= V)
        break;
    
      if(v[i] - curr_total > 1) {
        curr_total += C*(curr_total+1);
        num_added++;
        i--;
      } else {
        curr_total += C*(v[i]);
      }
    }
    while(curr_total < V) {
      curr_total += C*(curr_total+1);
      num_added++;
    }

    cout << "Case #" << tt << ": " << num_added << endl;

  }

  return 0;
}
