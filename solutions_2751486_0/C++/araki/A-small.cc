#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

bool iscons(char c) {
  if(c != 'a' && 
     c != 'e' && 
     c != 'i' && 
     c != 'o' && 
     c != 'u') return true;
  else return false;
}

vector<int> find_cons(string name, int n) {
  vector<int> r;
  for(int i = 0; i < name.size(); i++) {
    int j;
    for(j = 0; j < n; j++) {
      if(i + j < name.size() && iscons(name[i+j])) continue;
      else break;
    }
    if(j == n) r.push_back(i);
  }
  return r;
}

int solve(string name, int n){
  vector<int> r = find_cons(name, n);
  set<pair<int, int> > substr;
  for(int i = 0; i < r.size(); i++) {
    for(int j = 0; j <= r[i]; j++) {
      for(int k = r[i] + n - 1; k < name.size(); k++) {
	substr.insert(make_pair(j, k));
      }
    }
  }
  return substr.size();
}

int main(){
  int num_cases;
  cin >> num_cases;
  for(int i = 0; i < num_cases; i++){
    string name; int n;
    cin >> name >> n;
    int r = solve(name, n);
    cout << "Case #" << i+1 << ": " << r << endl;
  }
}
