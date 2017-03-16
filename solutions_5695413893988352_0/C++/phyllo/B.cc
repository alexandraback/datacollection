#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

void solve_small(const string& str1, const string& str2){
  int diff = 1000000;
  int best1 = 100000, best2 = 100000;
  string best1_str, best2_str;
  int N = str1.length();
  
  int mx = 1;
  rep(i,N) mx *= 10;
  rep(x,mx){
    rep(y,mx){
      bool ok = true;
      string a(N,0), b(N,0);
      int xx = x, yy = y;
      rep(i,N){
        a[N-1-i] = '0'+xx%10;
        xx/=10;
        b[N-1-i] = '0'+yy%10;
        yy/=10;
      }
      rep(i,N){
        if(str1[i] != '?' && str1[i] != a[i]) ok = false;
        if(str2[i] != '?' && str2[i] != b[i]) ok = false;
      }
      if(!ok) continue;
      if(diff == abs(x-y)){
        if(best1 > x){
          best1 = x;
          best1_str = a;
          best2 = y;
          best2_str = b;
        }
      }
      else if(diff > abs(x-y)){
        diff = abs(x-y);
        best1 = x;
        best1_str = a;
        best2 = y;
        best2_str = b;
      }
    }
  }
  cout << best1_str << " " << best2_str;

}

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t,T){
    string str1, str2;
    cin >> str1 >> str2;
    cout << "Case #" << t+1 << ": ";
    solve_small(str1, str2);
    cout << endl;
  }
  
  return 0;
}

