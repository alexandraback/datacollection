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

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define sz(X) ((int)(X).size())
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define IN(_lower,_variable,_higher) (((_lower)<=(_variable)) && ((_variable)<=(_higher)))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORU(v,p,k) for(int v=p;v<k;++v)
#define FORD(v,p,k) for(int v=(p)-1;v>=k;--v)
#define FORLLU(v,p,k) for(LL v=p;v<k;++v)
#define FORLLD(v,p,k) for(LL v=(p)-1;v>=k;--v)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

set<vector<int> > sume;
vector<int> a;
vector<vector<int> >nove;
vector<int> temp;

vector<int> solve() {
  vector<int> ret;
  int n;
  scanf("%d ", &n);
  a.resize(n);
  int sum=0;
  for (int i=0;i<n;i++) { scanf("%d ", &a[i]); sum+=a[i]; }
  sume.clear();
 
  for (int i=0;i<n;i++) {
    nove.clear();
    temp.clear();
    temp.push_back(a[i]);
    nove.push_back(temp);
    FOREACH(x, sume) {
      temp=*x;
      temp.push_back(a[i]);
      temp[0]+=a[i];
      nove.push_back(temp);
    }
    FOREACH(x, nove){
      FOREACH(y, sume) {
        if ((*x)[0]==(*y)[0]) {
          temp = *x;
          for (int j=1;j<sz(temp);j++)
            temp[0]-=temp[j];
          for (int j=0;j<sz(temp);j++)
            ret.push_back(temp[j]);
          ret.push_back(0);
          temp = *y;
          for (int j=1;j<sz(temp);j++)
            temp[0]-=temp[j];
          for (int j=0;j<sz(temp);j++)
            ret.push_back(temp[j]);
          return ret;
        }
      }
      sume.insert(*x);
    }
    /*
    FOREACH(x, sume)  {
      cout << (*x)[0] << " ";
    }
    cout << endl;
    */
  }
  
  ret.push_back(-1);
  
  
  return ret;
}





int main() {

  int _n=0;
  scanf("%d ", &_n);
  vector<vector<int> > sols;
  
  for (int i=0;i<_n;i++) {
    sols.push_back(solve());
  }
  for (int i=0;i<sz(sols);i++) {
    printf("Case #%d:\n", i+1);
    if (sols[i][0]==-2) {
      printf("Impossible\n");
      continue;
    }
    int space=0;
    for (int j=0;j<sz(sols[i]);j++) {
      if (space) printf(" ");
      if (sols[i][j]==0) { printf("\n"); space=0; continue; }
      printf("%d", sols[i][j]);
      space=1;
    }
    printf ("\n");
  }

  return 0;

}