#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(a) (a).begin(),(a).end()
#define INIT(a) memset((a),0,sizeof(a))
#define fs first
#define sc second
#define pb push_back
#define sz size() 
using namespace std;
typedef unsigned long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

const ll INF = 1e18;

vector<ll> solve(string a, string b){
  int len = a.sz;

  vector< vector< vector<ll> > > dp(len+1, vector< vector<ll> >(2, vector<ll>(3,INF)));
  dp[0][0] = vector<ll>(3,0);

  rep(i,len){
    rep(x,10){
      if(a[i] != '?' && a[i] != ('0'+x)) continue;
      rep(y,10){
	if(b[i] != '?' && b[i] != ('0'+y)) continue;
	vector<ll> tmp0 = dp[i][0], tmp1 = dp[i][1];
	tmp0[1] = tmp0[1]*10 + x; tmp0[2] = tmp0[2]*10 + y;
	tmp1[1] = tmp1[1]*10 + x; tmp1[2] = tmp1[2]*10 + y;
	if(x==y){
	  dp[i+1][0] = min(dp[i+1][0], tmp0);
	}else if(x < y){
	  tmp0[0] = tmp0[0]*10 + (y-x);
	  dp[i+1][1] = min(dp[i+1][1], tmp0);
	}
	tmp1[0] = tmp1[0]*10 + (y-x);
	dp[i+1][1] = min(dp[i+1][1], tmp1);
      }
    }
  }
  return min(dp[len][0], dp[len][1]);
}

string toString(ll a, int len){
  string res;
  rep(i,len){
    res += (char)('0'+a%10);
    a/=10;
  }
  reverse(all(res));
  return res;
}

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    string a,b;
    cin >> a >> b;
    int len = a.sz;

    vector<ll> res = solve(a,b);
    vector<ll> tmp = solve(b,a);
    if(res > tmp) res = tmp, swap(res[1], res[2]);

    cout << "Case #" << casenum << ": ";
    cout << toString(res[1],len) << " " << toString(res[2],len) << endl;
  }
}
