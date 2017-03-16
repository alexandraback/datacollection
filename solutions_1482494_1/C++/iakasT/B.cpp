#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <climits> 
#include <cfloat> 
#include <map> 
#include <utility> 
#include <set> 
#include <iostream> 
#include <memory> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <sstream> 
#include <complex> 
#include <stack> 
#include <queue> 
#include <cassert>
#include <fstream>
using namespace std; 
#define REP(i,b,n) for(int i=b;i<n;i++) 
#define rep(i,n)      REP(i,0,n) 
#define pb push_back  
#define mp make_pair 
#define ALL(C)   (C).begin(),(C).end() 
#define fe(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr != (c).end();itr++)
template<class T> void vp(T &a,int p){rep(i,p)cout << a[i]<<" ";cout << endl;}  
typedef complex<double>P; 
typedef long long ll; 
typedef unsigned long long ull; 
typedef pair<int,int> pii; 
const ll mod = 1000000009;
const int N = 1010;

int tans = 0;
int tused[2][N];
int memo[1<<21];
int search(int n,int cnt,int star,const vector<pair<int,int> > & in){
  int st = 0;
  rep(i,n){
    rep(j,2){
      if (tused[j][i])st++;
      st *= 2;
    }
  }
  //cout <<"check " << st << " " << star <<" " << cnt <<  " " << n << " " << memo[st] << endl;
  if (n == cnt)return 0;

  if (memo[st] != -1)return memo[st];
  int &ret = memo[st];
  ret = 3*n;
  rep(i,n){
    if (!tused[0][i] && in[i].first <= star){
      tused[0][i] = true;
      ret = min(ret,1+search(n,cnt,star+1,in));
      tused[0][i] = false;
    }
    if (!tused[1][i] && in[i].second <= star){
      int nextstar = 0;
      bool memo1 = tused[0][i];
      if (!tused[0][i])nextstar = star + 2;
      else nextstar = star + 1;
      tused[0][i] = tused[1][i] = true;
      ret = min(ret,1+search(n,cnt+1,nextstar,in));
      tused[1][i] = false;
      tused[0][i] = memo1;
    }
  }
  return ret;
}

int used[2][N];
int solve(int n,vector<pair<int,int> > & in){
  int ret = 0;
  rep(j,2)rep(i,n)used[j][i] = false;
  int cur = 0;
  while(true){
    rep(i,n){
      if (!used[1][i])goto end;
    }
    break;
  end:;
    bool isok = false;
    rep(i,n){
      if (!used[1][i] && in[i].second <= cur){
	if (!used[0][i])cur += 2;
	else cur++;
	ret++;
	used[0][i] = used[1][i] = true;
	isok = true;
      }
    }
    if (isok)continue;
    int maxi = 0;
    int mindex = -1;
    rep(i,n){
      if (!used[1][i] && !used[0][i] && in[i].first <= cur){
	if (mindex == -1){
	}else if (maxi > in[i].second){
	  continue;
	}
	mindex = i;
	maxi = in[i].second;
      }
    }
    if (mindex == -1)return -1;
    //cout <<"dore " << maxi <<" " << in[mindex].first << " " << in[mindex].second << endl;
    used[0][mindex] = true;
    cur++;
    ret++;
    
  }
  return ret;
}

main(){
  int te,tc=1;
  cin>>te;
  while(te--){
    int n;
    cin>>n;
    vector<pair<int,int> > in(n);
   rep(i,n)cin>>in[i].first>>in[i].second;

   /*
    rep(j,2)rep(i,n)tused[j][i] = false;
    rep(i,1<<(2*n+1))memo[i] = -1;
    int tans = search(n,0,0,in);
    if (tans == 3*n)tans = -1;
    //cout << tans << endl;
    */
   int ans = tans;
    int tmp = solve(n,in);
    //cout << ans <<" " << tmp << endl;
    //assert(ans == tmp);
    ans = tmp;
    if (ans == -1)cout <<"Case #" << tc++ << ": " <<"Too Bad" << endl;
    else cout <<"Case #" << tc++ << ": " <<ans << endl;
  }
  return 0;
}
