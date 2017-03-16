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
const int INF = 1 << 28;
const int EPS = 1e-9;

int l, r;

bool is_palindrome(int x){
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

int main(){
  int T;
  cin >> T;
  REP(t, T){
	cin >> l >> r;
	int ct = 0;
	for(int k = 1; k * k <= r; k++){
	  if(k * k >= l && is_palindrome(k) && is_palindrome(k * k)){
		ct++;
	  }
	}
	printf("Case #%d: %d\n", t + 1, ct);
  }
  return 0;
}
