#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(a) (a).begin(),(a).end()
#define INIT(a) memset((a),0,sizeof(a))
#define chmin(a,b) ((a) = min((a),(b)))
#define chmax(a,b) ((a) = max((a),(b)))
#define fs first
#define sc second
#define pb push_back
#define sz size() 
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

const static ll INF = 1e18;
const static D EPS = 1e-8;

ll toLL(string s){
  stringstream ss(s);
  ll res;
  ss >> res;
  return res;
}

string toString(ll x){
  stringstream ss;
  ss << x;
  return ss.str();
}

ll calc(string s){
  s[0]--;
  ll res = toLL(s);
  s[0]++;

  rep(i,s.size()){
    string pre = s.substr(0,i+1), suf = s.substr(i+1);
    ll steps = 1;
    if( toLL(suf) == 0 ){
      pre = toString( toLL(pre)-1 );
      steps += toLL("1" + suf) - 1;
    }else{
      steps += toLL(suf) - 1;
    }
    reverse(all(pre));
    steps += toLL(pre);

    res = min(res, steps);
  }
  //cout << res << endl;
  return res;
}

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    string s;
    cin >> s;

    if(s.size()<=2){
      ll n = toLL(s);
      vector<ll> dp(n+1,INF);
      dp[1] = 1;
      
      for(int i=1;i<=n;i++){
	if(i+1<=n)chmin(dp[i+1], dp[i]+1);
	string rev = toString(i);
	reverse(all(rev));
	ll l = toLL(rev);
	if(l<=n)chmin(dp[l],dp[i]+1);
      }
      cout << "Case #" << casenum << ": " << dp[n] << endl;
    }else{
      ll cur = 10, ans = 10;
      while( toString(cur).size() != s.size() ){
	cur *= 10;
	ans += calc( toString(cur-1) ) + 1;
      }
      ans += calc(s);

      cout << "Case #" << casenum << ": " << ans << endl;      
    }
    
  }
}
