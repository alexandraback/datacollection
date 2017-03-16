#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-10;
static const double PI = 3.141592653589;
typedef long long ll;

vector<double> solve(int N, vector<int> S){
  vector<double> result;
  int sum = 0;
  for (int i = 0; i < N; ++i){
    sum += S[i];
  }
  for (int i = 0; i < N; ++i){
    double left = 0.0, right = 100.0, center;
    for(int j = 0; j < 200; j++){
      center = (left+right)/2.0;
      double score = S[i]+sum*center/100.0;
      double dsum=0.0;
      for(int k = 0; k < N; k++){
	if(i == k) continue;
	if(score > S[k])
	  dsum += score-S[k];
      }
      dsum = dsum-sum*(100.0-center)/100.0;
      if(dsum < 0) left = center;
      else right = center;
    }
    result.push_back(left);
  }
  return result;
}

int main(){
  int T, N;
  vector<int> S;
  cin >> T;
  for(int t = 1; t <= T; t++){
    cin >> N;
    S.clear();
    for (int i = 0; i < N; ++i){
      int a;
      cin >> a;
      S.push_back(a);
    }
    vector<double> res = solve(N, S);
    cout << "Case #" << t << ": ";
    for (int i = 0; i < N; ++i){
      printf("%.10f",res[i]);
      if(i < N-1) cout << " ";
    }
    cout << endl;
  }
  
  return 0;
}
