// Code Jam 2015
// Problem
// Author: Max Pflueger

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


int solveCase(int R, int C, int W) {
  int moves = 0;

  // moves to eliminate row
  int row_e = C/W;
  moves = row_e * R;
  if (C % W) {
    moves += 1;
  }

  // finish the ship
  moves += W-1;

  return moves;
}

// Read n int values out of the file
vector<int> readVals(fstream* fs, int n) {
  vector<int> vals;
  int x;

  vals.resize(n);
  for (int i=0; i < n; i++) {
    *fs >> x;
    vals[i] = x;
  }
  return vals;
}

void readCase(fstream* fs, int case_num) {
  int R, C, W;
  *fs >> R;
  *fs >> C;
  *fs >> W;

  int x = solveCase(R, C, W);

  cout << "Case #" << case_num << ": " << x << endl;
}

int main(int argc, char** argv) {
  // Check number of args
  if (argc < 2) {
    cerr << "Please supply an input file.\n";
    return -1;
  }

  // Open the input file (read only)
  fstream fs;
  fs.open(argv[1], fstream::in);

  int cases;
  fs >> cases;
  for (int i=0; i<cases; i++) {
    readCase(&fs, i+1);
  }
}
