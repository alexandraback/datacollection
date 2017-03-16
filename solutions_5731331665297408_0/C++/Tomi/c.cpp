#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

int N, M;

vector<int> zip;
vector<vector<int> > sus;

vector<int> sled;
long long visited;
string mystr;
string beststr;

void backtrack() {
  if (sled.empty()) {
    if (visited == (1LL<<N)-1) {
      if (beststr.empty() || mystr < beststr) {
        beststr = mystr;
      }
    }
    return;
  }

  int cur = sled.back();

  // A) pick outgoing
  int best = 100000, bestv = -1;
  for (unsigned i = 0; i < sus[cur].size(); i++) {
    int v = sus[cur][i];
    if (visited & (1LL<<v)) continue;
    if (zip[v] < best) best = zip[v], bestv = v;
  }
  if (bestv != -1) {
    char buf[10]; sprintf(buf, "%05d", best);
    long long oldvisited = visited;

    sled.push_back(bestv);
    visited |= (1LL<<bestv);
    mystr.append(buf);

    backtrack();

    sled.pop_back();
    visited = oldvisited;
    mystr.resize(mystr.size() - 5);
  }

  // B) pick returning
  sled.pop_back();
  backtrack();
  sled.push_back(cur);
}

int main() {
  int TT;
  scanf("%d", &TT);
  for (int tc = 1; tc <= TT; tc++) {
    scanf("%d%d", &N, &M);

    zip.clear();
    zip.resize(N);
    sus.clear();
    sus.resize(N);

    int start = 0;
    for (int i = 0; i < N; i++) {
      scanf("%d", &zip[i]);
      if (zip[i] < zip[start]) start = i;
    }

    for (int i = 0; i < M; i++) {
      int a, b;
      scanf("%d%d", &a, &b); a--; b--;
      sus[a].push_back(b);
      sus[b].push_back(a);
    }

    char buf[10]; sprintf(buf, "%05d", zip[start]);

    sled.clear();
    sled.push_back(start);
    visited = (1LL<<start);
    mystr = buf;
    beststr = "";
    backtrack();

    printf("Case #%d: %s\n", tc, beststr.c_str());
  }
}
