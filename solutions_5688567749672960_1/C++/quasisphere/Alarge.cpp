#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<utility>
#include<sstream>

using namespace std;

int64_t calc(int64_t n) {
  if(n == 1) return 1;
  if(n%10 == 0) return calc(n-1) + 1;
  stringstream ss;
  ss << n;
  string s=ss.str();
  int64_t d=(s.size()+1)/2;
  int64_t p=1;
  for(int64_t i=0;i<d;i++) p*=10;
  int64_t count=n%p - 1;
  if(n%p == 1) {
    reverse(s.begin(),s.end());
    int64_t nxt;
    stringstream(s) >> nxt;
    if(nxt == n) return calc(n-1) + 1;
    return calc(nxt) + 1;
  }
  return calc(n-count) + count;
}

int main(void) {
  int64_t T;
  cin >> T;
  for(int64_t t=1;t<=T;t++) {
    int64_t n;
    cin >> n;
    cout << "Case #" << t << ": " << calc(n) << "\n";
  }
  return 0;
}

