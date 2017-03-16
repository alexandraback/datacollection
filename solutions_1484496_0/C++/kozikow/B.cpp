#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <map>
#define EPS 1e-9
using namespace std;


void wypisz(int x, int y, const vector<int>& pun) {
  for(int i=0; i<pun.size(); i++) {
    if((x&(1<<i)))
      cout << pun[i] << ' ';
  }
  cout << '\n';
  for(int i=0; i<pun.size(); i++) {
    if((y&(1<<i)))
      cout << pun[i] << ' ';
  }
  cout << '\n';
}


bool find_answer(const vector<int>& zbi, const vector<int>& pun) {
  for(int i=0; i<zbi.size(); i++) {
    for(int j=i+1; j<zbi.size(); j++)
      if((zbi[i] & zbi[j]) == 0) {
        //cerr << i << ' ' << j << endl;
        wypisz(zbi[i], zbi[j], pun);
        return true;
      }
  }
  return false;
}

bool random_answer(const vector<int>& zbi, const vector<int>& pun) {
  while(true) {
    int i = rand() % zbi.size();
    int j = rand() % zbi.size();
    if( (zbi[i] & zbi[j]) == 0) {
//       //cerr << i << ' ' << j << endl;
      wypisz(zbi[i], zbi[j], pun);
      return true;
    }
  }
  return false;
}

void solve() {
  int n;
    cin >> n;
    int maxi = (1<<n);
    vector<int> points;
    while(n--) {
      int x;
      cin >> x;
      points.push_back(x);
    }
    map<int, vector<int> > zbiory;
    for(int i=1; i<maxi; i++) {
      int sum = 0;
      for(int j=0; j<points.size(); j++) {
        if(i & (1<<j))
          sum += points[j];
      }
      zbiory[sum].push_back(i);
//       if(!sol2.empty()) {
//         ok = true;
//         for(int j=0; j<points.size(); j++) {
//           if(i & j)
//             cout << points[j] << ' ';
//           cout << '\n';
//           for(int j=0; j<sol2.size(); j++)
//             cout << sol2[j] << ' ';
//           cout << '\n';
//         }
//         break;
//       }
    }
    map<int,vector<int> >::iterator it;
    for(it = zbiory.begin(); it != zbiory.end(); it++) {
//       cerr << it->first << ' ' << it->second.size() << endl;
      if(it->second.size() < 500) {
        if(find_answer(it->second, points))
          return;
      }
      else {
        if(random_answer(it->second, points))
          return;
      }
    }
  cout << "Impossible\n";
}
int main() {
  int t;
  cin >> t;
  for(int z=1; z<=t; z++) {
    cout << "Case #" << z << ":\n";
    solve();
  }
  return 0;
}