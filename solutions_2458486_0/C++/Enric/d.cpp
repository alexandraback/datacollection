#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
#define REP(i,n) for (int i=0;i<int(n);++i)
const int NK = 201;

typedef pair<int,int> P;
#define x first
#define y second
int memo[1<<20];
vector<int> clau;
vector<vector<P> > regal;
int n;
vector<int> vret;

int f(int x, vector<int>& vk) {
  if (x==0) return memo[0] = 1;
  int &ans = memo[x];
  if (ans>=0) return ans;
  ans=0;
  REP(i,n) if ((x>>i)&1 and vk[clau[i]]>0) {
    vk[clau[i]]--;
    REP(j,regal[i].size()) vk[regal[i][j].x]+=regal[i][j].y;
    if (f(x^(1<<i), vk)) {
      vret.push_back(i+1);
      return ans=1;
    }
    REP(j,regal[i].size()) vk[regal[i][j].x]-=regal[i][j].y;
    vk[clau[i]]++;
  }
  return ans;
}

int main() {
  int t; cin >> t;
  REP(cas,t) {
    memset(memo,-1,sizeof(memo));
    vret.clear();
    int k;
    cin >> k >> n;
    vector<int> vk(NK,0); //vk[i] keys of type i
    REP(i,k) {
      int x;
      cin >> x;
      vk[x]++;
    }
    clau = vector<int>(n,0);
    regal = vector<vector<P> > (n);
    REP(i,n) {
      cin >> clau[i];
      int z; cin >> z;
      vector<int> reg(NK,0);
      REP(j,z) { //reg[i] = (tipus, quantitat)
        int x; cin >> x;
        reg[x]++;
      }
      REP(j,NK) if (reg[j]>0) regal[i].push_back(P(j,reg[j]));
    }
    cout << "Case #" << cas+1 << ": ";
    int ret = f((1<<n)-1, vk);
    reverse(vret.begin(),vret.end());
    if (ret) {
      REP(i,vret.size()) {
        if (i>0) cout << " ";
        cout << vret[i];
      }
      cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
  }
}
