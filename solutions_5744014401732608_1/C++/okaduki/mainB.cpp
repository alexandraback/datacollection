#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

void answer(VVI& G){
  int N = SZ(G);
  REP(i,N){
	string s(N, '0');
	for(int to: G[i]) s[to] = '1';
	cout << s << endl;
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(ttt,1,T+1){
	LL B, M; cin >> B >> M;
	if(M > (1LL<<(B-2))){
	  cout << "Case #" << ttt << ": IMPOSSIBLE" << endl;
	  continue;
	}
	VVI G(B);
	for(int i=B-2;i>0;--i)
	  FOR(j,i+1,B) G[i].PB(j);

	FOR(i,1,B-1){
	  if(M >= 1LL<<(B-i-2)){
		G[0].PB(i);
		M -= 1LL<<(B-i-2);
	  }
	}
	if(M > 1){
	  cout << "Case #" << ttt << ": IMPOSSIBLE" << endl;
	}
	else if(M == 1)
	  G[0].PB(B-1);
	
	cout << "Case #" << ttt << ": POSSIBLE" << endl;
	answer(G);
  }
  
  return 0;
}
