#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

ll gcd(ll a, ll b)
{
  if(a == 0)
    return b;

  if(a > b){
    ll tmp = a;
    a = b;
    b = tmp;
  }
  
  return gcd(b%a, a);
}

int main()
{
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    string s;
    cin >> s;
    ll P, Q;
    P = Q = 0;
    int i = 0;
    while(s[i] != '/'){
      P = P*10 + s[i] - '0';
      ++i;
    }
    ++i;
    while(i < s.size()){
      Q = Q*10 + s[i] - '0';
      ++i;
    }
    
    ll common = gcd(P,Q);
    P = P/common; Q = Q/common;
    // check if q is power of 2
    ll temp = Q;
    while(temp){
      if(temp & 1 == 1)
	break;
      temp /= 2;
    }
    if(temp == 1){
      ll ans = 0;
      while(P < Q){
	if(Q & 1 == 1)
	  break;
	Q = Q/2;
	++ans;
      }
      if(P < Q)
	cout << "Case #" << t << ": " << "impossible" << endl;
      else
	cout << "Case #" << t << ": " << ans << endl;
    }
    else
      cout << "Case #" << t << ": " << "impossible" << endl;
  }
  return 0;
}
