#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

int R, S;
int map[128][128];
char bio[128][128];
vector<pair<int, int> > V;

struct cmp {
  bool operator() (const pair<int,int> &a, const pair<int, int> &b) {
    return map[a.first][a.second] == map[b.first][b.second] ?
      a < b : map[a.first][a.second] > map[b.first][b.second];
  }
};

void init() {
  V.clear();
  memset(bio, 0, sizeof bio);
  for (int i = 0; i < R; ++i)
    for (int j = 0; j < S; ++j)
      V.push_back(pair<int, int>(i, j));
  sort(V.begin(), V.end(), cmp());
}

// vrati 0 ako je sve ok. tj. ako se moze s ruba doc do svih
// tocaka u [lo, hi>
int check(int lo, int hi) {
  for (int j = lo; j < hi; ++j) {
    int mx = V[j].first, my = V[j].second, ok = 2;
    // jeli cijeli njegov red cist?
    for (int k = 0; k < R; ++k)
      if (bio[k][my]) {--ok; break;}
    // jeli cijeli njegov stupac cist?
    for (int k = 0; k < S; ++k)
      if (bio[mx][k]) {--ok; break;}
    if (!ok) return 1;
  }
  return 0;
}

void add(int lo, int hi) {
  for (int j = lo; j < hi; ++j)
    bio[ V[j].first ][ V[j].second ] = 1;
}

int solve() {
  init();
  for (int j = 0; j < V.size(); ++j) {
    pair<int, int> &cur = V[j];
    int height = map[cur.first][cur.second];
    int k = j;
    for (; k < V.size() && height == map[V[k].first][V[k].second];++k);
    // [j, k> je interval istih visina.
    if (check(j, k)) return 0;
    add(j, k);
    j = k - 1;
  }
  return 1;
}

int main() {
  int k;
  scanf("%d", &k);
  for (int j = 0; j < k; ++j) {
    scanf("%d%d", &R, &S);
    for (int i = 0; i < R; ++i)
      for (int k = 0; k < S; ++k)
        scanf("%d", &map[i][k]);
    printf("Case #%d: %s\n", j + 1, solve() ? "YES" : "NO");
  }
  return 0;
}


