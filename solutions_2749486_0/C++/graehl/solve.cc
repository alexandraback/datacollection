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


I gx,gy;
I x,y;
N maxpath=1000000;
//N path[maxpath];

void solve() {
  x=y=0;
  DB(gx);DB(gy);
  while (x<gx) {
    out<<"WE";
    ++x;
  }
  while (x>gx) {
    out<<"EW";
    --x;
  }
  while (y<gy) {
    out<<"SN";
    ++y;
  }
  while (y>gy) {
    out<<"NS";
    --y;
  }
}

int main() {
  in>>ncase;
  for (int i = 0; i<ncase; ++i) {
    in >> gx >> gy;
    writeCase();
    solve();
    out <<'\n';
    DBNL;DBNL;
  }
  InEof();
}
