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

void solve (int t){
  cout << "Case #" << t << ": ";
  int ar,n;
  cin >> ar >> n;
  vector<int> a(n);
  FOR(i,n)
  cin >> a[i];

  sort(a.begin(),a.end());

  int bst = 2000000000;

  for (int l = n;l >= 0;l--){
    int my = ar;
    int cnt = n-l;
    bool bad = 0;
    FOR(i,l){
      if (my > a[i]){
        my += a[i];
      } else {

        if (my == 1){
          bad = 1;
          break;
        }

        my = 2*my-1;
        i--;
        cnt++;
      }
    }

    if (bad)
      continue;

    if (cnt < bst)
      bst = cnt;
  }
  cout << bst << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  FOR(i,t)
  solve(i+1);

  return 0;
}
