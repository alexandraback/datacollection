#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007

/*
*
* Zaiiiiiin
*
*/

using namespace std;

typedef pair<int,int> ii;

int T, t = 0;
ll k, c, s;

ll pw(ll x, ll p){
  ll ret = 1;
  for(int i=0; i<p; i++) ret *= x;
  return ret;
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> T;
  while(T--){
    cin >> k >> c >> s;
    ll n = pw(k, c-1);
    cout << "Case #" << ++t << ":";
    for(int i=0; i<s; i++)
      cout << " " << n * i + 1;
    puts("");
  }
  return 0;
}
