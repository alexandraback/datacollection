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

char rev(char c){
  return (c=='+'? '-': '+');
}

void flip(string& s, int e){
  string tmp = s;
  REP(i,e+1)
	tmp[i] = rev(s[e-i]);
  s = tmp;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int T; cin >> T;
  FOR(t,1,T+1){
	string S; cin >> S;
	int N = SZ(S);
	int ans = 0;
	while(count(ALL(S),'+') < N){
	  int e;
	  for(e=N-1;e>=0;--e)
		if(S[e] == '-') break;
	  int b;
	  for(b=0;b<N;++b)
		if(S[b] == '-') break;
	  if(b > 0){
		++ans;
		flip(S, b-1);
	  }
	  ++ans;
	  flip(S, e);
	}
	cout << "Case #" << t << ": " << ans << endl;
  }
  
  return 0;
}
