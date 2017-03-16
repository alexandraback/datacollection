#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<utility>
#include<sstream>

using namespace std;

int main(void) {
  int64_t T;
  cin >> T;
  vector<int64_t> res(1000001,1000000);
  res[1]=1;
  for(int64_t i=1;i<=1000000;i++) {
    int64_t nxt=i+1;
    if(nxt <= 1000000) {
      res[nxt]=min(res[nxt],res[i]+1);
    }
    stringstream ss;
    ss << i;
    string s=ss.str();
    reverse(s.begin(),s.end());
    stringstream(s) >> nxt;
    if(nxt <= 1000000) {
      res[nxt]=min(res[nxt],res[i]+1);
    }
  }
  for(int64_t t=1;t<=T;t++) {
    int64_t n;
    cin >> n;
    cout << "Case #" << t << ": " << res[n] << '\n';
  }
  return 0;
}

