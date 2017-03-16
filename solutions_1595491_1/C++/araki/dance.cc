#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int solve(int,int,int,vector<int>&);

int main(){
  int num_cases;
  cin >> num_cases;
  for(int i = 0; i < num_cases; i++){
    int n, s, p;
    vector<int> t;
    cin >> n >> s >> p;
    for(int j = 0; j < n; j++) {
      int t0;
      cin >> t0;
      t.push_back(t0);
    }
    int r = solve(n,s,p,t);
    cout << "Case #" << i+1 << ": " << r << endl;;
  }
}

int solve(int n, int s, int p, vector<int>& t){
  int res = 0;
  for(int i = 0; i < n; i++){
    int d = t[i] / 3;
    int r = t[i] % 3;
    int max;
    if(r == 0) max = d;
    else max = d + 1;
    if(p <= max) res++;
    else if(max == p - 1 && r != 1 && t[i] != 0 && s > 0) {res++; s--;}
  }
  return res;
}
