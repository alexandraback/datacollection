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

vector<LL> g;

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

inline int bin(LL v){
  int l = 0,r = g.size()-1;
  int mid;
  while (r-l>1){
    mid = (l+r)/2;
    if (g[mid] > v){
      r = mid;
    } else {
      l = mid;
    }
  }
  if (g[r] <= v)
    return r;
  return l;
}

void solve(int tt){
  cout << "Case #" << tt << ": ";
  LL a,b,l,h;
  cin >> a >> b;
  int cnt = 0;

  int i1 = bin(a), i2 = bin(b);

  cnt = i2-i1+1;

  if (g[i1] != a){
    cnt--;
  }

  cout << cnt << endl;
}

int main() {
  for (LL x = 1;x <= 10000000L;x++){
    if (isp(x) && isp(x*x)){
      g.push_back(x*x);
    }
  }

  int t;
  cin >> t;
  FOR(i,t){
    solve(i+1);
  }
  return 0;
}
