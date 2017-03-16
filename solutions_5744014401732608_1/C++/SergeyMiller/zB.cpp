#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <set>
#include <cassert>
#include <ctime>
#define MOD (int)1073741824
#define eps 1e-12
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define sz(a) a.size()
#define loop(i, n) for(int (i) = 0; (i) < (n) ; ++ (i))
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>  
typedef long long ll;
typedef long double ld;

using namespace std;

/*@Sergey_Miller*/
vector <vector <ll> > d;
vector <ll> dp;
vector <bool> ch;
ll n,m;

ll get(int v) {
  if(ch[v]) {
    return dp[v];
  }

  ch[v] = 1;
  ll sum = 0;
  loop(i,n) {
    if(d[i][v]) {
      sum += get(i);
    }
  }
  return sum;
}

vector <ll> divv(ll dt) {
  vector <ll> ans;
  while(dt) {
    ans.pb(dt%2);
    dt/=2;
  }
  return ans;
}

void solve() {
  cin >> n >> m;

  if(m > powl(2,n - 2)) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  d.resize(n,vector <ll> (n,0));
  int l = 0;
  int r = n-1;
  // cout <<"OK" << endl;
  while(l < r) {
    for(int i = l; i < r; ++i) {
      d[i][r] = 1;
      d[l][i+1] = 1;
    }
    ++l;
    --r;
  }
 // cout <<"OK" << endl;
  dp.resize(n,0);
  dp[0] = 1;
  ch.resize(n,0);
  ch[0] = 1;
  get(n-1);
  ll delta = powl(2,n-2) - m;
  // cout << delta << endl;
  // cout << powl(2,n-2) << " " << m << endl;
  vector <ll> pr = divv(delta);
  // cout <<"OK" << endl;
  loop(i,sz(pr)) {
    if(!pr[i]) {
      continue;
    }
    int st = i+1;
    // cout << st <<" " <<  n-1 << endl;
    d[st][n-1] = 0;
  }
  // cout <<"OK" << endl;
  cout << "POSSIBLE" << endl;
  loop(i,n) {
    loop(j,n) {
      cout << d[i][j];
    }
    cout << endl;
  } 
  d.clear();
  dp.clear();
  ch.clear();
}


int main () {
    ios::sync_with_stdio(false);
    // srand(time(NULL));
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    loop(i,n) {
      cout << "Case #" << i + 1 << ": ";
    solve();
    }
}