#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> v;

bool palindrome(string s) {
  string r = s;
  reverse(s.begin(), s.end());
  return s == r;
}

//Stupid solution to asure that both small and large1 are correct.
//See large2's solution for a better approach (suposing it's correct and gets AC)
int main() {
  for (int i = 1; i <= 10000000; ++i) {
    ll x = i;
    stringstream ss;
    ss << x;
    string s;
    ss >> s;
    if (palindrome(s)) {
      x *= x;
      stringstream ss2;
      ss2 << x;
      ss2 >> s;
      if (palindrome(s)) v.push_back(x);
    }
  }
  
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    ll a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = 0; i < v.size(); ++i) if (a <= v[i] and v[i] <= b) ++res;
    cout << "Case #" << cas << ": " << res << endl;
  }
}