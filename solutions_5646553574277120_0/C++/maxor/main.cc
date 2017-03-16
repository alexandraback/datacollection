// Code Jam 2015 
// Problem C
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

bool gt(int a, int b) { return a > b;}

bool change(int val, int C, const vector<int>& denoms) {
  // Assume cange can be make for val-1 ?
  vector<int> D = denoms;
  sort(D.begin(), D.end(), gt);

  int di = 0;
  while (di < D.size()) {
    if (val >= D[di]) {
      int coins = min(val / D[di], C);
      val = val - (D[di] * coins);
    }
    di++;
  }

  return val == 0;
}

int solveCase(int C, int D, int V, vector<int>& denoms) {
  int new_d = 0;

  for (int i=1; i<=V; i++) {
    if (!change(i, C, denoms)) {
      denoms.push_back(i);
      new_d++;
      i = (C*i) + (i-1);
    }
  }

  return new_d;
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
  int C, D, V;
  *fs >> C;
  *fs >> D;
  *fs >> V;

  vector<int> denoms = readVals(fs, D);
  if (denoms.size() != D) {
    cerr << "Error\n";
    return;
  }

  int x = solveCase(C, D, V, denoms);

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
