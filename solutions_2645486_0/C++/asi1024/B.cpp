#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>

#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define sz          size()
#define pb          push_back
#define mp          make_pair
#define ALL(X)      (X).begin(),(X).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void output(int c,long long n){
  cout<<"Case #"<<c<<": "<<n<<endl;
}

int v[16384];
int rem[16384];
int ned[16384];
int use[16384];

int main(void)
{
  int t;
  cin>>t;
  FOR(c,1,t+1){
    int e,r,n;
    cin>>e>>r>>n;
    REP(i,n){
      cin>>v[i];
    }
    vector<pair<int,int> > w;
    REP(i,n) w.pb(mp(v[i],i));
    sort(w.rbegin(),w.rend());
    REP(i,n){
      rem[i]=e;
      ned[i]=0;
      use[i]=0;
    }
    REP(i,w.sz){
      int it=w[i].second;
      use[it]=rem[it]-ned[it];
      REP(j,w.sz){
	rem[j]=(j==0)?e:min(rem[j-1]-use[j-1]+r,e);
      }
      for(int j=n-1;j>=0;j--){
	ned[j]=(j==n-1)?0:max(ned[j+1]+use[j+1]-r,0);
      }
    }
    long long res=0;
    REP(i,n) res+=(long long)v[i]*use[i];
    output(c,res);
  }
  return 0;
}
