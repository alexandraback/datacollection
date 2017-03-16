#include <bits/stdc++.h>

using namespace std;

#define upto(i,n) for (int i = 0; i<n; ++i)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAX = 1000;
const ll MOD = 1000000007;



void solve() {
  ll c,d,v;
  ll tmp; 
  priority_queue<ll, vector<ll>, greater<ll> > pq;

  cin >> c >> d >>v;

  int sum = 0;
  upto(i, d) {
    cin >> tmp; 
    pq.push(tmp);
  }

  ll best = c;

  if ( pq.top() == 1 )
    pq.pop();
  else
    sum++;


  while ( best < v ) {
    while ( !pq.empty() ) {
      ll x = pq.top(); 
      //cout << x << ", best: " << best<< endl;
      if ( x <= best+1) {
        pq.pop();
        best = x*c+best;
      }
      else {
        pq.push(best+1);
        sum++;
      }
      if ( best >= v )
        goto END;
    }
      pq.push(best+1);
      sum++;
  }
END:
  cout << sum << endl;

}

int main() {
  int t;

  cin >> t;
  for ( int tc = 1; tc<=t; ++tc) {
    cout << "Case #" << tc<< ": ";
    solve();
  }
  return 0;
}
