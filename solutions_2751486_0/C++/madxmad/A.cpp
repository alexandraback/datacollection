#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>

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

bool isvowel(char c){
  c = tolower(c);
  if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
    return true;
  return false;
}

int main(){
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);

  int T;
  cin >> T;

  rep(ncase,1,T+1){
    string name;
    int l;
    cin >> name >> l;
    
    int n = name.size();
    vi v(n,0);
    REP(i,n) if(!isvowel(name[i])){
      v[i] = 1;
      if(i) v[i] += v[i-1];
    }

    int index = 0;
    lld ans = 0;
    REP(i,n){
      while(index < n and (v[index] < l or (index-i+1)<l)) index++;
      ans += n - index;
    }

    cout << "Case #" << ncase << ": " << ans << endl;
  }
  return 0;
}
