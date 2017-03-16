#include <iostream>
#include <fstream>

#include <unordered_set>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int find(size_t p, size_t q) {
  size_t left = 0, right = q;

  int min_g = 1000;
  int g = 1;
  while (true) {
    size_t middle = left + right;
    if (middle & 1) return -1;

    middle >>= 1;

    if (p == middle)
      break;

    if (p > middle) {
      left = middle;
      if (min_g == 1000)
	min_g = g;
    }
    else {
      ++g;
      right = middle;
    }
  }

  if (min_g == 1000)
    min_g = g;

  return min_g;
}

int main(int argc, char* argv[]) {

  if (argc < 3)
    return -1;

  ifstream fin(argv[1]);
  ofstream fout(argv[2]);

  int N;
  fin >> N;

  string token;
  int i=0;
  while (fin >> token) {
    ++i;
    size_t pos = token.find('/');

    size_t p = stol(token.substr(0, pos));
    size_t q = stol(token.substr(pos+1));

    int g = find(p, q);

    fout << "Case #" << i << ": ";

    if (g == -1)
      fout << "impossible" << endl;
    else
      fout << g << endl;
  }

  fin.close();
  fout.close();

  return 0;
}

