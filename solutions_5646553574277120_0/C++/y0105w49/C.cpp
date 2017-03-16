#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define foreach(v,c) for(typeof(c.begin()) v=c.begin();v!=c.end();++v)
#define printA(a,l,r) for(int zzz49=l; zzz49!=r; zzz49++) cout << a[zzz49] << ((zzz49==r-1)?"\n":" ")

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define MAXD 120

int T,zz;

int coins[MAXD];

int main() {
  cin >> T;
  for (int zz=1;zz<=T;zz++) {
    int C,D,V;
    cin >> C >> D >> V;
    assert(C==1);
    REP(i,D) cin >> coins[i];
    int highposs=0;
    int ind = 0;
    int res=0;
    while (highposs<V) {
      if (ind<D && highposs+1>=coins[ind])
        highposs+=coins[ind++];
      else {
        ++res;
        highposs+=highposs+1;
      }
    }



    cout << "Case #" << zz << ": " << res << endl;
  }
  return 0;
}
