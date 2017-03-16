#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
int primes[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int NUMPRIMES = 10;
int factors[12][20][40];

void gen_factors(){
  for (int base = 2; base <= 10; base++)
    for(int p = 0; p < NUMPRIMES; p++)
      factors[base][p][0] = 1;
      
  for (int base = 2; base <= 10; base++){
    for (int p = 0; p < NUMPRIMES; p++){
      int prime = primes[p];
      for (int pw = 1; pw < 40; pw++){
	factors[base][p][pw] = factors[base][p][pw-1] * base % prime;
      }
    }
  }
}

void solve(int n, int J){
  int tot = 0;
  for (ll mask = 1; mask < (1LL << n); mask++){
    if (((1LL << (n-1)) & mask) == 0) continue;
    if ((1LL & mask) == 0) continue;
    bool iscomp = true;
    vi ans;
    for (int base = 2; base <= 10; base++){
      bool found = false;
      for (int p = 0; p < NUMPRIMES; p++){
	ll sum = 0;
	for (int j = 0; j < n; j++){
	  if ((1LL << j) & mask){
	    sum += factors[base][p][j];
	  }
	}
	if (sum % primes[p] == 0) {
	  found = true;
	  ans.push_back(primes[p]);
	  break;
	}
      }
      if (!found){
	iscomp = false;
	break;
      }
    }
    if (iscomp) {
      for (int j = n-1; j >= 0; j--){
	if ((1LL << j) & mask){
	  cout << 1;
	} else cout << 0;
      }
      for (int x : ans) cout << ' ' << x;
      cout << endl;
      tot++;
      if (tot == J) return;
    }
  }
}

int main(){
  gen_factors();
  int tc, n, J; cin >> tc >> n >> J;
  assert(tc == 1);
  cout << "Case #1:" << endl;
  solve(n, J);


  return 0;
}
