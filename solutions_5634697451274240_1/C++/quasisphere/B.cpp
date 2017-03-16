#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>
#include<iomanip>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);

  int64_t T;
  cin >> T;
  for(int64_t t=1;t<=T;t++) {
    string s;
    cin >> s;
    char first=s[0];
    char last=s[s.size() - 1];
    int64_t changes=0;
    for(int64_t i=1;i<s.size();i++) {
      if(s[i] != s[i-1]) changes++;
    }
    if(first == '-') {
      int64_t minuses=(changes+2)/2;
      cout << "Case #" << t << ": " << 2*minuses - 1 << "\n";
    } else {
      int64_t minuses=(changes+1)/2;
      cout << "Case #" << t << ": " << 2*minuses << "\n";
      //+-+-+-+-+-+-
    }
  }
  return 0;
}

