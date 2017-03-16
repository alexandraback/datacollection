#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100000000;
vector<bool> isprime;
vector<int> factors;

void sieve(){
  isprime.assign(MAXN, 1);
  factors.resize(MAXN);
  isprime[0] = isprime[1] = false;
  for (int i = 2; i < MAXN; i++){
    if (isprime[i]){
      for (ll j = (ll) i * i; j < MAXN; j += i){
	isprime[j] = false;
	factors[j] = i;
      }
    }
  }
}

ll trial(ll num){
  assert(num > 1);
  if (num <= 3) return 0;
  if (num % 2 == 0) return 2;
  for (ll i = 3; i * i <= num; i += 2)
    if (num % i == 0) return i;
  return 0;
}

ll power(int base, int id){
  ll res = 1;
  while (id--){
    res *= base;
  }
  return res;
}

void solve(int n, int k){
  int found = 0;
  for (ll mask = 1; mask < (1LL << (n-2)); mask++){
    bool comp = true;
    vector<ll> ans;
    for (int base = 2; base <= 10; base++){
      ll num = 1 + power(base, n - 1);
      for (int id = n-3; id >= 0; id--){
	if ((1LL << id) & mask)
	  num += power(base, id + 1);
      }
      if (num < MAXN) {
	if (isprime[num]){
	  comp = false;
	  break;
	} else ans.push_back(factors[num]);
      } else {
	ll x = trial(num);
	if (x == 0) {
	  comp = false;
	  break;
	} else ans.push_back(x);
      }
    }
    if (comp){
      cout << 1;
      for (int id = n-3; id >= 0; id--){
	if ((1LL << id) & mask) {
	  cout << 1;
	} else {
	  cout << 0;
	}
      }
      cout << 1;
      for (ll x : ans){
	cout << ' ' << x;
      }
      cout << endl;
      found++;
      if (found == k) break;
    }
  }
}

int main(){
  sieve();
  int tc, n, k; cin >> tc >> n >> k;
  cout << "Case #" << 1 << ":" << endl;
  solve(n, k);

  return 0;
}
