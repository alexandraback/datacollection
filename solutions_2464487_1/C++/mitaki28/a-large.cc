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

const int INF = 1 << 28;
const double EPS = 1e-9;
const double PI = 3.14159265358979;

ll r, t;

int main(){
  int T;
  cin >> T;
  REP(ts, T){
	cin >> r >> t;
	ll ub = 1LL << 31, lb = 0;
	while(ub - lb > 1){
	  ll mid = (ub + lb) / 2;
	  if(2 * mid * mid + (2 * r - 1) * mid > t){
		ub = mid;
	  }else{
		lb = mid;
	  }
	}
	printf("Case #%d: %lld\n", ts + 1, lb);
  }
  return 0;
}
