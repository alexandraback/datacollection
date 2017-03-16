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
  int r = 0;
  int L = SIZE(s);
  REP(i, L){
	int k = 0;
	bool flag = false;
	FOR(j, i, L){
	  if(is_consonants(s[j])) k++;
	  else k = 0;
	  if(flag || k >= n){
		r++;
		flag = true;
	  }
	}
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
