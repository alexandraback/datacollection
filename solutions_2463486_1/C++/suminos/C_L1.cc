#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(c) (c).begin(), (c).end()
typedef long long ll;
const ll SQRT = 1e+7;

bool is_palindrome(ll x) {
  char s[100];
  sprintf(s, "%lld", x);
  int len = strlen(s);
  for(int i=0; i<len/2; i++)
    if(s[i] != s[len-i-1])
      return false;
  return true;
}

int main() {
  vector<ll> nums;
  for(ll i=1; i<=SQRT; i++)
    if(is_palindrome(i) && is_palindrome(i*i))
      nums.push_back(i*i);
  
  int T; cin >> T;
  for(int t=1; t<=T; t++) {
    ll A, B; cin >> A >> B;
    ll ans =
      ( lower_bound(all(nums), B+1) - nums.begin() ) -
      ( lower_bound(all(nums), A  ) - nums.begin() );
    cout << "Case #" << t << ": " << ans << endl;
  }
}
