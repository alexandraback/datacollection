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
char key[10] = {'Z', 'W', 'U', 'X', 'G', 'R', 'F', 'V', 'O', 'E'};
int val[10] = {  0, 2, 4, 6, 8, 3, 5, 7, 1, 9};

int al[30] = {0};
int ans[30] = {0};
void solve(int time) {
  string s;
  rep(i, 30){
    al[i] = ans[i] = 0;
  }
  cin >> s;
  rep(i, sz(s)) {
    al[s[i] - 'A'] +=1;
  }

  rep(i, 10) {
    int cnt = al[key[i] - 'A'];
    string t = digits[val[i]];
    ans[val[i]] = cnt;
    rep(j, sz(t)){
      al[t[j] - 'A'] -= cnt;
    }
  }

  printf("Case #%d: ", time);
  rep(i, 10) {
    rep(j, ans[i]) {
      printf("%d", i);
    }
  }
  printf("\n");
}


int main(){
  cin >> T;
  reps(times, 1, T+1) {
    solve(times);
  }

}
