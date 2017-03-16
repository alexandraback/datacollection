#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define echo(x) cerr << #x << ": " << x << endl;

int main(int ac, char** av) {
  int num_cases;
  cin >> num_cases;
  for (int i = 0; i < num_cases; ++i) {
    int R,C,W;
    cin >> R >> C >> W;
    int cost = (C / W) * R + W - 1 + 1; // add W-1 for killing the rest + 1 miss to find direction
    if (C%W == 0) {
      cost--; // no need to find direction -> game over
    }
    cout << "Case #" << i+1 << ": " << cost << endl;
  } 
}
