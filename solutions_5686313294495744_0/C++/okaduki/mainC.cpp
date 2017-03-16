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


int bc(int x){
  int res =0;
  while(x >0){
	res += x&1;
	x >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(tt,1,T+1){
	int N; cin >> N;
	vector<pair<string,string>> vps(N);
	REP(i,N) cin >> vps[i];
	int ans = 0;
	for(int bit=0;bit<(1<<N);++bit){
	  set<string> s1, s2;
	  bool ok = true;
	  REP(i,N){
		if(bit>>i&1){
		  s1.insert(vps[i].FF);
		  s2.insert(vps[i].SS);
		}
	  }
	  REP(i,N){
		if(bit>>i&1){}
		else{
		  if(!s1.count(vps[i].FF) || !s2.count(vps[i].SS)){
			ok = false;
		  }
		}
	  }
	  if(ok) ans = max(ans, N-bc(bit));
	}
	
	cout << "Case #" << tt << ": " << ans << endl;
  }
  
  return 0;
}
