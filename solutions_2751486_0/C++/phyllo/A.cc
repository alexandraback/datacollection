#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
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

int en[1000005];

bool isVowel(char c){
  if(c == 'a') return true;
  if(c == 'e') return true;
  if(c == 'i') return true;
  if(c == 'o') return true;
  if(c == 'u') return true;
  return false;
}

ll solve_naive(const std::string& name, int n){
  ll ret = 0;
  rep(b,name.length()){
    REP(e,b+1,name.length()+1){
      string sub = name.substr(b, e-b);

      bool flg = false;
      int cnt = 0;
      rep(i,sub.length()){
        if(!isVowel(sub[i])){
          cnt++;
          if(cnt>=n){
            flg = true;
            break;
          }
        }else{
          cnt = 0;
        }
      }
      if(flg) ret++;
    }
  }
  return ret;
}

ll solve(const std::string& name, int n){
  ll ret = 0;

  int b = -1;
  ll sub = 0;
  int start = 0;
  rep(i,name.length()){
    
    if((isVowel(name[i]) || (i==name.length()-1))){
      if(b == -1) b = i;
      int e = i-1;
      if(!isVowel(name[i])) e = i;
      //cout << b << " " << e << endl;

      if(e+1-b >= n){
        ll res = 0;
        ll nn = name.length()-b-n+1;
        ll mm = e+1-b-n+1;

        ll forward = b-start+1;
        
        res += nn * forward;

        ll pp = name.length()-e;
        ll qq = e-b+1-n;
        //cout << pp << " " << qq << endl;
        res += pp * qq;
        
        ll N = e+1-b-2-(n-1); if(N<=0) N=0;
        ll inter = 0;
        if(N%2==0){
          inter = N/2LL*(N+1);
        }else{
          inter = (N+1)/2LL*N;
        }
        res += inter;

        
        ret += res;
        start = e-n+2;
      }
      b = -1;
    }
    else if(!isVowel(name[i]) && b == -1){
      b = i;
    }
  }
  
  return ret;
}

int main(){
  int T;
  cin >> T;
  
  rep(t,T){
    std::string name;
    int n;
    cin >> name >> n;
    
    cout << "Case #" << t+1 << ": " << solve(name, n) << endl;
  }
  
  return 0;
}
