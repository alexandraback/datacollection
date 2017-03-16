#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 5000000000;
#define PB push_back
#define sz(a) (a).size()
#define reps(i,n,m) for(int (i)=(n);(i)<int(m);++(i))
#define rep(i,n) reps(i,0,n)
ll T;

int main(){
  cin >> T;
  reps(times, 1, T+1) {
    int x, r, c, area;
    bool flg = false;
    cin>>x>>r>>c;
    area = r*c;
    switch(x) {
    case 1:
    case 2:
      flg = true;
      break;
    case 3:
      flg = (min(r,c) >= 2);
      break;
    case 4:
      flg = (min(r,c) >= 3);
      break;
    case 5:
      flg = (min(r,c) >= 4);
      break;
    case 6:
      flg = (min(r,c) >= 4);
      break;
    default: // if x >7 then impossible
      break;
    }
    if(area % x != 0)
      flg = false;
    printf("Case #%d: %s\n", times, flg ? "GABRIEL" : "RICHARD");
  }

}
