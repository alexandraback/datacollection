#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <numeric>
#include <stdio.h>

using namespace std;

vector<double> solve(int n, const vector<int>& s);

int main(){
  int num_cases;
  cin >> num_cases;
  for(int i = 0; i < num_cases; i++){
    int n, s0;
    vector<int> s;
    cin >> n;
    for(int j = 0; j < n; j++) {
      cin >> s0;
      s.push_back(s0);
    }
    vector<double> r = solve(n, s);
    cout << "Case #" << i+1 << ": ";
    for(int k = 0; k < n-1; k++) {
      printf("%f ", r[k]*100);
    } 
    printf("%f\n",r[n-1]*100);
  }
}

vector<double> solve(int n, const vector<int>& s){
  vector<double> r;
  vector<int> pass;
  int sum = accumulate(s.begin(), s.end(), 0);
  double ave = static_cast<double>(sum*2)/static_cast<double>(n);
  while(1) {
    bool occur = false;
    for(int i = 0; i < n; i++){
      int tosub = 0;
      if(find(pass.begin(),pass.end(),i) == pass.end() && ave < s[i]) {
	pass.push_back(i);
	occur = true;
      }
    }
    if(occur == true) {
      int tosub = 0;
      for(int i = 0; i < pass.size(); i++){
	tosub += s[pass[i]];
	ave = double(sum*2 - tosub) / double(n - pass.size());
      }
    } else break;
  }
  for(int i = 0; i < n; i++){
    if(find(pass.begin(),pass.end(),i) == pass.end())
      r.push_back((ave-static_cast<double>(s[i]))/
		  static_cast<double>(sum));
    else r.push_back(0.0);
  }
  return r;
}
