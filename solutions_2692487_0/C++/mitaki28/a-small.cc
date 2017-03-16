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

const int MAX_N = 110;
const int INF = 1 << 28;
const double EPS = 1e-9;
const double PI = 3.14159265358979;

int n, k;
int a[MAX_N];

int dfs(int i, int size){
  if(i == n) return 0;
  else if(size > a[i]){
	return dfs(i + 1, size + a[i]);
  }else{
	int r = dfs(i + 1, size) + 1;
	int ct = 0;
	while(size <= a[i]){
	  size += size - 1;
	  ct++;
	}
	return min(r, dfs(i + 1, size + a[i]) + ct);
  }
}

int solve(){
  if(k == 1) return n;
  sort(a, a + n);
  return dfs(0, k);
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
	cin >> k >> n;
	REP(i, n) cin >> a[i];
	printf("Case #%d: %d\n", t + 1, solve());
  }
  return 0;
}
