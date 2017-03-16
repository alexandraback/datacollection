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

LL C, D, V;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1){
	cin >> C >> D >> V;
	VI xs(D);
	REP(i,D){
	  cin >> xs[i];
	}
	SORT(xs);

	LL v = 0, ans = 0;
	for(int i=0;i<D;++i){
	  if(v+1 < xs[i]){
		++ans;
		v += C * (v+1);
		--i;
	  }
	  else{
		v += C * xs[i];
	  }
	}
	while(v < V){
	  ++ans;
	  v += C * (v+1);
	}

	cout << "Case #" << t << ": " << ans << endl;
  }
  
  return 0;
}
