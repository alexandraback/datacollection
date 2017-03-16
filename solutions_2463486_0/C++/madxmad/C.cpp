#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define D(x) cout << #x << " = " << x << endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=b-1;i>=a;i--)
#define REP(i,n) rep(i,0,n)
#define REPD(i,n) repd(i,0,n)
#define pb push_back
#define mp make_pair

typedef long long int lld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<lld> vlld;

const lld MAXN = 10000010;

bool ispalindrome(lld n){
  stringstream ss;
  ss << n;

  string s;
  ss >> s;

  int size = s.size();
  REP(i,size/2) if(s[i] != s[size-i-1])
    return false;
  return true;
}

int main(){
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);

  int t;
  cin >> t;

  vlld v;
  rep(n,1,MAXN) if(ispalindrome(n)){
    lld n2 = n; n2 *= n;
    if(ispalindrome(n2))
      v.push_back(n2);
  }

  rep(ncase,1,t+1){
    lld a, b;
    cin >> a >> b;

    int ans = 0;
    REP(i,v.size()) if(a <= v[i] and v[i] <= b)
      ans++;

    cout << "Case #" << ncase << ": " << ans << endl;
  }

  return 0;
}
