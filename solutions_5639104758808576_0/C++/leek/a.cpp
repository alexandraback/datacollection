#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int k;
string s;

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {

    int ret = 0;
    cin >> k >> s;
    int standing = (s[0]-'0');

    for(int i=1; i<s.size(); i++) {
      if(s[i] =='0') continue;
      if(i > standing) {
        int val = i-standing;
        standing += (s[i]-'0');
        standing += val;
        ret += val;
      }
      else {
        standing += (s[i]-'0');
      }

    }

    printf("Case #%d: %d\n",tc,ret);


  }

  return 0;
}