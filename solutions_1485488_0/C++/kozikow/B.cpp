#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <map>
#include <algorithm>
#define EPS 1e-9
using namespace std;
typedef long long LL;

bool check_zbi(vector<LL>& zbi) {
  sort(zbi.begin(), zbi.end());
  for(int i=1; i<zbi.size(); i++)
    if(zbi[i] == zbi[i-1])
      return false;
  return true;
}

bool intersect(const vector<LL>& zb1, const vector<LL>& zb2) {
  int last = 0;
  for(int i=0; i<zb1.size(); i++) {
    while(last < zb2.size() && zb2[last] < zb1[i])
      last++;
    if(last != zb2.size() && zb1[i] == zb2[last])
      return true;
  }
  return false;
}

void wypisz(const vector<LL>& zb) {
  for(int i=0; i<zb.size(); i++)
    cout << zb[i] << ' ';
}


bool check(vector<vector<LL> >& zbi) { 
  if(!check_zbi(zbi.back())) {
    zbi.pop_back();
    return false;
  }
  if(zbi.size() <= 1)
    return false;
  
  for(int i=0; i<(int)zbi.size()-1; i++) {
    if(!intersect(zbi[i], zbi.back())) {
      wypisz(zbi[i]);
      cout << '\n';
      wypisz(zbi.back());
      cout << '\n';
      return true;
    }
  }
  return false;
}

void solve() {
  int n;
  cin >> n;
  vector<LL> points;
  while(n--) {
    LL x;
    cin >> x;
    points.push_back(x);
  }
  map<LL, vector<vector<LL> > > zbiory;
  vector<LL> last;
  LL sum = 0;
  while(true) {
    int x = rand() % points.size();
    sum += points[x];
    last.push_back(points[x]);
    zbiory[sum].push_back(last);
    if(check(zbiory[sum]))
      return;
    if(last.size() > 10) {
      last.clear();
      sum = 0;
    }
  }
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