#include <bits/stdc++.h>
#include <unistd.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
int f[1005];

int inDeg[1005];
bool dead[1005];

int run(int id){

  int cnt = 0;
  do {
    ++cnt;
    dead[id] = true;
    id = f[id];
  } while (!dead[id]);
  return cnt;
  
}

vector < int > E[1005];

int get(int id, int p){
  int r = 1;
  for (auto t : E[id]) if (t != p) r = max(r, 1+get(t, id));
  return r;
}

void Solve(){

  memset(inDeg, 0, sizeof inDeg);
  memset(dead, 0, sizeof dead);
  REP(i,1005) E[i].clear();
  
  cin >> n;
  REP(i,n) cin >> f[i];
  REP(i,n) --f[i];
  REP(i,n) E[f[i]].pb(i);

  REP(i,n) ++inDeg[f[i]];
  queue < int > Q;
  REP(i,n) if (inDeg[i] == 0) Q.push(i);
  while (!Q.empty()){
    int id = Q.front();
    Q.pop();
    dead[id] = true;
    if (--inDeg[f[id]] == 0) Q.push(f[id]);
  }

  int r2 = 0;
  vector < int > sz = {0};
  REP(i,n) if (!dead[i]){
    int bl = run(i);
    if (bl != 2){sz.pb(bl); continue;}
    r2 += get(i, f[i]) + get(f[i], i);
  }

  sort(sz.begin(), sz.end());
  int r1 = sz.back();
  cout << max(r1, r2) << endl;

}

int main(){
  ios_base::sync_with_stdio(false);
  srand(getpid() * (int)time(0));

  int t;
  cin >> t;
  REP(i,t) cout << "Case #" << i+1 << ": ", Solve();
  
  return 0;
}
