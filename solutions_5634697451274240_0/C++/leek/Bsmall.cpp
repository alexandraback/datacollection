#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
string s;



int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    cin >> s;
    int ret = 0;
    int fp = 0;
    while(fp < s.size()) {
      if(s[fp] == '+') break;
      fp ++;
    }

    if(fp > 0) ret ++;
    for(int i=fp; i<s.size()-1; i++) {
      if(s[i] == '+' && s[i+1] == '-') {
        ret += 2;
      }
    }

    printf("Case #%d: %d\n",tc,ret);


  }

  return 0;
}