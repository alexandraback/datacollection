#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int T;
  cin >> T;

  for(int tt = 1; tt <= T; tt++) {
    int R,C,W;
    cin >> R >> C >> W;

    int i = 0;
    int guesses = 0;
    while (i < C) {
      guesses += 1;
      i += W;
     }
    guesses *= R;
    guesses += W-1;
    
    cout << "Case #" << tt << ": " << guesses << endl;

  }

  return 0;
}
