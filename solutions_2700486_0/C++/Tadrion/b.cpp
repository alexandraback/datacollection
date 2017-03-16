//Tadrion
#include <cstdio>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define CLEAR(x) (memset(x,0,sizeof(x)))
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define VAR(v, n) __typeof(n) v = (n)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOREACH(i, c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define DBG(v) cout<<#v<<" = "<<v<<endl; 
#define IN(x,y) ((y).find(x)!=(y).end())
#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

vector< pair<set<PII>,double> > dd[30],kkk; 

vector< pair< set<PII> , double > > sim(int x, int y, set<PII> v, double mnoz) {
  //printf("%d %d %f\n",x,y,mnoz);
  if(y == 0) {
    set<PII> res(v);
    res.insert(PII(x,y));
    vector< pair < set<PII>,double > > vv;
    vv.PB(MP(res,mnoz));
    return vv;
  }

  if(IN(PII(x,y-2),v) ) {
    if(IN(PII(x-1,y-1),v) && IN(PII(x+1,y-1),v) ) {
      set<PII> res(v);
      res.insert(PII(x,y));
      vector< pair < set<PII>,double > > vv;
      vv.PB(MP(res,mnoz));
      return vv;
    }
    else if(IN(PII(x-1,y-1),v) && !IN(PII(x+1,y-1),v) ) {
      return sim(x+1,y-1,v,mnoz);
    } 
    else if(!IN(PII(x-1,y-1),v) && IN(PII(x+1,y-1),v) ) {
      return sim(x-1,y-1,v,mnoz);
    }
    else {
      vector< pair < set<PII>, double > > vv0,vv1;
      set<PII> res0(v);
      vv0 = sim(x-1,y-1,v,0.5*mnoz);
      set<PII> res1(v);
      vv1 = sim(x+1,y-1,v,0.5*mnoz);
      REP(i,SZ(vv1)) {
	vv0.PB(vv1[i]);
      }
      return vv0;
    }
  }
  else {
    if(IN(PII(x-1,y-1),v) && IN(PII(x+1,y-1),v) ) {
      set<PII> res(v);
      res.insert(PII(x,y));
      vector< pair < set<PII>,double > > vv;
      vv.PB(MP(res,mnoz));
      return vv;
    }
    else if(IN(PII(x-1,y-1),v) && !IN(PII(x+1,y-1),v) ) {
      return sim(x+1,y-1,v,mnoz);
    } 
    else if(!IN(PII(x-1,y-1),v) && IN(PII(x+1,y-1),v) ) {
      return sim(x-1,y-1,v,mnoz);
    }
    else {
      return sim(x,y-1,v,mnoz);
      // vector< pair < set<PII>, double > > vv0,vv1;
      // set<PII> res0(v);
      // vv0 = sim(x-1,y-1,v,0.5*mnoz);
      // set<PII> res1(v);
      // vv1 = sim(x+1,y-1,v,0.5*mnoz);
      // REP(i,SZ(vv1)) {
      // 	vv0.PB(vv1[i]);
      // }
      // return vv0;
    }
  }
}

int T;
int X,Y;
int main() {
  set<PII> ss;
  dd[0].PB(MP(ss,1.0));

  FOR(i,1,21) {
    REP(j,SZ(dd[i-1])) {
      kkk = sim(0,20,dd[i-1][j].ST,dd[i-1][j].ND);
      REP(k,SZ(kkk)) {
	dd[i].PB(kkk[k]);
      }
    }
  }
  
  cin >> T;
  FOR(ttt,1,T) {
    int X,Y,N;
    cin >> N >> X >> Y;
    double prob = 0.0;
    REP(i,SZ(dd[N]) ) {
      if(IN(MP(X,Y),dd[N][i].ST)) prob+=dd[N][i].ND;
    }
    printf("Case #%d: %.8f\n",ttt,prob);
    
  }


  return 0;
}
