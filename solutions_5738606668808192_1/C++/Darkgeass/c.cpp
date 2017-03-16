#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int n,m,J,ncount;
int bits[40];

void solve(){
  memset(bits,0,sizeof(bits));
  bits[0] = 1;
  bits[n-1] = 1;
  for(int a = 0; a < m; ++a){
    bits[2*a+1] = 1;
    for(int b = a+1; b < m; ++b){
      bits[2*b+1] = 1;
      for(int c = 0; c < m; ++c){
	bits[2*c+2] = 1;
	for(int d = c+1; d < m; ++d){
	  bits[2*d+2] = 1;
	  for(int i = n-1; i >= 0; --i) cout << bits[i];
	  cout << " 3 2 3 2 7 2 3 2 3\n";
	  ++ncount;
	  if(ncount == J) return;
	  bits[2*d+2] = 0;
	}
	bits[2*c+2] = 0;
      }
      bits[2*b+1] = 0;
    }
    bits[2*a+1] = 0;
  }
}

int main(){
  int t; cin >> t;
  for(int cass = 1; cass <= t; ++cass){
    cin >> n >> J;
    m = n/2-1;
    ncount = 0;
    cout << "Case #" << cass << ": \n";
    solve();
  }
}