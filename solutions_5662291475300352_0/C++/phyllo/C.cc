#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

struct ST {
  int d;
  int m;
};
bool operator<(const ST& a, const ST& b){
  if(a.d == b.d) return a.m > b.m;
  return a.d < b.d;
}

int N;
int D[100];
int H[100];
int M[100];

int solve(){
  int num = 0;
  rep(i,N) num += H[i];
  if(num <= 1) return 0;
  vector<ST> st;
  rep(i,N){
    rep(j,H[i]){
      st.push_back((ST){D[i],M[i]+j});
    }
  }
  
  sort(ALLOF(st));

  double PI = acos(-1);
  
  if(st[0].m == st[1].m) return 0;
  double v1 = PI/st[0].m;
  double v2 = PI/st[1].m;
  
  {
    double t1 = PI * (360-st[0].d)/360.0 * v1;
    double t2 = (PI + PI * (360-st[1].d)/360.0) * v2;
    //cout << "1:" << t1 << " " << t2 << endl;
    if(t1 < t2) return 0;
  }
  {
    double t1 = (PI + PI * (360-st[0].d)/360.0) * v1;
    double t2 = (PI * (360-st[1].d)/360.0) * v2;
    //cout << "2:" << t1 << " " << t2 << endl;
    if(t2 < t1) return 0;
  }
  return 1;
}

int main(){
  int T;

  cin >> T;
  rep(t,T){
    cin >> N;
    rep(i,N){
      cin >> D[i] >> H[i] >> M[i];
    }
    cout << "Case #" << t+1 << ": " << solve() << endl;
  }
  
  return 0;
}
