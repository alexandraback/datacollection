#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
using namespace std;

const int N=12;
int j, p, s, k;
int use[N][N][N];

void read(){
  cin >> j >> p >> s >> k;
}

// tuple<int,int,int> next(int a, int b, int c){
//   if(c<s) return mt(a, b, c+1);
//   else if(b<p) return mt(a, b+1, 1);
//   else if(a<j) return mt(a+1, 1, 1);
//   else return mt(0,0,0);
// }

void solve(){
  vector<tuple<int,int,int> > v;
  memset(use, 0, sizeof(use));
  for(int j_=1; j_<=j; j_++){
    for(int p_=1; p_<=p; p_++){
      for(int s_=1; s_<=s; s_++){
        if(use[j_][p_][0] == k || use[j_][0][s_] == k || use[0][p_][s_] == k) continue;
        use[j_][p_][0]++; use[j_][0][s_]++; use[0][p_][s_]++;
        v.pb(mt(j_,p_,s_));
      }
    }
  }
  cout << v.size() << '\n';
  int tmp1, tmp2, tmp3;
  for(auto tmp: v){
    tie(tmp1, tmp2, tmp3)=tmp;
    cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << '\n';
  }

}

int main(){
  int T;
  cin >> T;
  for(int i=1; i<=T; i++){
    read();
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}