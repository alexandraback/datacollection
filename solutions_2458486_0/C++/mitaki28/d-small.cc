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

const int MAX_N = 20;
const int MAX_K = 210;
const int INF = 1 << 28;
const int EPS = 1e-9;

struct Treasure{
  int require;
  vector<int> keys;
};

int K, n;
int keys[MAX_K];
Treasure treasures[MAX_N];
int memo[1 << MAX_N];
int next[1 << MAX_N];
int r[MAX_N];

int dfs(int S){
  if(memo[S] != -1) return memo[S];
  if(S == (1 << n) - 1) return memo[S] = 1;
  REP(i, n) if(!(S & (1 << i))){
	Treasure &t = treasures[i];
	if(keys[t.require] > 0){
	  keys[t.require]--;
	  REP(j, SIZE(t.keys)) keys[t.keys[j]]++;
	  int r = dfs(S | (1 << i));
	  REP(j, SIZE(t.keys)) keys[t.keys[j]]--;
	  keys[t.require]++;
	  if(r == 1){
		next[S] = i;
		return memo[S] = 1;
	  }
	}
  }
  return memo[S] = 0;
}

bool solve(){
  int res = dfs(0);
  if(res == 0) return false;
  int S = 0;
  int i = 0;
  while(S != (1 << n) - 1){
	r[i++] = next[S];
	S = S | (1 << next[S]);
  }
  return true;
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
	memset(keys, 0, sizeof(keys));
	memset(memo, -1, sizeof(memo));
	cin >> K >> n;
	REP(i, K){
	  int k;
	  cin >> k;
	  keys[k]++;
	}
	REP(i, n){
	  int m;
	  cin >> treasures[i].require >> m;
	  treasures[i].keys.clear();
	  REP(j, m){
		int k;
		cin >> k;
		treasures[i].keys.push_back(k);
	  }
	}
	printf("Case #%d: ", t + 1);
	if(solve()){
	  REP(i, n) printf("%d%c", r[i] + 1, " \n"[i == n - 1]);
	}else{
	  printf("IMPOSSIBLE\n");
	}
  }
  return 0;
}
