#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int nextInt() { int tmp; scanf("%d", &tmp); return tmp; }

struct probable {
  vector<int> v;
  map<int,int> m;

  void gen() {
    m.clear();
    for (int i = 0; i < 8; ++i) {
      int p = 1;
      for (int j = 0; j < 3; ++j)
        if (i >> j & 1)
          p *= v[j];
      ++m[p];
    }
  }
};

vector<probable> ps;

void gen()
{
  for (int i = 0; i < 1 << 12; ++i) {
    probable p;
    for (int j = 0; j < 3; ++j)
      p.v.push_back((i >> 2 * j & 3) + 2);
    p.gen();
    ps.push_back(p);
  }
}

void solve(vector<int> p)
{
  int mx = 0;
  probable ans;
  for (int i = 0; i < ps.size(); ++i) {
    int d = 1;
    for (int j = 0; j < p.size(); ++j) {
      if (ps[i].m.find(p[j]) != ps[i].m.end())
        d *= ps[i].m[p[j]];
      else
        d = 0;
    }
    if (d > mx)
      ans = ps[i];
  }
  for (int i = 0; i < ans.v.size(); ++i)
    printf("%d", ans.v[i]);
  puts("");
}

int main()
{
  int T = nextInt();
  int R = nextInt();
  int N = nextInt();
  int M = nextInt();
  int K = nextInt();

  gen();

  puts("Case #1:");
  for (int i = 0; i < R; ++i) {
    vector<int> p(K);
    for (int j = 0; j < K; ++j)
      p[j] = nextInt();
    solve(p);
  }
}
