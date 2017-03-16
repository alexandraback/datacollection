//#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream cin("B-large.in");
ofstream cout("B-large.out");

int main() {
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
      string s;
      cin >> s;
      int truns = 0;
      if (s[s.size()-1] == '-') truns++;
      for (int i=0; i<s.size()-1; i++) {
        if (s[i] != s[i+1]) truns++;
      }
      cout << "Case #" << t+1 << ": " << truns << endl;
    }
return 0;
}
