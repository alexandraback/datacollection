#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

int main(void) {
  int64_t T;
  cin >> T;
  for(int64_t t=1;t<=T;t++) {
    int64_t smax;
    cin >> smax;
    string s;
    cin >> s;
    int64_t total=0,add=0;
    for(int64_t i=0;i<=smax;i++) {
      if(s[i] != '0') {
        if(total < i) {
          add+=i-total;
          total+=add;
        }
      }
      total+=s[i]-'0';
    }
    cout << "Case #" << t << ": " << add << "\n";
  }
  return 0;
}

