#include <bits/stdc++.h>

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
int h[105][105];

int mat[105][105];
bool taken[105];
bool tdir[2][105];

bool rek(){

  int cnt = 0;
  REP(i,2*n-1) cnt += taken[i];
  if (cnt == 2*n-1) return true;

  vector < pii > ran;

  REP(a,2) REP(b,n){
    if (tdir[a][b]) continue;
    vector < int > seq(n);
    if (a == 0) REP(i,n) seq[i] = mat[b][i];
    else REP(i,n) seq[i] = mat[i][b];
    vector < int > poss;
    REP(i,2*n-1){
      if (taken[i]) continue;
      bool ch = true;
      REP(j,n) if (seq[j] != -1 && seq[j] != h[i][j]) ch = false;
      if (ch) poss.pb(i);
    }
    if (poss.size() == 2) ran.pb({a, b});
    if (poss.size() != 1) continue;
    int id = poss.back(); //TRACE(a _ b _ id);
    taken[id] = true;
    tdir[a][b] = true;
    if (a == 0) REP(i,n) mat[b][i] = h[id][i];
    else REP(i,n) mat[i][b] = h[id][i];
    if (rek()) return true;
    if (a == 0) REP(i,n) mat[b][i] = seq[i];
    else REP(i,n) mat[i][b] = seq[i];
    taken[id] = false;
    tdir[a][b] = false;
    return false;
  }

  if (ran.empty()) return false;
  int idd = rand()%(int)ran.size();
  int a = ran[idd].x, b = ran[idd].y;

  vector < int > seq(n);
  if (a == 0) REP(i,n) seq[i] = mat[b][i];
  else REP(i,n) seq[i] = mat[i][b];
  vector < int > poss;
  REP(i,2*n-1){
    if (taken[i]) continue;
    bool ch = true;
    REP(j,n) if (seq[j] != -1 && seq[j] != h[i][j]) ch = false;
    if (ch) poss.pb(i);
  }
  for (auto id : poss){
    taken[id] = true;
    tdir[a][b] = true;
    if (a == 0) REP(i,n) mat[b][i] = h[id][i];
    else REP(i,n) mat[i][b] = h[id][i];
    if (rek()) return true;
    if (a == 0) REP(i,n) mat[b][i] = seq[i];
    else REP(i,n) mat[i][b] = seq[i];
    taken[id] = false;
    tdir[a][b] = false;
  } return false;
  
}

void Solve(){

  memset(mat, -1, sizeof mat);
  memset(taken, 0, sizeof taken);
  memset(tdir, 0, sizeof tdir);
  
  cin >> n;
  REP(i,2*n-1) REP(j,n) cin >> h[i][j];

  int id = 0;
  REP(i,2*n-1) if (vector<int>(h[i], h[i]+n) < vector<int>(h[id], h[id]+n)) id = i;
  taken[id] = true;
  tdir[0][0] = true;
  REP(i,n) mat[0][i] = h[id][i];

  bool bla = false;
  REP(a,2) REP(b,n){
    if (a == 0 && b == 0) continue;
    if (bla) break;
    tdir[a][b] = true;
    if (rek()){bla = true; tdir[a][b] = false; break;}
    tdir[a][b] = false;
  } assert(bla);

  REP(a,2) REP(b,n) if (!tdir[a][b]){
    if (a == 0) REP(i,n) cout << mat[b][i] << " ";
    else REP(i,n) cout << mat[i][b] << " ";
    cout << endl;
    return;
  } assert(false);

}

int main(){
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  REP(i,t) cout << "Case #" << i+1 << ": ", Solve();
  
  return 0;
}
