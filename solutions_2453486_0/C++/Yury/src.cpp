#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;


void scan(char c1, char c2, char c3, char c4, bool flags[3]){
  char cs[4] = {c1, c2, c3, c4};

  int t = 0;
  int x = 0;
  int o = 0;
  for(int i = 0; i < 4; i++) {
    switch(cs[i]) {
      case 'T': t++; break;
      case 'X': x++; break;
      case 'O': o++; break;
      case '.': flags[0] = true;
    }
  }
  if(x == 4 || (x == 3 && t == 1)) flags[1] = true;
  if(o == 4 || (o == 3 && t == 1)) flags[2] = true;
}

int main(int argc, char* argv[]) {
  fstream     f(argv[1]);

  int T;
  f >> T;

  for(int t = 1; t <= T; t++) {
    char    map[4][4];

    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        f >> map[i][j];
      }
    }

    ////

    /*
    for(auto& line : map) {
      for(auto c : line) {
        cerr << c;
      }
      cerr << endl;
    }
    */

    //int count = calc(d);

    cout << "Case #" << t << ": ";

    bool  flags[3] = {false, false, false};

    for(int i = 0; i < 4; i++) {
      scan(
        map[i][0],
        map[i][1],
        map[i][2],
        map[i][3],
        flags);
    }

    for(int i = 0; i < 4; i++) {
      scan(
        map[0][i],
        map[1][i],
        map[2][i],
        map[3][i],
        flags);
    }

    scan(
      map[0][0],
      map[1][1],
      map[2][2],
      map[3][3],
      flags);

    scan(
      map[0][3],
      map[1][2],
      map[2][1],
      map[3][0],
      flags);

    if(flags[1]) {
      cout << "X won\n";
    }else if(flags[2]) {
      cout << "O won\n";
    }else if(flags[0]) {
      cout << "Game has not completed\n";
    }else{
      cout << "Draw\n";
    }
  }
}

