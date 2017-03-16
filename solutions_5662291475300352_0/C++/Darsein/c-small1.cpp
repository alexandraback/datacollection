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
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

const static int INF = 1e8;
const static D EPS = 1e-8;

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    ll n;
    cin >> n;
    vector<ll> d(n),h(n),m(n);
    rep(i,n)cin >> d[i] >> h[i] >> m[i];

    ll u1,d1,u2,d2;
    if(n==1){
      if(h[0]==1){
	cout << "Case #" << casenum << ": " << 0 << endl;
	continue;
      }

      u1 = m[0]; u2 = m[0]+1;
      d1 = d2 = d[0];
    }else{
      u1 = m[0]; u2 = m[1];
      d1 = d[0]; d2 = d[1];
      /*
      if(d1 < d2){
	swap(d1,d2); swap(u1,u2);
      }else if(d1 == d2 && u1 > u2){
	swap(d1,d2); swap(u1,u2);
      }
      */
      if(u1 > u2){
	swap(d1,d2); swap(u1,u2);
      }
    }

    int res = 0;
    //cout << u1*(720-d1) << " " << u2*(360-d2) << endl;
    if( u1*(720-d1) <= u2*(360-d2) )res = 1; 

    cout << "Case #" << casenum << ": " << res << endl;
  }
}
