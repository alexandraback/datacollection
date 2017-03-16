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

const int table[4][4] = { {1, 2, 3, 4},
			  {2, -1, 4, -3},
			  {3, -4, -1, 2},
			  {4,  3, -2, -1} };

inline int calc(int a, int b){
  int sign = a*b;
  return (sign<0?-1:1) * table[abs(a)-1][abs(b)-1];
}

inline int rev(int a, int b){
  rep(i,4){
    if(abs(table[abs(a)-1][i]) == abs(b)){
      int sign = a*b*table[abs(a)-1][i];
      return (sign<0?-1:1) * (i+1);
    }
  }
  return 0;
}

int main(){
  cin.tie(0); ios::sync_with_stdio(0);
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    int l,x;
    cin >> l >> x;
    string s,tmp;
    cin >> tmp;
    rep(i,x)s += tmp;
    l *= x;

    vector<int> val(l+1);
    val[0] = 1;
    rep(i,l){
      val[i+1] = calc(val[i],s[i]-'i'+2);
    }

    bool f = false;
    for(int i=1;i<=l;i++){
      int I = val[i];
      if(I!=2)continue;
      for(int j=i+1;j<=l;j++){
	int J = rev(val[i],val[j]);
	int K = rev(val[j],val[l]);
	if(J==3 && K==4){
	  f = true;
	  break;
	}
      }
      if(f)break;
    }

    cout << "Case #" << casenum << ": " << (f?"YES":"NO") << endl;
  }
}
