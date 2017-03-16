#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

fstream in, out;

int T;
int D;
vector<int> diners;

int diner;

bool comp(int i, int j) { return (i > j);}

int main() {
  in.open("B-large.in", fstream::in);
  out.open("probb-large.out", fstream::out);

  int sum;
  in >> T;
  for (int i = 0; i < T; i++) {
    in >> D;
    diners.clear();
    sum = 0;
    for (int j = 0; j < D; ++j) {
      in >> diner;
      diners.push_back(diner);
      sum += diner;
    }
    std::sort(diners.begin(), diners.end(), comp);

    int count = 0;
    int size = diners.size();
    int max = diners[0];
    int best = max;

    for (int k = 1; k < max; ++k) {
      int ans = k;
      for (int l = 0; l < size; ++l) {
	if (diners[l] > k) {
	  ans += (diners[l] - 1) / k;
	}
      }
      if (ans < best) {
	best = ans;
      }
    }
    out << "Case #" << i + 1 << ": " << best << endl;
  }
    
  in.close();
  out.close();
  return 0;
}
