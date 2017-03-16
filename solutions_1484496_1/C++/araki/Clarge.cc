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

pair<vector<long long>, vector<long long> > solve(long long,vector<long long>);

int main(){
  long long num_cases;
  cin >> num_cases;
  for(long long i = 0; i < num_cases; i++){
    vector<long long> s;
    long long s0, n;
    cin >> n;
    for(long long j = 0; j < n; j++) {
      cin >> s0;
      s.push_back(s0);
    }
    pair<vector<long long>, vector<long long> > r = solve(n,s);
    cout << "Case #" << i+1 << ": " << endl;
    if(r.first.size() == 0) cout << "Impossible" << endl;
    else {
      for(long long i = 0; i < r.first.size(); i++) cout << (r.first)[i] << " ";
      cout << endl;
      for(long long i = 0; i < r.second.size(); i++) cout << (r.second)[i] << " ";
      cout << endl;
    }
  }
}

pair<vector<long long>,vector<long long> > solve(long long n, vector<long long> s){
  vector<long long> data(n);
  map<long long, vector<long long> > mymap;
  map<long long, vector<long long> >::iterator it;
  pair<vector<long long>, vector<long long> > sets;
  for(long long i = 0; i < n; i++) data[i] = i;
  bool found = false;
  for(long long i = 1; i < n; i++) {
    vector<long long> d(data);
    do {
      long long sum = 0;
      for(long long j = 0; j < i; j++) sum+=s[d[j]];
      vector<long long> d2;
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
  pair<vector<long long>, vector<long long> > values;
  if(!found) return values;
  else {
    for(long long i = 0; i < sets.first.size(); i++)
      values.first.push_back(s[sets.first[i]]);
    for(long long i = 0; i < sets.second.size(); i++)
      values.second.push_back(s[sets.second[i]]);
    return values;
  }
}
