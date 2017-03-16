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

#define minVal 0.0000000001

vector<int> a;
int sum =0;


int canBeEliminated(double x, int index) {

  double frac = 1 - x;
  double goal = a[index] + sum*x;
//  cout << x << " " << index << " " << goal << endl;
  for (int i=0;i<sz(a);i++) {
    if (i == index) continue;
    if (a[i]>goal) continue;
    double needs = (goal-a[i])/sum;
//    cout << i << " needs " << needs << endl;
    if (needs>frac) return false;
    frac -=needs;
  }
  return true;
}

double binarySearch(double left, double right, int index) {
  if (right-left<minVal) return left;
  double mid = (left+right)/2;
  if (canBeEliminated( mid , index ) ){
    return binarySearch(mid, right, index);
  } else {
    return binarySearch(left, mid, index);
  }

}


vector<double> solve () {
  vector<double> ret;
  int n;
  scanf("%d ", &n);
  a.resize(n);
  sum=0;
  for (int i=0;i<n;i++) {
    scanf("%d ", &a[i]);
    sum+=a[i];
  }
//  double goal = 2.0*sum/n;
  for (int i=0;i<n;i++) {
    ret.push_back(binarySearch(0,1, i)*100);    
  }
  
  return ret;
  

}




int main() {

  int _n=0;
  scanf("%d ", &_n);
  vector<vector<double> > sols;
  
  for (int i=0;i<_n;i++) {
    sols.push_back(solve());
  }
  for (int i=0;i<sz(sols);i++) {
    printf("Case #%d:", i+1);
    for (int j=0;j<sz(sols[i]);j++)
      printf(" %0.6lf", sols[i][j]);
    printf ("\n");
  }

  return 0;

}