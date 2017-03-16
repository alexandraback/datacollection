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

void add(LL x, vector<bool>& v){
  while(x > 0){
	v[x%10] =true;
	x /= 10;
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1){
	LL N;
	cin >> N;
	if(!N){
	  cout << "Case #" << t << ": " << "INSOMNIA" << endl;
	  continue;
	}

	LL ans = 0;
	vector<bool> ok(10,false);
	while(count(ALL(ok),true) < 10){
	  ans += N;
	  add(ans, ok);
	}
	
	cout << "Case #" << t << ": " << ans << endl;
  }
  
  return 0;
}
