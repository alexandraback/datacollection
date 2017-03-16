#include <bits/stdc++.h>

using namespace std;

#define upto(i,n) for (int i = 0; i<n; ++i)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAX = 1000;
const ll MOD = 1000000007;


int res[1000];

void solve() {
  int c,d,v;
  int tmp; 

  memset(res, 0, sizeof(res));

  cin >> c >> d >>v;

  upto(i, d) {
    cin >> tmp;
    for ( int j = v; j>=1; j--) 
      if ( res[j] ) res[j+tmp] = 1;
    res[tmp] = 1; 
  } 

  int sum =0;
  for ( int i = 1; i<=v ; i++) {
    if ( res[i] == 0 ) {
      sum++;
     for ( int j = v; j>=1; j--) 
        if ( res[j] ) res[j+i] = 1;
      res[i] = 1;
    }  
  }

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
