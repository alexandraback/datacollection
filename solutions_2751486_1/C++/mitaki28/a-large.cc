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

int n;
string s;

bool is_consonants(char c){
  if(c != 'a' &&  c != 'e' && c != 'i' && c != 'o' && c != 'u') return true;
  return false;
}

ll solve(){
  if(n == 0){
	ll r = 0;
	REPN(i, SIZE(s)) r += i;
	return r;
  }
  int m = SIZE(s);
  int p = 0, q = 0, ct = 0, last_v = -1;
  ll r = 0;
  while(q < m){
	while(p < m && ct < n){
	  if(is_consonants(s[p])){
		ct++;
	  }else{
		ct = 0;
		last_v = p;
	  }
	  p++;
	}
	if(ct >= n) r += m - p + 1;
    if(is_consonants(s[q]) && q > last_v) ct--;
	q++;
  }
  return r;
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
	cin >> s >> n;
	printf("Case #%d: %lld\n", t + 1, solve());
  }
  return 0;
}
