#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int nC[1000001];

bool isC(char c) {
  return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

bool areC(const string& s, int i, int n) {
  for (int c = 0; c < n; c++)
    if (!isC(s[i+c]))
      return false;
  return true;
}

ll solve2 (const string& s, int n) {
  ll sum = 0; int iCh = 0, j;
  for (int i = 0; i + n <= s.length(); i++) {
    if (areC(s, i, n)) {
      j = i + n - 1;
      sum += ((i + 1 - iCh) * (s.length() - j));
      iCh = i+1;
    }
  }
  return sum;
}

bool hasCn (const string& s, int i, int j, int n) {
  for (int k = i; k + n - 1 <= j; k++) {
    if (areC(s,k,n))
      return true;
  }
  return false;
}

ll solve (const string& s, int n) {
  ll sum = 0;
  
  for (int i = 0; i < s.length(); i++) {
    for (int j = i + n - 1; j < s.length(); j++) {
      if (hasCn(s,i,j,n)) {
        sum++;
      }
    }
  }

  return sum;
}

int main () {
  int n, T; cin >> T;
  string s;

  for (int t = 1; t <= T; t++) {
    cin >> s >> n; 
    ll ans = solve2(s,n);
    cout << "Case #" << t << ": " << ans << endl;
  }

  return 0;
}
