#pragma comment(linker, "/STACK:46777216")

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned char byte;
typedef pair<int, int> pii;
#define forn(i,n) for (ll i = 0; i < ll(n); ++i)
#define mp make_pair

bool isv(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
}

int main() {
  int T;
  cin >> T;
  forn (_, T) {
    cout << "Case #" << (_ + 1) << ": ";
    string s; cin >> s;
    int n; cin >> n;

    ll result = 0;
    ll pos = -1000000000;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (!isv(s[i])) ++cnt; else cnt = 0;
      if (cnt >= n) pos = i - n;
      if (pos >= -1) {
        result += (pos + 2);
      }
    }
    
    cout << result << endl;
  }


  return 0;
}