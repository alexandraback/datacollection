#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>
#include<functional>
#include<queue>

#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define FORN(i, a, n) for(int i = (a); i <= (n);i++)
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define ABS(x) (x) > 0 ? (x) : -(x)
#define SIZE(vec) (int)vec.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAX_D = 15;
const ll MAX_N = 10001000;
const int INF = 1 << 28;
const int EPS = 1e-9;

ll l, r;
ll nums[MAX_N];

bool is_palindrome(ll x){
  int d[MAX_D];
  int n = 0;
  while(x > 0){
	d[n++] = x % 10;
	x /= 10;
  }
  int p = 0, q = n - 1;
  while(p <= q){
	if(d[p++] != d[q--]) return false;
  }
  return true;
}

void init(){
  memset(nums, 0, sizeof(nums));
  ll ct = 0;
  nums[0] = 0;
  for(ll k = 1; k * k <= 1e14; k++){
	if(is_palindrome(k) && is_palindrome(k * k)){
	  ct++;
	}
	nums[k] = ct;
  }
}

int main(){
  int T;
  cin >> T;
  init();
  REP(t, T){
	cin >> l >> r;

	ll ub = MAX_N, lb = 0;
	while(ub - lb > 1){
	  ll mid = (ub + lb) / 2;
	  if(mid * mid >= l){
		ub = mid;
	  }else{
		lb = mid;
	  }
	}
	int l1 = lb;
	
	ub = MAX_N, lb = 0;
	while(ub - lb > 1){
	  ll mid = (ub + lb) / 2;
	  if(mid * mid <= r){
		lb = mid;
	  }else{
		ub = mid;
	  }
	}

	int r1 = lb;
	printf("Case #%d: %lld\n", t + 1, nums[r1] - nums[l1]);
  }
  return 0;
}
