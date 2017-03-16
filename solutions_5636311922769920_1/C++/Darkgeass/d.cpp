#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll s,k,c;

int main(){
  int t; cin >> t;
  for(int cass = 1; cass <= t; ++cass){
    cin >> k >> c >> s;
    if(k > c*s) cout << "Case #" << cass << ": IMPOSSIBLE\n";
    else{
      cout << "Case #" << cass << ":";
      vi check(c);
      ll aux = k/c; if(k%c) ++aux;
      for(ll i = 0; i < aux; ++i){
	for(ll j = 0; j < c; ++j){
	  check[j] = min(k-1,j+c*i);
	}
	ll aux2 = 0;
	for(ll j = 0; j < c; ++j){
	  aux2 *= k;
	  aux2 += check[j];
	}
	cout << ' ' << aux2+1;
      }
      cout << '\n';
    }
  }
}