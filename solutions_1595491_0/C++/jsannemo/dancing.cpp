#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool solve(int tc) {
  int n, s, p;
  cin >> n >> s >> p;
  vector<int> sc(n);
  rep(i,0,n){
    int q;
    cin >> q;
    sc[i] = q;
  }
  int scwo = 	0;
  int scwi = 0;
  rep(i,0,n){
    if((sc[i]+2)/3 >= p) scwo++;
    else if(p >= 2 && (sc[i]+4)/3 >= p) scwi++;
  }
  cout << "Case #" <<(tc+1)<<": "<<(scwo+min(scwi, s))<<endl;
  return true;
}



int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);
  int n = 0;
  if(!n) cin >> n;
  for(int i = 0; i < n && solve(i); ++i);
}