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

string toString(int a, int len){
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

    int dif = 10000;
    int c=-1,j=-1, lim=1;
    rep(i,len) lim*=10;

    rep(cc,lim){
      string sc = toString(cc,len);
      bool fc = true;
      rep(i,len){
	if(a[i] != '?' && a[i] != sc[i]) fc = false;
      }
      if(!fc) continue;

      rep(jj,lim){
	string sj = toString(jj,len);
	bool fj = true;
	rep(i,len){
	  if(b[i] != '?' && b[i] != sj[i]) fj = false;
	}
	if(!fj) continue;

	if(dif > abs(cc-jj)){
	  dif = abs(cc-jj);
	  c = cc; j = jj;
	}
      }
    }

    cout << "Case #" << casenum << ": ";
    cout << toString(c,len) << " " << toString(j,len) << endl;
  }
}
