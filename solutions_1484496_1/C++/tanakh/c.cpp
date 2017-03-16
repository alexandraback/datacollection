#include <iostream>
#include <unordered_set>
#include <vector>
#include <stdint.h>
using namespace std;

class xor128 {
public:
  uint32_t x, y, z, w;
  xor128() {
    x=123456789,y=362436069,z=521288629,w=88675123;
  }

  uint32_t operator()() {
    uint32_t t=(x^(x<<11));x=y;y=z;z=w;
    return( w=(w^(w>>19))^(t^(t>>8)) );
  }
};

int probn[10];
int probv[10][500];

int main()
{
  int cn; cin >> cn;

  for (int cc = 1; cc <= cn ; ++cc) {
    int n; cin >> n;

    vector<int64_t> ns(n);
    for (int i = 0; i < n; ++i)
      cin >> ns[i];

    cout << "Case #" << cc << ":" << endl;
    cerr << "#" << cc << endl;

    uint64_t tt = 0;
    {
      xor128 rng;
      unordered_set<int64_t> ss;
      for (; ; ) {
        if (ss.size() % 1000000 == 0)
          cerr << ss.size() << endl;
        uint64_t tot = 0;
        uint32_t rs[32*16];
        for (int i = 0; i < 16; ++i) rs[i] = rng();

        for (int i = 0; i < n; ++i)
          if ((rs[i >> 5] >> (i & 31)) & 1) tot += ns[i];

        if (!ss.insert(tot).second) {
          bool fst = true;
          for (int i = 0; i < n; ++i) {
            if ((rs[i >> 5] >> (i & 31)) & 1) {
              if (fst) fst = false; else cout << ' ';
              cout << ns[i];
            }
          }
          cout << endl;
          cerr << "ok!" << endl;
          tt = tot;
          break;
        }
      }
    }

    {
      xor128 rng;
      for (; ; ) {
        uint64_t tot = 0;
        uint32_t rs[32*16];
        for (int i = 0; i < 16; ++i) rs[i] = rng();

        for (int i = 0; i < n; ++i)
          if ((rs[i >> 5] >> (i & 31)) & 1) tot += ns[i];

        if (tot == tt) {
          bool fst = true;
          for (int i = 0; i < n; ++i) {
            if ((rs[i >> 5] >> (i & 31)) & 1) {
              if (fst) fst = false; else cout << ' ';
              cout << ns[i];
            }
          }
          cout << endl;
          break;
        }
      }
    }
  }

  return 0;
}
