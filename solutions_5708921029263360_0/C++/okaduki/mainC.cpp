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

LL X, Y, Z, K;
map<PII,int> xy, yz, xz;
int dfs(int x,int y,int z, vector<tuple<int,int,int>>& ans){
  if(z == Z+1) return dfs(x,y+1,1,ans);
  if(y == Y+1) return dfs(x+1,1,1,ans);
  if(x == X+1) return 0;

  auto prv = ans;
  int res = dfs(x,y,z+1,ans);
  if(xy[MP(x,y)] < K && yz[MP(y,z)] < K && xz[MP(x,z)] < K){
	xy[MP(x,y)]++;
	yz[MP(y,z)]++;
	xz[MP(x,z)]++;
	int res_ = dfs(x,y,z+1,prv)+1;
	if(res < res_){
	  res = res_;
	  ans = prv;
	  ans.EB(x,y,z);
	}
	xy[MP(x,y)]--;
	yz[MP(y,z)]--;
	xz[MP(x,z)]--;
  }
  return res;
}



int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(ttt,1,T+1){
	cin >> X >> Y >> Z >> K;
	/*
	map<PII,int> xy, yz, xz;
	vector<tuple<int,int,int>> ans;
	FOR(x,1,X+1){
	  FOR(y,1,Y+1){
		FOR(z,1,Z+1){
		  if(xy[MP(x,y)] < K && yz[MP(y,z)] < K && xz[MP(x,z)] < K){
			xy[MP(x,y)]++;
			yz[MP(y,z)]++;
			xz[MP(x,z)]++;
			ans.EB(x,y,z);
		  }
		}
	  }
	}
	*/
	vector<tuple<int,int,int>> ans;	
	if(K >= 3){
	  FOR(x,1,X+1){
		FOR(y,1,Y+1){
		  FOR(z,1,Z+1){
			  ans.EB(x,y,z);
		  }
		}
	  }
	}
	else dfs(1,1,1,ans);
	cout << "Case #" << ttt << ": " << SZ(ans) << endl;
	for(auto& t: ans){
	  int x, y, z;
	  tie(x,y,z) = t;
	  cout << x << " " << y << " " << z << endl;
	}
  }
  
  return 0;
}
