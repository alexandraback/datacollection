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
    int n;
    string data;
    int stnd = 0;
    int ans = 0;
    cin >> n >> data;
    rep(i,sz(data)){
      int m = (int) (data[i] - '0');
      if (m && stnd < i) {
        int d = i - stnd;
        stnd += d;
        ans  += d;
      }
      stnd += m;
    }
    printf("Case #%d: %d\n", times, ans);
  }
}
