#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define MAXN 1200
#define INF 200000

int T;

bool go(int x, int r, int c) {
  if (x>r && x>c) return false;
  if (x>=7) return false;
  if ((r*c)%x) return false;
  if (x<=2) return true;
  if (r>c) swap(r,c);
  if (r==1) return false;
  if (x==3) return true;
  if (r==2) return false;
  if (x==4) return true;
  if (r==3) return false;
  return true;
}

int main() {
  cin >> T;
  REP(zz,T) {
    int x,r,c;
    cin >> x >> r >> c;
    cout << "Case #" << (zz+1) << ": " << (go(x,r,c)?"GABRIEL":"RICHARD") << endl;
  }
}
