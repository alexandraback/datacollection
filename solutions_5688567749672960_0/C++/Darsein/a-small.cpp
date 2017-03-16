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

const static int INF = 1e8;
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

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    ll n;
    cin >> n;

    vi dp(n+1,INF);
    dp[1] = 1;

    for(int i=1;i<=n;i++){
      if(i+1<=n)chmin(dp[i+1], dp[i]+1);
      string rev = toString(i);
      reverse(all(rev));
      ll l = toLL(rev);
      if(l<=n)chmin(dp[l],dp[i]+1);
    }
    cout << "Case #" << casenum << ": " << dp[n] << endl;
  }
}
