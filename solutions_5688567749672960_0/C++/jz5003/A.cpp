/*
ID: jeffrey31
LANG: C++
TASK: A
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
typedef long long ll;

const int N = 1000010;
int t, f[20];
ll p[16];
string s;
int main() {
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  cin >> t;
  p[0] = 1;
  for(int i = 1; i < 16; i++) {
    p[i] = p[i-1]*10;
  }
  f[1] = 10;
  for(int i = 2; i <= 14; i++) {
    if(i % 2 == 0) {
      f[i] = (p[i/2] - 1) * 2;
      f[i]++;
    } else {
      f[i] = f[i-1] + 9 * p[i/2];
    }
  }
  for(int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    cin >> s;
    ll ans = 0;
    for(int j = 1; j < s.length(); j++) {
      ans += f[j];
    }
    if(s[s.length() - 1] == '0') {
      ll num = 0;
      int dig = 0;
      for(int j = 0; j < s.length(); j++) {
        num += p[j] * (s[s.length() - j - 1]- '0');
        dig += (s[j] - '0');
      }
      num--;
      if(dig == 1) {
        cout << ans << endl;
        continue;
      } else {
        for(int j = 0; j < s.length(); j++) {
          s[s.length() - j - 1] = (char)(num % 10 + '0');
          num /= 10;
        }
        ans++;
      }
    }    
    ll mid = 0;
    ll le= 0, ri = 0;
    for(int j = 1; j < s.length()/2; j++) {
      le += ((s[j]-'0') )*p[j];
    }
    if(s.length()/2 > 0)
      le += (s[0] -'0') - 1;
    for(int j = 0; j < s.length()/2; j++) {
      ri += ((s[s.length() - j - 1] - '0') * p[j]);
    }
    if(s.length() % 2) {
      mid = (s[s.length()/2] - '0') * p[s.length()/2];
    }
    if(le == 0) {cout << ans + ri + mid << endl;}
    else {
      cout << ans + le + ri + mid + 1 << endl;
    }
  }
  return 0;
}