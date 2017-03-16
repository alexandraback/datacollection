#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 5000000000;
#define PB push_back
#define sz(a) (a).size()
#define reps(i,n,m) for(int (i)=(n);(i)<(m);++(i))
#define rep(i,n) reps(i,0,n)
ll T;
string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


void solve(int time) {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  reps(i, 0, 10000000) {
    int x = i;
    string s2 = "";
    while(x > 0) {
      int t = x % 10;
      s2 += digits[t];
      x /= 10;
    }
    sort(s2.begin(), s2.end());
    x = i;
    if(s == s2) {
      vector < int > v;
      do {
        v.PB(x % 10);
        x /= 10;
      } while(x > 0);
      sort(v.begin(), v.end());
      printf("Case #%d: ", time);
      for(int y : v) {
        printf("%d", y);
      }
      printf("\n");
      return;
    }
  }
  printf("Case #%d: ", time);
  rep(i, sz(s) / 4) {
    printf("0");
  }
  printf("\n");

}

int main(){
  cin >> T;
  reps(times, 1, T+1) {
    solve(times);
  }
}
