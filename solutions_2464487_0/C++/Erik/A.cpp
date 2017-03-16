#include <cstdio>
#include <cmath>
#include <iostream>
#include <inttypes.h>

using namespace std;


// 2^96 a + 2^64 b + 2^32 c + d
struct bigint {
  uint64_t a,b,c,d;
};

const uint64_t lowmask = (1LLU<<32)-1;

void fix(bigint &x) {
  uint64_t over;

  over = x.d >> 32;
  x.d = x.d&lowmask;

  x.c += over;
  over = x.c >> 32;
  x.c = x.c&lowmask;

  x.b += over;
  over = x.b >> 32;
  x.b = x.b&lowmask;

  x.a += over;
  over = x.a >> 32;
  x.a = x.a&lowmask;

  if (over>0)
    cerr << "overflow error!" << endl;
}

bigint sq(bigint a) {
  // uint64_t csq = c*c;
  // uint64_t dsq = d*d;
  // uint64_t cd2 = c*d*2;

  // bigint ret;
  // ret.a = 0;
  // ret.b = (dsq&lowmask) + (cd2>>32);
  // ret.c = (cd2&lowmask) + (dsq>>32);
  // ret.d = (dsq&lowmask);

  bigint ret;
  ret.a = 0;
  ret.b = a.c*a.c;
  ret.c = 2*a.c*a.d;
  ret.d = a.d*a.d;

  fix(ret);
  return ret;
}

bigint add(bigint a, bigint b) {
  bigint ret;
  ret.a = a.a + b.a;
  ret.b = a.b + b.b;
  ret.c = a.c + b.c;
  ret.d = a.d + b.d;

  fix(ret);
  return ret;
}

bigint mult(bigint a, bigint b) {
  bigint ret;
  ret.a = 0;
  ret.b = a.c*b.c;
  ret.c = a.c*b.d+a.d*b.c;
  ret.d = a.d*b.d;

  fix(ret);
  return ret;
}

int main() {
  int T;
  cin >> T;

  // bigint eight;
  // eight.a = eight.b = eight.c = 0;
  // eight.d = 8;

  // uint64_t r,t;
  double r,t;
  for (int t_ = 0; t_ < T; t_++) {
    // cin >> r >> t;
    // bigint b,mc;
    // b.d = (2*r-1);
    // fix(b);
    // mc.d = t;
    // fix(t);

    // bigint bsq = sq(b);
    // bigint mc8 = mult(mc,eight);
    // bigint bsqpmc8 = add(bsq,mc8);

    cin >> r >> t;
    double b = 2*r-1;
    double c = -t;
    double n = (-b + sqrt(b*b-8*c))/4;

    cout << "Case #" << t_+1 << ": " << (int)n;
    cout << endl;
  }


  return 0;
}
