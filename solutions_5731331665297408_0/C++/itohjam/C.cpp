#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#include <complex>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
using namespace std;

typedef long long ll;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
bool ISINT(double x){return fabs(x-(int)round(x))<EPS;}
bool ISEQ(double x,double y){return fabs(x-y)<EPS;}
string itos(ll x){stringstream ss;ss<<x;return ss.str();}
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin();itr!=c.end();itr++)

int n, m;
string ZIP[52];
vector<int> t[52];
bool used[52];
int perm[52], idx, cnt;

bool dfs(int id){
  used[id] = true;

  for(int i = 0; i < t[id].size(); i++){
    int to = t[id][i];

    if(used[to]) continue;
    if(perm[idx] != to) continue;

    idx++;
    cnt++;
    if(cnt == n) return true;

    if(dfs(to)) return true;
  }

  return false;
}

void solve(){
  for(int i = 0; i < n; i++){
    perm[i] = i;
  }

  string ans = "";
  ans += (char)('9' + 1);

  do{
    string cat = "";
    for(int i = 0; i < n; i++){
      cat += ZIP[perm[i]];
    }
    if(cat >= ans){
      continue;
    }

    memset(used, 0, sizeof(used));
    idx = cnt = 1;

    if(dfs(perm[0])){
      ans = min(ans, cat);
    }
  }while(next_permutation(perm, perm + n));

  cout << ans << endl;
}

int main(void){
  int T;
  cin >> T;

  for(int CASE = 1; CASE <= T; CASE++){
    cout << "Case #" << CASE << ": ";

    cin >> n >> m;

    for(int i = 0; i < n; i++){
      cin >> ZIP[i];
      t[i].clear();
    }
    for(int i = 0; i < m; i++){
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      t[a].push_back(b);
      t[b].push_back(a);
    }

    if(n == 1){
      cout << ZIP[0] << endl;
      continue;
    }

    solve();
  }
}
