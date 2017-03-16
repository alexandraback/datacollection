//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
#include<cassert>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

vector<big> vec;
bool isp(big x){
  
  vector<int> v;
  while(x){
    v.push_back(x%10);
    x /= 10;
  }
  
  for(int i = 0 ; i < v.size()/2 ; i++)
    if(v[i] != v[v.size()-1-i])
      return false;
  return true;
}


int main() {
  
//    freopen("/Users/hamza/1.in", "rt", stdin);
  freopen("/Users/hamza/Downloads/C-small-attempt0.in", "rt", stdin);
  freopen("/Users/hamza/C-small-attempt0.out", "wt", stdout);
  
  for(big i = 1 ; i <= 10000000 ; i++){
    if(isp(i) && isp(i*i)){
      //cout << i << " " << i*i << endl;
      vec.push_back(i*i);
    }
  }
  
  int tt; cin >> tt;
  for(int t = 1 ; t <= tt; t++){
    big A, B; cin >> A >> B;
    int res = 0;
    for(int i = 0 ; i < vec.size() ; i++){
      if(vec[i] >= A && vec[i] <= B)
        res ++;
    }
    cout << "Case #" << t << ": " << res << endl;
  }
  
  return 0;
}
