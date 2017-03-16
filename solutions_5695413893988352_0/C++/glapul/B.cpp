
//Michał Glapa
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
//Make sure no overflow problems
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define ld long double
#define mini(x,y) x=min(x,y)
#define maxi(x,y) x=max(x,y)
#define CLR(a,x) memset(a,x,sizeof(a))
#define SIZE(x) ((int)x.size())
const int INF = 2000000009;
const long long INFLL = (ll)INF * (ll)INF;
const ld EPS = 10e-9;
typedef vector<int> vi;
typedef pair<int,int> pii;

///////////////////////////////////////////////////////////////
//
//
vector<int> _best = {INFLL, INFLL, INFLL};
vector<int> func(string a, string b, int fdp, bool swapres, string& ares, string &bres) {
  REP(i, fdp) {
    if(a[i] == '?' && b[i] == '?') {
      a[i] = '0';
      b[i] = '0';
      continue;
    }
    if (a[i] == '?' || b[i] =='?') {
      if (a[i] == '?')
        a[i] = b[i];
      else
        b[i] = a[i];
      continue;
    }
    if (a[i] != b[i])
      return _best;
  }

  if (fdp < a.size()) {

  REP(_, 1) {
    if(a[fdp] == '?' && b[fdp] == '?') {
        a[fdp] = '1', b[fdp] = '0';
      continue;
    }
    if (a[fdp] == '?' || b[fdp] == '?') {
      if (a[fdp] == '?') {
        if (b[fdp] == '9') {
          return _best;
        } else {
          a[fdp] = b[fdp] + 1;
        }
      } else {
        if (a[fdp] == '0')
          return _best;
        else
          b[fdp] = a[fdp] - 1;
      }
      continue;
    }
    if (a[fdp] <= b[fdp])
      return _best;
  }
  }
  FOR(i, fdp + 1, (int)a.size() - 1) {
    if (a[i] == '?')
      a[i] = '0';
    if (b[i] == '?')
      b[i] = '9';
  }
  if(swapres) {
    swap(a, b);
  }
  ares = a;
  bres = b;
  a.push_back(0);
  b.push_back(0);
  int aval, bval;
  sscanf(a.c_str(), "%lld", &aval);
  sscanf(b.c_str(), "%lld", &bval);
  vector<int> res {abs(aval-bval), aval, bval};
  return res;


}
void solve() {
  string a, b;
  cin >> a >> b;
  vector<int> best = {INFLL, INFLL, INFLL};
  string ares, bres;
  string s[2] = {a, b};

  REP(fdp, (int)a.size() + 1) {
    REP(bhigher, 2) {
      string atmp, btmp;
      auto tmp = func(s[bhigher], s[1-bhigher], fdp, bhigher, atmp, btmp);
      if (tmp < best) {
        best = tmp;
        ares = atmp;
        bres = btmp;
      }
    }
  }
  cout << ares << " " << bres << endl;


}
#undef int
int main()
#define int long long
{
  int z;
  cin >> z;
  FOR(i,1, z) {
    cout <<"Case #" <<i << ": ";
    solve();
  }

}
