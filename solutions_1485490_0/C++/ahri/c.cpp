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

class combo {
public:
  long long tip, count;
};

  int n, m;
  vector<combo> box;
  vector<combo> toy;
  
long long rek (int b, int t) {
  if (b>=n || t>=m) return 0;
  long long ret =0;
  long long useful = 0;
  if (box[b].tip == toy[t].tip) {
    useful = min(box[b].count, toy[t].count);
  } 
//  cout << box[b].count << " " << box[b].tip << " " << toy[t].count << " " << toy[t].tip << " :: " << useful << endl;
  
  ret+= useful;
  box[b].count -=useful;
  toy[t].count -=useful;
  long long rek1=rek(b, t+1);
  long long rek2=rek(b+1, t);
  ret+=max(rek1, rek2);
  box[b].count +=useful;
  toy[t].count +=useful;    

//  cout << b << " " << t << " == " << ret << endl;;
  return ret;
}


long long solve () {
//  cout << endl;
  scanf("%d %d ", &n, &m);
  box.resize(n);
  toy.resize(m);
  for (int i=0;i<n;i++) {
    cin >> box[i].count;
    cin >> box[i].tip;
//    scanf("%d %d ", &(box[i].count), &(box[i].tip));
  }
  for (int i=0;i<m;i++) {
    cin >> toy[i].count;
    cin >> toy[i].tip;
//    scanf("%d %d ", &(toy[i].count), &(toy[i].tip));
  }


  long long ret = rek(0,0);
  

  return ret;
}


int main() {

  int _n=0;
  scanf("%d ", &_n);
  vector<long long> sols;
  
  for (int i=0;i<_n;i++) {
    sols.push_back(solve());
  }
  for (int i=0;i<sz(sols);i++) {
    cout << "Case #" << i+1 << ": " << sols[i] << endl;
  }

  return 0;

}