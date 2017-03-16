// Code Jam 2015 Round 1C
// Problem B
// Author: Max Pflueger

#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int countTarget(string target, string S) {
  int pos = S.length() - target.length() + 1;
  int ct = 0;
  for (int i=0; i < pos; i++) {
    if (target == S.substr(i, target.length())) {
      ct++;
    }
  }
  return ct;
}

double solveCase(int K, int L, int S, string keyboard, string target) {
  double leftover = 1.0;

  map<char, int> alph;
  for (auto c : keyboard) {
    if (alph.find(c) != alph.end()) {
      alph[c] = alph[c] + 1;
    }
    else {
      alph[c] = 1;
    }
  }

  // check for targert in alphabet
  for (auto c : target) {
    if (alph.find(c) == alph.end()) {
      return 0.0;
    }
  }

  // check target overlap
  int slide = L;
  assert(L == target.length());
  for (int i=1; i < L; i++) {
    if (target.substr(0, L-i) == target.substr(i, L-i)) {
      slide = i;
      break;
    }
  }

  // find max strings, bananas
  int max_b = ((S-L) / slide) + 1;
  leftover = (double) max_b;

  // find expected success
  //check all strings
  long long bananas = 0;
  vector<int> keys;
  keys.resize(S+1, 0);
  while (keys[S] == 0) {
    string s;
    for (int i=0; i<S; i++) {
      s = s + keyboard[keys[i]];
    }
    bananas += max_b - countTarget(target, s);

    // increment string
    keys[0] += 1;
    for (int i=0; i < S; i++) {
      if (keys[i] == K) {
        keys[i] = 0;
        keys[i+1] += 1;
      } else {
        break;
      }
    }
  }

  leftover = bananas / pow(K, S);

  return leftover;
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
  int K, L, S;
  *fs >> K;
  *fs >> L;
  *fs >> S;

  string keyboard;
  *fs >> keyboard;

  string target;
  *fs >> target;

  //cerr << "kb: " << keyboard << endl;
  //cerr << "target: " << target << endl;

  double x = solveCase(K, L, S, keyboard, target);

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
