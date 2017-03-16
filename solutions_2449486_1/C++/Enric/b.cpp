#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define REP(i,n) for (int i=0;i<int(n);++i) 
int main() {
  int t; cin >> t;
  REP(cas,t) {
    int n, m; cin >> n >> m;
    vector<vector<int> > v(n,vector<int>(m,0));
    REP(i,n) REP(j,m) cin >> v[i][j];
    //Lemma: There exists a row or column with all same elements.
    vector<int> f(n,0),c(m,0);
    REP(i,n) REP(j,m) {
      f[i]=max(f[i],v[i][j]);
      c[j]=max(c[j],v[i][j]);
    }
    bool ok=1;
    REP(i,n) REP(j,m) if (v[i][j]!=min(f[i],c[j])) ok=0;
    cout << "Case #" << cas+1 << ": ";
    if (ok) cout <<"YES"<<endl;
    else cout << "NO" << endl;
  }
}
