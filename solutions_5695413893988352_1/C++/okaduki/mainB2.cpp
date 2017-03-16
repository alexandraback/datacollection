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

string fix(string t, char c){
  REP(i,SZ(t)) if(t[i] == '?') t[i] = c;
  return t;
}

PLL solve(int i, string& s, string& t){
  if(i == SZ(s)){
	return PLL(stoll(s), stoll(t));
  }
  
  char p1 = s[i], p2 = t[i];
  PLL res(0,1e18+100);
  if(s[i] == '?'){
	if(t[i] == '?'){
	  s[i] = t[i] = '0';
	  res = solve(i+1, s, t);
	  
	  s[i] = '0'; t[i] = '1';
	  string s_ = fix(s, '9');
	  string t_ = fix(t, '0');
	  PLL tmp(stoll(s_), stoll(t_));
	  if(myless(tmp,res)) res = tmp;

	  s[i] = '1'; t[i] = '0';
	  s_ = fix(s, '0');
	  t_ = fix(t, '9');
	  tmp = PLL(stoll(s_), stoll(t_));
	  if(myless(tmp,res)) res = tmp;
	}
	else{
	  s[i] = t[i];
	  res = solve(i+1, s, t);
	  
	  if(t[i] != '0'){
		s[i] = t[i] - 1;
		string s_ = fix(s, '9');
		string t_ = fix(t, '0');
		PLL tmp(stoll(s_), stoll(t_));
		if(myless(tmp,res)) res = tmp;
	  }
	  if(t[i] != '9'){
		s[i] = t[i] + 1;
		string s_ = fix(s, '0');
		string t_ = fix(t, '9');
		PLL tmp = PLL(stoll(s_), stoll(t_));
		if(myless(tmp,res)) res = tmp;
	  }	  
	}
  }
  else{
	if(t[i] == '?'){
	  t[i] = s[i];
	  res = solve(i+1, s, t);
	  
	  if(s[i] != '0'){
		t[i] = s[i] - 1;
		string s_ = fix(s, '0');
		string t_ = fix(t, '9');
		PLL tmp(stoll(s_), stoll(t_));
		if(myless(tmp,res)) res = tmp;
	  }
	  if(s[i] != '9'){
		t[i] = s[i] + 1;
		string s_ = fix(s, '9');
		string t_ = fix(t, '0');
		PLL tmp = PLL(stoll(s_), stoll(t_));
		if(myless(tmp,res)) res = tmp;
	  }	  
	}
	else{
	  if(s[i] == t[i])
		res = solve(i+1, s, t);
	  else if(s[i] < t[i]){
		string s_ = fix(s, '9');
		string t_ = fix(t, '0');
		res = PLL(stoll(s_), stoll(t_));
	  }
	  else{
		string s_ = fix(s, '0');
		string t_ = fix(t, '9');
		res = PLL(stoll(s_), stoll(t_));
	  }
	}
  }

  s[i] = p1, t[i] = p2;
  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(ttt,1,T+1){
	string s, t;
	cin >> s >> t;
	PLL ans = solve(0,s,t);
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
