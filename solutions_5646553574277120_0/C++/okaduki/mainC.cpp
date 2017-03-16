#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int C, D, V;
int dfs(int idx, VI& nv, vector<bool>& ok, vector<bool>& use){
  if(SZ(nv) == idx) return 0;
  if(ok[nv[idx]]) return dfs(idx+1, nv, ok, use);

  int res = 1000;
  for(int i=1;i<=nv[idx];++i){
	if(use[i] || !ok[nv[idx] - i]) continue;
	use[i] = true;

	vector<bool> tmp = ok;
	VI buf;
	for(int v=0;v+i<=V;++v)
	  if(ok[v]) buf.PB(v+i);
	for(int j: buf)
	  ok[j] = true;
	res = min(res, 1+dfs(idx+1, nv, ok, use));

	ok = tmp;
	use[i] = false;
  }

  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1){
	// C == 1
	cin >> C >> D >> V;
	vector<bool> ok(V+1, false), use(V+1, false);
	VI xs(D);
	REP(i,D){
	  cin >> xs[i];
	  use[xs[i]] = true;
	}

	VI nv;
	ok[0] = true;
	REP(i,D){
	  VI buf;
	  for(int v=xs[i];v<=V;++v)
		if(ok[v-xs[i]]) buf.PB(v);
	  for(int j: buf)
		ok[j] = true;
	}
	FOR(i,1,V+1)
	  if(!ok[i]) nv.PB(i);

	//	cout<<SZ(nv)<<endl;
	int ans = dfs(0,nv,ok,use);
	
	cout << "Case #" << t << ": " << ans << endl;
  }
  
  return 0;
}
