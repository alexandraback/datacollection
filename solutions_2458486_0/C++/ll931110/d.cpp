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
#define maxn 20
using namespace std;

bool reach[1 << maxn];
vector<int> keyLeft[1 << maxn];
vector<int> order[1 << maxn];
vector<int> contain[maxn];
int openKey[maxn];
int n,k,T;

void solveCase(int it) {
  scanf("%d %d", &k, &n);
  for (int i = 0; i < (1 << n); i++) reach[i] = false;
  reach[0] = true;
  for (int i = 0; i < 200; i++) keyLeft[0][i] = 0;
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    keyLeft[0][x - 1]++;
  }
  for (int i = 0; i < n; i++) {
    int counter;
    scanf("%d %d", &openKey[i], &counter);
    openKey[i]--;
    contain[i].resize(counter);
    for (int j = 0; j < counter; j++) {
      scanf("%d", &contain[i][j]);
      contain[i][j]--;
    }
  }
  for (int mask = 0; mask < (1 << n); mask++) if (reach[mask])
    for (int i = 0; i < n; i++) if ((mask & (1 << i)) == 0) {
      // append the i-th chest
      if (keyLeft[mask][openKey[i]] <= 0) continue;
      vector<int> nextOrder = order[mask];
      nextOrder.push_back(i);
      int mask2 = mask ^ (1 << i);      
      if (!reach[mask2] || order[mask2] > nextOrder) {
        vector<int> tmp = keyLeft[mask];
	tmp[openKey[i]]--;
	for (int j = 0; j < contain[i].size(); j++)
	  tmp[contain[i][j]]++;
	order[mask2] = nextOrder;
	reach[mask2] = true;
	keyLeft[mask2] = tmp;
      }
    }

  printf("Case #%d: ", it);
  int last = (1 << n) - 1;
  if (!reach[last]) printf("IMPOSSIBLE\n"); else {
    for (int i = 0; i < order[last].size(); i++) printf("%d ", order[last][i] + 1);
    printf("\n");
  }
}

int main() {
  scanf("%d", &T);
  for (int i = 0; i < (1 << 20); i++) keyLeft[i].resize(200);
  for (int it = 1; it <= T; it++) solveCase(it);
}
