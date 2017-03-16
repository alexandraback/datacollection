#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
#define sz(a)      (int)((a).size())
#define rep(i,n)   for(ll i=0; i<n; ++i)
#define REP(i,j,k) for(ll i=j; i<k; ++i)

int memo[10000001];

bool palindrome(ll a) {
  char s[256];
  sprintf(s, "%lld", a);
  int n = strlen(s);
  rep (i, n/2) if (s[i] != s[n-i-1]) return false;
  return true;
}

bool fair(ll a) {
  return palindrome(a) && palindrome(a * a);
}

int main () {
  int TC = 0;  scanf("%d", &TC);
  memo[0] = 0;
  REP (i, 1, 10000001) {
    memo[i] = memo[i-1] + fair(i) ;
  }
  
  rep (tc, TC) {
    cout << "Case #"<< tc+1 <<": ";
    ll A, B; cin >> A >> B;
    cout << memo[int(floor(sqrt(B)))] - memo[int(ceil(sqrt(A)))-1] << endl;
  }
  
  return 0;
}
