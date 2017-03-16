#include <fstream>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <stdint.h>
#include <cmath>
#include <iomanip>
#include <boost/math/special_functions/binomial.hpp>
#include <boost/math/distributions/binomial.hpp>


#ifdef NDEBUG
#define DB(x)
#define DBNL
#else
#define DB(x) cerr<<" "#x"="<<(x);
#define DBNL cerr<<'\n';
#endif

using namespace std;
using namespace boost;
using namespace boost::math;

typedef double R;
typedef unsigned N;
typedef int I;
typedef int64_t I64;
typedef uint64_t N64;
typedef N64 A;

ifstream in("in");
ofstream out("out");
int casei, ncase;
ostream &writeCase() {
  return out<<"Case #"<<++casei<<": ";
}
char const* YESNO(bool yes) {
  return yes ? "YES" : "NO";
}
template <class C>
void writeCase(C const& c) {
  writeCase() << c << '\n';
}
void InEof() {
  char c;
  assert(!(in>>c));
  assert(in.eof());
}
template <class I>
void MaxEq(I &i, I bigger) {
  if (i<bigger)
    i = bigger;
}
template <class I>
void MinEq(I &i, I smaller) {
  if (smaller<i)
    i = smaller;
}
template <class U>
void Show(U *v, std::size_t N) {
  copy(v, v+N, ostream_iterator<U>(cerr," "));
  cerr<<'\n';
}

inline bool vowel(char c) {
  return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

inline bool cons(char c) {
  return !vowel(c);
}


N n;
N const maxlen=7*1024*1024;
bool c[maxlen];
N cc[maxlen];
N nextrun[maxlen];
N len;
A nvalue;
std::string wordstr;

void solve() {
  nvalue=0;

  len=wordstr.size();
  N cumc=0;
  cc[0]=0;
  for (N i=0;i<len;++i) {
    cumc+=(c[i]=cons(wordstr[i]));
    cc[i+1]=cumc;
  }
  c[len]=0;
  N runlen=0;
  N start=0;
  for (N i=0;i<=len;++i) { // sum for each i ending a max len run
    if (runlen >= n) {
      N b=i-n;
      N nb=b-start+1;
      N ne=len-i+1;
      N add=nb*ne;
      start=b+1;
      nvalue+=add;
      //DB(start);DB(b);DB(i);DB(len);DB(nb);DB(ne);DB(add);DB(nvalue);
    }
    if (c[i]) {
      ++runlen;
    } else {
      runlen=0;
    }
  }
}

int main() {
  in>>ncase;
  for (int i = 0; i<ncase; ++i) {
    in >> wordstr;
    in >> n;
    solve();
    writeCase() << setprecision(19) << nvalue <<'\n';
    DBNL;DBNL;
  }
  InEof();
}
