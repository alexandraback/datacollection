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
      flg = (area%x==0);
      break;
    case 3:
      flg = (area%x==0) && (area != 3);
      break;
    default:
      flg = (area%4==0) && (area >= 12);
    }
    printf("Case #%d: %s\n", times, flg ? "GABRIEL" : "RICHARD");
  }

}
