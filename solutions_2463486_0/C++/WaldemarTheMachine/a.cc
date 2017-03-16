#include <string> 
#include <cmath>  
#include <cstdlib>  
#include <algorithm>  
#include <vector>  
#include <string.h>  
#include <utility>  
#include <queue>
#include <stack>
#include <iostream>  
#include <iomanip>  
#include <ctype.h>  
#include <sstream>  
#include <map> 
#include <set> 
#include <stdio.h>  
#include <ctype.h>  

using namespace std;

#define INF = 2000000000
#define FOR(i,n) for(int i = 0;i < n;i++)
#define CLEAR(x) memset((x),0,sizeof(x))
#define REP(i,a,b) for(int i = (a);i<(b);++i)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define sz(a) (int)(a).size()

typedef long long LL;

bool isp(LL x){
  stringstream ss;
  ss << x;
  string s;
  ss >> s;
  for (int i = 0; i < s.length()/2;i++)
    if (s[i] != s[s.length()-1-i])
      return false;
  return true;
}

void solve(int tt){
  cout << "Case #" << tt << ": ";
  LL a,b,l,h;
  cin >> a >> b;
  l = (LL)sqrt(a-1);
  h = (LL)sqrt(b+1);
  LL cnt = 0;
  for (LL x = l;x <= h;x++){
    if (a<= x*x && x*x <= b && isp(x) && isp(x*x)){
      cnt++;
    }
  }
  cout << cnt << endl;
}

int main() {
  int t;
  cin >> t;
  FOR(i,t){
    solve(i+1);
  }
  return 0;
}
