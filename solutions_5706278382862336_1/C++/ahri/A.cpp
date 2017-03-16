/*
ID: ahri1
PROG: A
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define sz(X) ((int)(X).size())
#define foreach(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

unsigned long long gcd(unsigned long long a, unsigned long long b){return b==0?a:gcd(b,a%b);}


class frac {
  static long long gcd(long long a, long long b){return b==0?a:gcd(b,a%b);}

  public:    
  long long num, den;  
 
  frac() : num(0), den(1) {}
  frac(long long n, long long d) { long long g = gcd(n,d); num=n/g; den=d/g; }
  frac(const frac &drugi) : num(drugi.num), den(drugi.den) {}

  frac operator-() const {    
    return frac(-num,den);
  }
  
  bool operator==(const frac &drugi) const {
    return (num==drugi.num && den==drugi.den);
  }  
  
  bool operator==(const int &drugi) const {
    return (den==1 && num==drugi);
  }  
  
  
  
  bool operator!=(const frac &drugi) const {
    return (num!=drugi.num || den!=drugi.den);
  }  
  
  bool operator!=(const int &drugi) const {
    return (den!=1 || num!=drugi);
  }
  
  frac& operator=(const frac &drugi){
    if (this!=&drugi) {
      num=drugi.num;
      den=drugi.den;
    }
    return *this;
  }  
  
  frac& operator=(const int &drugi) {
    num=drugi;
    den=1;
    return *this;
  }
  
  frac operator+(const frac &drugi) const {
    frac ret;
    long long g=gcd(den, drugi.den);
    ret.den=(den/g)*drugi.den;
    ret.num=num*(drugi.den/g) + drugi.num*(den/g);
    g=gcd(ret.den, ret.num);
    ret.den/=g;
    ret.num/=g;
    if (ret.den<0) {
      ret.num=-ret.num;
      ret.den=-ret.den;
    }
    return ret;        
  }  
  
  frac operator-(const frac &drugi) const{    
    return -drugi+ *this;
  }
  frac operator*(const frac &drugi) const {
    frac ret, temp;
    ret.num=num;
    ret.den=den;
    temp.num=drugi.num;
    temp.den=drugi.den;
    
    long long g=gcd(ret.num, temp.den);
    ret.num/=g;
    temp.den/=g;
    g=gcd(ret.den, temp.num);
    ret.den/=g;
    temp.num/=g;   
    ret.den*=temp.den;
    ret.num*=temp.num;
    if (ret.den<0) {
      ret.den=-ret.den;
      ret.num=-ret.num;
    }
    return ret;
  }
  frac operator!() const {
    return frac(den, num);  
  }
  
  frac operator/(const frac &drugi) const {
    return (!drugi)* (*this);
  }
  
  const bool operator<(const frac &drugi) const {    
    frac temp=*this-drugi;
    return (temp.num<0);
  }
    
  const bool operator>(const frac &drugi) const {
    return (drugi<*this);  
  }
  
  frac operator+=(const frac &drugi) {
    *this = *this+drugi;
    return *this;
  }

  frac operator-=(const frac &drugi) {
    *this = *this-drugi;
    return *this;
  }
  
  frac operator*=(const frac &drugi) {
    *this = *this*drugi;
    return *this;
  }
  frac operator/=(const frac &drugi) {
    *this = *this/drugi;
    return *this;
  }  
  
  frac operator()(const int &integer) {
    *this=frac(integer,1);
    return *this;
  }  
  
  friend ostream& operator<<(ostream& output, const frac& f) {
    output << f.num << "/" << f.den;
    return output;
  }
  
  friend frac operator/(const int &x, const frac& f) {
    return frac(x,1)/f;
  }
  
};

inline int numbits(uint64 x) {
  int ret=0;
  while (x) {
    ret+=(x&1);
    x>>=1;
  }
  return ret;
}

map<uint64, int> M;


void solve2() {
  uint64 P, Q;
  char c;
  
  if (sz(M)==0) {
    for(int i=0;i<40;++i){
      M[1ULL<<i]=i;
    }
  }
  
  cin >> P >> c >> Q;
  frac A(P,Q);
  frac pola(1,2);
  frac dva (2,1);
  
  if (M.count(A.den)==0){
    cout << "impossible" << endl;
  } else {    
    int ret = 1;
    while (A<pola) {
      A=A*dva;
      ret++;
    }
    cout << ret << endl;
  }  
}

void solve(){
  int P, Q;
  char c;
  cin >> P >> c >> Q;
  frac V(P,Q);
  // cerr << "V" << V << endl;
  frac DVA(2,1);
  set<frac> A;
  
  A.insert(frac(0,1));
  A.insert(frac(1,1));
  // cerr << sz(A) << endl;
  
  set<frac> T;
  for(int i=0;i<10;++i){
    foreach (a, A) {
      if (i==9) cerr << *a << endl;
      foreach(b, A) {
        frac t = (*a+*b)/DVA;
        // cerr << "A: " << *a << endl;
        // cerr << "B: " << *b << endl;        
        // cerr << "T: " << t << endl;
        T.insert(t);
      }
    }
    foreach(t, T) {
      A.insert(*t);
    }
    // cerr << sz(A) << endl;
  }
  for(int i=0;i<9;++i){
    int moo = 1<<i;
    for(int j=0;j<moo;++j){
      frac t(j,moo);
      if (A.find(t)==A.end()) {
        cerr << "MOO: " << t << endl;
      }
      
    }
  }
  
}

int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve2();
  }
  
  return 0;
}
