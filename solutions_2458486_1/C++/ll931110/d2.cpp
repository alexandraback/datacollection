#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
#define maxn 205
#define maxk 200
using namespace std;

int K,n,T;
vector<int> keysLeft;
vector<int> chest[maxn];
vector<int> startPack;
int order[maxn];
bool open[maxn];
int openKey[maxn];

vector<int> tmpKeysLeft;
int chestLeft[maxk];
bool tmpOpen[maxn];
bool reach[maxn];
int trace[maxn];

void tmpUnlock(int u) {
  tmpKeysLeft[openKey[u]]--;
  for (int i = 0; i < chest[u].size(); i++) tmpKeysLeft[chest[u][i]]++;
  tmpOpen[u] = true;
  chestLeft[openKey[u]]--;
}

int BFS(int kl) {
  // breath-first search to see which chest to open
    memset(reach,false,sizeof(reach));
    queue<int> q;
    for (int i = 0; i < n; i++) if (!tmpOpen[i] && openKey[i] == kl) {
      reach[i] = true;
      q.push(i);
    }
    int container = -1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < chest[u].size(); i++) {
        int nextKey = chest[u][i];
	if (nextKey == kl) {
	  container = u;
	  break;
	}
	for (int v = 0; v < n; v++) if (!tmpOpen[v] && !reach[v] && openKey[v] == nextKey) {
	  reach[v] = true;	 
	  trace[v] = u;
	  q.push(v);
	}
      }
      if (container >= 0) break;
    }
    // there is no way to gain more keys of type kl, terminate the process
    if (container < 0) return container;
    while (1) {
      if (openKey[container] == kl) break;
      container = trace[container];
    }
    return container;
}

bool ableToUnlock(int candidate) {
  if (keysLeft[openKey[candidate]] <= 0) return false;
  for (int i = 0; i < maxk; i++) tmpKeysLeft[i] = keysLeft[i];
  for (int i = 0; i < n; i++) tmpOpen[i] = open[i];
  tmpUnlock(candidate);
  memset(chestLeft,0,sizeof(chestLeft));
  for (int i = 0; i < n; i++) if (!tmpOpen[i]) chestLeft[openKey[i]]++;
  
  while (1) {
    bool chestRemain = false;
    for (int i = 0; i < n; i++) if (!tmpOpen[i]) chestRemain = true;
    if (!chestRemain) return true;

    bool proceed = false;
    for (int u = 0; u < n; u++) if (!tmpOpen[u]) {
      // number of keys left is greater or equal than number of chest left of the corresponding key type
      // open it right away
      if (tmpKeysLeft[openKey[u]] >= chestLeft[openKey[u]]) {
        tmpUnlock(u);
	proceed = true;
      }      
    }
    if (proceed) continue;
    // choose a type of key that can expand
    int container = -1;
    for (int i = 0; i < maxk; i++) if (tmpKeysLeft[i] < chestLeft[i] && tmpKeysLeft[i]) {
      container = BFS(i);
      if (container >= 0) break;
    }
    if (container < 0) return false;
    // do a breath-first search here
    // otherwise trace back and open the starting chest    
    tmpUnlock(container);
    proceed = true;
    if (!proceed) return false;
  }
  return true;
}

void reparse() {
  fprintf(stderr,"%d %d\n", K, n);
  for (int i = 0; i < K; i++) fprintf(stderr,"%d ", startPack[i]);
  fprintf(stderr,"\n");
  for (int i = 0; i < n; i++) {
    fprintf(stderr,"%d %d ", openKey[i], chest[i].size());    
    for (int j = 0; j < chest[i].size(); j++) fprintf(stderr,"%d ", chest[i][j]);
    fprintf(stderr,"\n");
  }
}

void solveCase(int it) {
  fprintf(stderr,"%d\n", it);
  scanf("%d %d", &K, &n);
  keysLeft.resize(maxk);
  tmpKeysLeft.resize(maxk);
  startPack.resize(K);
  for (int i = 0; i < maxk; i++) keysLeft[i] = 0;
  for (int i = 0; i < K; i++) {
    scanf("%d", &startPack[i]);
    startPack[i]--;
    keysLeft[startPack[i]]++;
  }
  for (int i = 0; i < n; i++) {
    int cnt;
    scanf("%d %d", &openKey[i], &cnt);
    openKey[i]--;    
    chest[i].resize(cnt);
    for (int j = 0; j < cnt; j++) {
      scanf("%d", &chest[i][j]);
      chest[i][j]--;
    }
  }
  memset(open,false,sizeof(open));
  for (int counter = 0; counter < n; counter++) {
    int flag = -1;
    for (int i = 0; i < n; i++) if (!open[i] && ableToUnlock(i)) {
      flag = i;
      break;
    }
    if (flag < 0) {
      printf("Case #%d: IMPOSSIBLE\n", it);
      return;
    }
    open[flag] = true;
    keysLeft[openKey[flag]]--;
    order[counter] = flag;
    for (int j = 0; j < chest[flag].size(); j++) keysLeft[chest[flag][j]]++;
  }
  printf("Case #%d: ", it);
  for (int i = 0; i < n; i++) printf("%d ", order[i] + 1);
  printf("\n");
}

int main() {
  scanf("%d", &T);
  for (int it = 1; it <= T; it++) solveCase(it);
}
