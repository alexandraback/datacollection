// #include <assert.h>

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
//#include <unordered_map>
#include <vector>

using namespace std;

#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FOR_(i, n) for (int i = n - 1; i >= 0; --i)


int main () {
  ifstream in_("A-small-attempt0.in");
  ofstream out_("out");
  int T;
  in_ >> T;
  for (int count = 1; count <= T; ++count) {
    int c = 0;
    // Input
    int A, N;
    in_ >> A >> N;
    vector<int> mots;
    for (int i = 0; i < N; ++i) {
      int temp;
      in_ >> temp;
      mots.push_back(temp);
    }

    // compute answer
    sort(mots.begin(), mots.end());
    if (A == 1)
      c = mots.size();
    else {

      vector<int> toAdd;
      for (int i = 0; i < N; ++i) {
        int m = 0;
        while (A <= mots[i]) {
          A = 2*A- 1;
          ++m;
        }
        A += mots[i];
        toAdd.push_back(m);
      }

      // find n operations
      N--;
      c = 0;
      for (int i = N; i >= 0; --i) {
        if (toAdd[i] < N - i + 1) {
          c += toAdd[i];
        }
        else {
          c += (N - i + 1);
          N = i - 1;
        }
      }
    }

    // output
    stringstream ss;
    ss << count;
    stringstream p;
    p << c;
    string s1("Case #");
    string s2;
    ss >> s2;
    string s3(": ");
    string s4;
    p >> s4;

    string sss = s1 + s2 + s3 + s4;
    out_ << sss << endl;
  }

  in_.close();
  out_.close();

  return 0;
}
