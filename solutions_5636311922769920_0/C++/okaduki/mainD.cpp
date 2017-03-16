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

LL pow(LL x, LL y){
  if(y == 0) return 1;
  return pow(x*x,y/2) * (y%2?x:1);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1){
	LL K, C, S; cin >> K >> C >> S;
	if((K+C-1)/C > S){
	  cout << "Case #" << t << ": IMPOSSIBLE" << endl;
	  continue;
	}
	cout << "Case #" << t << ":";
	for(LL i=0;i<K;i+=C){
	  LL b = 0;
	  for(LL n=0;n<C&&n+i<K;++n){
		b += pow(K, C-n-1) * (i+n);
	  }
	  cout << " " << b+1;
	}
	cout << endl;
  }
  
  return 0;
}
