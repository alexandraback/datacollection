#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define D(x) cout << #x << " = " << x << endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=b-1;i>=a;i--)
#define REP(i,n) rep(i,0,n)
#define REPD(i,n) repd(i,0,n)
#define pb push_back
#define mp make_pair

typedef long long int lld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

lld solve(int e, int r, int n, vpii &v){
  sort(v.begin(),v.end(),greater<pii>());

  map<int,pii> m;
  map<int,pii> :: iterator it;
  m[0] = mp(0,e);
  m[n+1] = mp(0,0);

  //D(n+1);

  lld ans = 0;
  REP(i,n){
    int c = v[i].first;
    int index = v[i].second;

    it = m.upper_bound(index); it--;
    int a = (*it).first;
    int b = (*m.upper_bound(index)).first;

    int el = m[a].second;
    int er = m[b].first;

    int da = index - a;
    int db = b - index;

    int ini = min(e,el+da*r);
    int fin = db*r - er;

    //D(index); D(c); D(a); D(b); D(ini); D(fin);
    
    
    if(fin <= 0){
      fin = abs(fin);
      int ener = ini - fin;
      ener = max(0,ener);

      m[index] = mp(ini-ener,fin);
      ans += ener*c;
      //D(ener);
    }else{
      m[index] = mp(ini,0);
      ans += ini*c;
      //D(ini);
    }
    //D(ans);
  }

  return ans;
}

int main(){
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);

  int t;
  cin >> t;
  
  rep(ncase,1,t+1){
    int e,r,n;
    cin >> e >> r >> n;

    vpii v(n);
    REP(i,n){
      cin >> v[i].first;
      v[i].second = i+1;
    }
    lld ans = solve(e,r,n,v);
    cout << "Case #" << ncase << ": " << ans << endl;
  }

  return 0;
}
