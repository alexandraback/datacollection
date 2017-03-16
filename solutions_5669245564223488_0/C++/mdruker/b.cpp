#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

bool shareLetters(string a, string b) {
  for (char ch='a'; ch <= 'z'; ch++) {
    if (a.find(ch) != string::npos && b.find(ch) != string::npos) {
      return true;
    }
  }
  return false;
}

bool validTrain(string s) {
  for (int j=0; j<s.size(); j++) {
    for (int k=j+2; k<s.size(); k++) {
      if (s[k] != s[k-1] && s[k] == s[j]) {
	return false;
      }
    }
  }
  
  return true;
}

vector<string> cars;
vector<int> copies;
vector< vector<int> > nextcar;
vector<int> component;
vector< vector<int> > components;

long long curcount;
vector<bool> used;

void makeTrain(string CurTrain, int pos, int carnum, int target) {
  used[pos] = true;
  CurTrain += cars[pos];
  
  if (carnum == target) {
    if (validTrain(CurTrain)) {
      curcount++;
    }
    return;
  }
  
  for (int i=0; i<nextcar[pos].size(); i++) {
    if (component[nextcar[pos][i]] == component[pos] && !used[nextcar[pos][i]]) {
      makeTrain(CurTrain, nextcar[pos][i], carnum+1, target);
    }
  }
}

int main() {
  int T, N;
  long long M = 1000000007;
  in >> T;
  for (int curcase = 1; curcase <= T; curcase++) {
    in >> N;

    cars.clear();
    copies.clear();
    for (int i=0; i<N; i++) {
      string s;
      in >> s;
      
      bool notacopy=true;
      for (int j=0; j<cars.size(); j++) {
	if (cars[j] == s) {
	  copies[j]++;
	  notacopy=false;
	  break;
	}
      }
      if (notacopy) {
	cars.push_back(s);
	copies.push_back(1);
      }      
    }
    
    out << "Case #" << curcase << ": ";

    bool failed=false;
    for (int i=0; i<cars.size(); i++) {
      if (!validTrain(cars[i])) {
	failed = true;
	break;
      }
    }

    if (failed) {
      out << 0 << endl;
      continue;
    }

    nextcar.clear();
    nextcar.resize(cars.size());    
    component.clear();
    component.resize(cars.size());

    for (int i=0; i<cars.size(); i++) {
      component[i] = i;
    }

    for (int i=0; i<cars.size(); i++) {
      for (int j=0; j<cars.size(); j++) {
	if (i == j) {
	  continue;
	}
	if (shareLetters(cars[i], cars[j])) {
	  int OldComponent = component[j];
	  for (int k=0; k<cars.size(); k++) {
	    if (component[k] == OldComponent) {
	      component[k] = component[i];
	    }
	  }
	}
	
	if (validTrain(cars[i] + cars[j])) {
	  nextcar[i].push_back(j);
	}	  	  
      }
    }

    components.clear();
    components.resize(cars.size());
    for (int i=0; i<cars.size(); i++) {
      components[component[i]].push_back(i);
    }

    int realcomponents = 0;

    long long ans=1;
    for (int i=0; i<components.size(); i++) {
      if (components[i].size() == 0) {
	continue;
      } else {
	realcomponents++;
      }

      curcount=0;
      for (int j=0; j<components[i].size(); j++) {
	used.clear();
	used.resize(cars.size(),0);
	
	makeTrain("",components[i][j],1,components[i].size());
      }
      
      ans *= curcount;
      ans %= M;
      
      for (int j=0; j<components[i].size(); j++) {
	ans *= copies[components[i][j]];
	ans %= M;
      }      
    }

    for (int i=2; i<=realcomponents; i++) {
      ans *= i;
      ans %= M;
    }

    out << ans << endl;    
  }
}
