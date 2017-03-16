#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
//typedef long long LL;
using LL = __int128;
typedef pair<LL, LL> PLL;
typedef vector<LL> VL;
typedef vector<VL> VVL;

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

ostream& operator<<(ostream& os, LL x){
  string t;
  while(x > 0){
	t += (char)('0' + (x%10));
	x /= 10;
  }
  reverse(ALL(t));
  return os << t;
}

LL to(LL x, LL B){
  LL res = 0, p = 1;
  while(x > 0){
	if(x & 1) res += p;
	p *= B;
	x >>= 1;
  }
  return res;
}

LL isprime(LL x){
  for(LL d=2;d<=10;++d)
	if(x % d == 0)
	  return d;
  return 0;
}

string tobin(LL x){
  string res;
  while(x > 0){
	res += (char)('0' + (x&1));
	x >>= 1;
  }
  reverse(ALL(res));
  return res;
}

vector<LL> BASE{2,3,4,5,6,7,8,9,10};
VI table{0,1,2,3,4,5,6,7,8};
void solve(int N, int J){
  LL mn = (1LL << (N-1)) + 1;
  LL mx = 1LL << N;
  VL ans;
  VVL ans_xs;
  int cnt = 0;
  for(LL x=mn;x<mx&&cnt<J;x+=2){
	VL tmp;
	for(auto b: BASE){
	  LL y = to(x,b);
	  LL d = isprime(y);
	  if(!d) break;
	  tmp.PB(d);
	}
	if(SZ(tmp) == 9){
	  ++cnt;
	  ans.PB(x);
	  ans_xs.PB(tmp);
	}
  }

  REP(i,J){
	cout << tobin(ans[i]);
	for(auto idx: table)
	  cout << " " << ans_xs[i][idx];
	cout << endl;
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1){
	int N, J; cin >> N >> J;
	cout << "Case #" << t << ":" << endl;
	solve(N,J);
  }
  
  return 0;
}
