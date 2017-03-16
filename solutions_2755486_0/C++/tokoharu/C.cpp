#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
using namespace std;


typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++) 
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
#define ALL(c) (c).begin(),(c).end() 



const int MAX_N = 1<<21; //10ma-n
int haba , dat[2*MAX_N - 1] ;

//初期化
void init(int haba_) {
	haba = 1;
	while( haba<haba_ ) haba *= 2;
	
	for(int i=0; i<2*haba-1; i++) dat[i] = INT_MAX ;
}

//k(0-indexed)番目の値をaに変更する

void update(int k, int a) {
	
	k += haba-1;
	dat[k] = a;
	
	while(k>0) {
		k = (k - 1) /2;
		dat[k] = min( dat[k*2+1] , dat[k*2+2] ) ;
	}
}

//[a,b)の最小値を求める。////[a,b]ではないので注意
//外からは" int q =  query(a,b,0,0,haba); "として呼び出す

int query(int a, int b, int k, int l , int r) {
	
	//[a,b),[l,r)が交差していない
	if(r<=a || b<=l) return INT_MAX ;
	
	//[a,b)が[l,r)を完全に含む場合
	if(a<=l && r<=b) return dat[k];
	
	//それ以外
	
	int vl = query(a, b, k*2+1, l, (l+r)/2 ) ;
	int vr = query(a, b, k*2+2, (l+r)/2, r ) ;
	
	return min(vl,vr) ;
}

const int MAXN = 1000000;
vector<pair<int,PII> > data[MAXN]; // 日にち、強、左、右

int solve() {
  REP(i,MAXN) data[i].clear();
  int N;
  cin>>N;
  for(int i=0; i<N; i++) {
    int d,n,w,e,s,cd,ce,cs;
    cin>>d>>n>>w>>e>>s>>cd>>ce>>cs;
    
    for(int j=0; j<n; j++) {
      int day = d + j * cd;
      int west = w + ce*j;
      int east = e + ce*j;
      int str = s + cs * j;
      west += 2000;
      east += 2000;
      data[day].push_back(MP(str,MP(west,east)));
    }
  }
  //  init(10000);
  //sort(data.begin() , data.end());
 
  int ans  = 0;
  int block[10000];
  for(int i=0; i<10000; i++) block[i] = 0;
  for(int i=0; i<MAXN; i++) {
    for(int j=0; j<data[i].size(); j++) {
      int st = data[i][j].first;
      int west = data[i][j].second.first;
      int east = data[i][j].second.second;
      bool ok = false;
      for(int x=west; x<east; x++) {
	if(block[x]<st) ok = true;
      }
      if(ok) ans++;
      //      cout<<ok<<" "<<i<<" "<<st<<" "<<west<<" "<<east<<endl;
    }

    for(int j=0; j<data[i].size(); j++) {
      int st =data[i][j].first;
      int west = data[i][j].second.first;
      int east = data[i][j].second.second;
      
      for(int x=west; x<east; x++) {
	block[x] = max(block[x] , st);
      }
    }
    
  }
  
  
  
  return ans;
}

int main() {
  int t;
  cin>>t;
  for(int i=0; i<t; i++) {
    int ans = solve();
    cout<<"Case #"<<i+1<<": "<<ans<<endl;
    
  }
  
  return 0;
}
