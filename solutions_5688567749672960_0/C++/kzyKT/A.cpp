#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
#define pb(a) push_back(a)
#define pr(a) cout<<(a)<<endl
#define PR(a,b) cout<<(a)<<" "<<(b)<<endl
#define R cin>>
#define F first
#define S second
#define ll long long
bool check(int n,int m,int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<60,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;

int d[10000001];

int main() {
  int T;
  R T;
  REP(tt,1,T+1) {
    int s;
    R s;
    ll ans=0;
    fill(d,d+10000001,MAX);
    d[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty()) {
      int x=que.front();que.pop();
      if(x==s) break;
      {
	int y=x+1;
	if(d[y]==MAX) {
	  d[y]=d[x]+1;
	  que.push(y);
	}
      }
      {
	int y=0,z=x;
	while(z) {
	  y*=10;
	  y+=z%10;
	  z/=10;
	}
	if(d[y]==MAX) {
	  d[y]=d[x]+1;
	  que.push(y);
	}
      }
    }
    cout << "Case #" << tt << ": " << d[s] << endl;
  }
  return 0;
}

/*
  456
   19
   91
  109 199
  901 991
 1009
 9001
 9019
 
  104
  401
  456
  
  
 */
