//#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
using namespace std;

ifstream cin("D-large.in");
ofstream cout("D-large.out");

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
    cout << "CASE #"<<t<<": ";
    int K,C,S;
    cin >> K >> C >> S;
      if (C>=K) C=K;
      vector<long long> ret;
      vector<vector<long long> > base;
      for (int i=0; i<K;) { vector<long long> out;
        for (int j=0; j<C; j++) {
          out.push_back(i); i++;
          if (i>=K) break;
        }
        base.push_back(out);
      }
      if (S<base.size()) cout << "IMPOSSIBLE" << endl;
      else {
        for (int i=0; i<base.size(); i++) {
          long long z=1,zv=0;
          for (int j=base[i].size()-1; j>=0; j--) {
            zv += base[i][j]*z; z*=K;
          }
          ret.push_back(zv);
        }
      for (int i=0; i<ret.size(); i++) cout << ret[i]+1 << " "; cout << endl;
      }
    }
return 0;
}
