#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

char digits[][10] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
char rep[] = {
  'Z', 'N', 'W', 'H', 'U', 'F', 'X', 'V', 'G', 'I'
};
int pos[] = {
  0, 2, 4, 6, 5, 7, 8, 9, 3, 1
};

int main(void){
  int T;
  cin >> T;
  for(int tt = 0; tt < T; ++tt) {
    string s;
    cin >> s;
    int cnt[10];

    map<char, int> m;
    for(int i = 0; i < s.size(); ++i){
      if(m.find(s[i]) == m.end())
        m[s[i]] = 0;
      ++m[s[i]];
    }

    for(int i = 0; i < 10; ++i) {
      int j = pos[i];
      cnt[j] = m[rep[j]];
      for(int k = 0; k < strlen(digits[j]); ++k)
        m[digits[j][k]] -= cnt[j];
    }

    string res;
    for(int i = 0; i < 10; ++i)
      for(int j = 0; j < cnt[i]; ++j)
        res += i + '0';

    cout << "Case #" << tt+1 << ": " << res << endl;
  }

  return 0;
}
