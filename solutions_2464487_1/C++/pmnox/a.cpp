int COND = 0;
#define ll long long
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>



using namespace std;

ll sum(ll x, ll num) {
	return num*(2*x+1) + 2*num*(num-1);
}

ll pot10[50];

ll solve() {
  ll r, t;
  scanf("%lld%lld", &r, &t);
  if (t < 0) return 0;
  ll res = 0;
  pot10[0] = 1;
  for (int i = 1; i < 50; i++) pot10[i] = pot10[i-1]*10;
  
  for (int i = 7; i >= 0; i -- ) {
	  while (t >= sum(r,pot10[i])) {
		  t -= sum(r,pot10[i]);
		  res += pot10[i];
		  r += 2*pot10[i];
	  }
  }
  ll ret = 0; 


  return res;
}

int main(int argc, char ** argv) {
	COND = argc >= 2 && argv[1][0] == 'q';
	int T;
	scanf("%d", &T);
	fo (my, 1, T) { printf("Case #%d: %lld\n", my, solve()); }
	return 0;
}
