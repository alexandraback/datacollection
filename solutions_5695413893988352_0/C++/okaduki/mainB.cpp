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

bool myless(PII p1, PII p2){
  if(abs(p1.FF-p1.SS) < abs(p2.FF-p2.SS)) return true;
  if(abs(p1.FF-p1.SS) > abs(p2.FF-p2.SS)) return false;
  return p1 < p2;
}

PII dfs(int i, string& s, string& t){
  if(i == SZ(s) + SZ(t)){
	return PII(stoi(s),stoi(t));
  }
  PII res(0,1e9);
  if(i < SZ(s)){
	if(s[i] != '?') return dfs(i+1, s, t);
	FOR(d,0,10){
	  s[i] = '0' + d;
	  PII tmp = dfs(i+1, s, t);
	  if(myless(tmp,res)) res = tmp;
	}
	s[i] = '?';
  }
  else{
	i -= SZ(s);
	if(t[i] != '?') return dfs(SZ(s)+i+1, s, t);
	FOR(d,0,10){
	  t[i] = '0' + d;
	  PII tmp = dfs(SZ(s)+i+1, s, t);
	  if(myless(tmp,res)) res = tmp;
	}
	t[i] = '?';
  }

  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(ttt,1,T+1){
	string s, t;
	cin >> s >> t;
	PII ans = dfs(0,s,t);
	for(int i=SZ(s)-1;i>=0;--i){
	  s[i] = ans.FF % 10 + '0';
	  ans.FF /= 10;
	}
	for(int i=SZ(t)-1;i>=0;--i){
	  t[i] = ans.SS % 10 + '0';
	  ans.SS /= 10;
	}
	cout << "Case #" << ttt << ": " << s << " " << t << endl;
  }
  
  return 0;
}
