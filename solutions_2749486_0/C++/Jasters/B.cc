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

#define MAXSIZE 100000

int main() {
  int T, X, Y;
  string moves;
  string addx, addy;
  
  cin >> T;
  for (int trial = 1; trial <= T; ++trial) {
    cin >> X >> Y;
    
    if (X < 0) addx = "EW";
    else addx = "WE";
    
    if (Y < 0) addy = "NS";
    else addy = "SN";
    
    moves = "";
    for (int i = 0; i < abs(X); ++i) {
      moves += addx;
    }
    
    for (int i = 0; i < abs(Y); ++i) {
      moves += addy;
    }
    
    cout << "Case #" << trial << ": " << moves << endl;
  }
  
  return 0;
}
