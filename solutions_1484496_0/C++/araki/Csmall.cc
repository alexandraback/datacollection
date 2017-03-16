#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

// from http://photon.poly.edu/~hbr/boost/combinations.html
#include "combination.hpp"

using namespace std;
using namespace boost;

pair<vector<int>, vector<int> > solve(int,vector<int>);

int main(){
  int num_cases;
  cin >> num_cases;
  for(int i = 0; i < num_cases; i++){
    vector<int> s;
    int s0, n;
    cin >> n;
    for(int j = 0; j < n; j++) {
      cin >> s0;
      s.push_back(s0);
    }
    pair<vector<int>, vector<int> > r = solve(n,s);
    cout << "Case #" << i+1 << ": " << endl;
    if(r.first.size() == 0) cout << "Impossible" << endl;
    else {
      for(int i = 0; i < r.first.size(); i++) cout << (r.first)[i] << " ";
      cout << endl;
      for(int i = 0; i < r.second.size(); i++) cout << (r.second)[i] << " ";
      cout << endl;
    }
  }
}

pair<vector<int>,vector<int> > solve(int n, vector<int> s){
  vector<int> data(n);
  map<int, vector<int> > mymap;
  map<int, vector<int> >::iterator it;
  pair<vector<int>, vector<int> > sets;
  for(int i = 0; i < n; i++) data[i] = i;
  bool found = false;
  for(int i = 1; i < n; i++) {
    vector<int> d(data);
    do {
      int sum = 0;
      for(int j = 0; j < i; j++) sum+=s[d[j]];
      vector<int> d2;
      copy(d.begin(),d.begin()+i,back_inserter(d2));
      if((it = mymap.find(sum)) != mymap.end()) {
	sets.first = (*it).second;
	sets.second = d2;
	found = true;
	break;
      } else {
	mymap[sum] = d2;
      }
    } while(next_combination(d.begin(), d.begin()+i, d.end()));
    if(found) break;
  }
  pair<vector<int>, vector<int> > values;
  if(!found) return values;
  else {
    for(int i = 0; i < sets.first.size(); i++)
      values.first.push_back(s[sets.first[i]]);
    for(int i = 0; i < sets.second.size(); i++)
      values.second.push_back(s[sets.second[i]]);
    return values;
  }
}
