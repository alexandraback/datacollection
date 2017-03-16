#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <ctime>
#include <queue>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define sz(X) ((int)(X).size())
#define FOREACH(i,c) for( c.begin()::typeid i=(c.begin());i!=(c).end();++i)
#define IN(_lower,_variable,_higher) (((_lower)<=(_variable)) && ((_variable)<=(_higher)))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORU(v,p,k) for(int v=p;v<k;++v)
#define FORD(v,p,k) for(int v=(p)-1;v>=k;--v)
#define FORLLU(v,p,k) for(LL v=p;v<k;++v)
#define FORLLD(v,p,k) for(LL v=(p)-1;v>=k;--v)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))

vector<vector<int> > a;

int v[10001];


void dfs(int x) {
  v[x]++;  
  for (int i=0;i<sz(a[x]);i++) {
    dfs(a[x][i]);
  }
}

bool solve() {
  int n, m, temp;
  a.clear();
  scanf("%d ", &n); 
  a.resize(n);
  for (int i=0;i<n;i++) {
    scanf("%d ", &m );
    for (int j=0;j<m;j++) {
      scanf("%d ", &temp);
      a[temp-1].push_back(i);
      }
  } 
  
  for (int i=0;i<n;i++) {
    memset(v, 0, sizeof(v));
    dfs(i);
    for (int j=0;j<n;j++) {
      if (v[j]>1) return true;
    } 
  }
  
  

  
  return false;
}

int main() {

  int _n=0;
  scanf("%d ", &_n);
  vector<bool> sols;
  
  for (int i=0;i<_n;i++) {
    sols.push_back(solve());
  }
  for (int i=0;i<sz(sols);i++) {
    printf("Case #%d: %s\n", i+1, (sols[i])?"Yes":"No");
  }

  return 0;

}