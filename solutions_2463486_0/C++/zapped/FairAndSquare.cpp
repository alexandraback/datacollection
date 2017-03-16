#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <string.h>
#include <sstream>
#include <limits>
using namespace std;
typedef long long int64;
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
bool ispalindrome(long long x){
  string xp;
  if(x < 10)return true;
  xp = toString(x);
  int n = xp.size();
  for(int i = 0; i < n / 2; ++i){
    if(xp[i] != xp[n - i - 1])return false;
  }
  return true;
}
int main(){
  int T;
  long long a, b;
  long res = 0;
  cin>>T;
  b = 100000000000000;
  vector<long long> v;
  for(int64 i = 0; i <= sqrt(b); ++i){
      int64 xp = (int64)(i * i);
      if(ispalindrome(i) && ispalindrome(xp) && xp <= b){
	v.push_back(xp);
      }
  }							  
  for(int times = 0; times < T; ++times){
    cin>>a>>b;
    res = 0;
    for(int i = 0; i < v.size(); ++i){
      if(v[i] >= a && v[i] <= b)res++;
    }
    cout<<"Case #"<<times + 1<<": "<<res<<endl;
  }
  return 0;
}
