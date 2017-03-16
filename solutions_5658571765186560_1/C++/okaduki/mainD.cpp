//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>
 
using namespace std;
 
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef set<PII> SP;
 
//container util
//------------------------------------------
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
set<SP> vs[7];

void print(const SP& spii){
  for(auto& pii: spii)
    cout << pii.first << "," << pii.second << endl;
  cout << endl;
}

void f(SP& ps){
  SP tmp = ps;
  PII sp = *ps.begin(); 
  for(auto& p: ps)
    sp = min(sp, p);

  ps.clear();
  for(auto& p: tmp){
    PII p_ = p;
    p_.first -= sp.first;
    p_.second -= sp.second;
    ps.insert(p_);
  }
}

void rev(SP& ps, const SP& orig){
  ps.clear();
  for(auto& pii: orig){
    PII p;
    p.first = -pii.first;
    p.second = pii.second;
    ps.insert(p);
  }
  f(ps);
}

void rot(set<SP>& ps, const SP& orig){
  SP s;
  for(auto& pii: orig){
    PII p;
    p.first = -pii.second;
    p.second = pii.first;
    s.insert(p);
  }
  f(s);
  ps.insert(s);

  s.clear();
  for(auto& pii: orig){
    PII p;
    p.first = -pii.first;
    p.second = -pii.second;
    s.insert(p);
  }
  f(s);
  ps.insert(s);

  s.clear();
  for(auto& pii: orig){
    PII p;
    p.first = pii.second;
    p.second = -pii.first;
    s.insert(p);
  }
  f(s);
  ps.insert(s);
}

void init(){
  SP buf;
  buf.insert(MP(0,0));
  vs[1].insert(buf);
  for(int j=2;j<7;++j){
    for(auto& spii: vs[j-1]){
      for(auto& pii: spii){
	for(int i=0;i<4;++i){
	  PII nxt = pii;
	  nxt.first += dx[i], nxt.second += dy[i];
	  if(spii.count(nxt)) continue;

	  SP tmp = spii;
	  tmp.insert(nxt);
	  f(tmp);
	  vs[j].insert(tmp);
	}
      }
    }

    set<SP> buf;
    for(auto& spii: vs[j]){
      if(buf.count(spii)) continue;
      SP tmp;
      set<SP> rm;
      rev(tmp, spii);
      buf.insert(tmp);
      rot(buf, tmp);
      rot(buf, spii);
      buf.erase(spii);
    }
    for(auto& spii: buf)
      vs[j].erase(spii);
  }
}

bool cnt(int X, int R, int C, vector<vector<bool>>& m){
  for(int y=0;y<R;++y){
    for(int x=0;x<C;++x){
      if(m[y][x]) continue;
      queue<PII> q;
      q.push(MP(x,y));
      m[y][x] = true;
      int c = 1;
      while(!q.empty()){
	PII p = q.front(); q.pop();
	for(int i=0;i<4;++i){
	  PII nxt = p;
	  nxt.first += dx[i], nxt.second += dy[i];
	  if(nxt.first < 0 || C <= nxt.first
	     || nxt.second < 0 || R <= nxt.second
	     || m[nxt.second][nxt.first]) continue;
	  m[nxt.second][nxt.first] = true;
	  q.push(nxt);
	  ++c;
	}
      }
      if(c % X != 0) return false;
    }
  }

  return true;
}

bool check(int X, int R, int C){
  for(auto& spii_: vs[X]){
    set<SP> tiles;
    SP tmp;
    rev(tmp, spii_);
    tiles.insert(tmp);
    tiles.insert(spii_);
    rot(tiles, spii_);
    rot(tiles, tmp);
    bool ok = false;
    for(auto& spii: tiles){
      for(int y=-X;y<R+X;++y){
	for(int x=-X;x<C+X;++x){
	  vector<vector<bool>> used(R, vector<bool>(C, false));
	  bool fit = true;
	  for(auto& pii: spii){
	    int tx = x + pii.first, ty = y + pii.second;
	    if(tx < 0 || C <= tx || ty < 0 || R <= ty){
	      fit = false; break;
	    }
	    used[ty][tx] = true;
	  }
	  if(!fit) continue;
	  if(cnt(X, R, C, used)){
	    ok = true;
	    x = y = 1000;
	  }
	}
      }
      if(ok) break;
    }
    if(!ok) return false;
  }
	  
  return true;
}

int main(){
  int T; cin >> T;
  init();

  for(auto& spii: vs[3]){
  }
  FOR(t,1,T+1){
    int X, R, C; cin >> X >> R >> C;
    bool ok = (X >= 7? false: check(X,R,C));

    cout << "Case #" << t << ": " << (ok? "GABRIEL": "RICHARD") << endl;
  }
  
  return 0;
}
