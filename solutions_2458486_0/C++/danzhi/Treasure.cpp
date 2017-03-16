#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <functional>
#include <hash_map>
#include <iostream>
#include <iomanip>
#include <list>
#include <deque>
#include <queue>
#include <math.h>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
bool test = false;
const double pi=acos(-1.0);
const double eps=1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\Treasure";
void reopen(char* a) {
	char input[256], output[256];
	sprintf(input, "%s\\%s", rootdir, a);
	sprintf(output, "%s\\%s", rootdir, a);
	char *p = strstr(output, ".in");
	if (p) sprintf(p, ".out"); 
	else sprintf(&p[strlen(output)], ".out");
	debug(input);
	debug(output);
	freopen(input,"r",stdin);
	if (!test) freopen(output,"w",stdout);
}

const int C = 201;
int T = 0;
int K = 0;         // Number of keys you start with
int N = 0;         // Number of chests to open
int skeys[500];    // types of the keys that you start with
int ti[C];       // the key type needed to open the chest i
int ki[C];       // the number of keys inside the chest i
int kit[C][C];   // the types of the keys contained within the chest i

int kc[C];       // count of keys for each type
bool opened[C];  // whether chest i already opened

void showin(int cn) {
  if (!test) return;
  printf("Problem %d\n", cn);
  printf("%d %d\n", K, N);
  for(int i = 0; i < K; i++) {
    printf("%d ", skeys[i]);
  }
  printf("\n");
  for(int i = 1; i <= N; i++) {
    printf("%d %d ", ti[i], ki[i]);
    for(int j = 0; j < ki[i]; j++) {
      printf("%d ", kit[i][j]);
    }
    printf("\n");
  }
}

typedef struct OP {
  int id;  // chest index
  int kt;  // key type
};
OP ops[500];
int top = 0;
int startid = 1;

void openChest(int i) {
  ops[top].id = i;
  ops[top].kt = ti[i];
  top++;
  kc[ti[i]]--;
  // pick up all keys in chest i
  for (int j = 0; j < ki[i]; j++) {
    int type = kit[i][j];
    kc[type]++;
  }
  opened[i] = true;
  startid = 1;
  if (test) {
    printf("opened chest %2d keys: ", i);
    for (int j = 1; j <= N; j++) {
      if (kc[j] == 0) continue;
      for (int k = 0; k < kc[j]; k++) printf("%d ", j);
    }
    printf("\n");
  }
}

void closeChest() {
  int i = ops[top-1].id;
  opened[i] = false;
  // undo opening of last chest
  // put back all keys in chest i
  for (int j = 0; j < ki[i]; j++) {
    int type = kit[i][j];
    kc[type]--;
  }
  kc[ti[i]]++;
  top--;
  startid = i + 1;
  if (test) printf("closed chest %2d\n", i);
}

bool totalCountOk() {
  int need[C];
  int have[C];
  for (int i = 1; i < C; i++) {
    need[i] = 0;
    have[i] = 0;
  }
  for (int i = 1; i < C; i++) {
    need[ti[i]]++;
    for (int j = 0; j < ki[i]; j++) {
      int type = kit[i][j];
      have[type]++;
    }
  }
  for (int i = 0; i < K; i++) have[skeys[i]]++;
  for (int i = 1; i < C; i++) {
    if (need[i] > have[i]) return false;
  }
  return true;
}

void solve(int cn) {
  
  top = 0;
  for (int i = 0; i <= C; i++) {
    kc[i] = 0;
    opened[i] = false;
  }
  opened[0] = true;
  for (int i = 0; i < K; i++) kc[skeys[i]]++;
  if (!totalCountOk()) {
    printf("Case #%d: IMPOSSIBLE\n", cn);
    return;
  }
  startid = 1;
  vector<int> chests;

  while(true) {
    if (top >= N) {
      printf("Case #%d: ", cn);
      for (int i = 0; i < top; i++) {
        printf("%d ", ops[i].id);
      }
      printf("\n");
      return;
    }
    bool openedNewChest = false;
    // consider all chests in ascending order that we have key to open
    for (int i = startid; i <= N; i++) {
      if (opened[i]) continue;
      if (kc[ti[i]] <= 0) continue;
      // if other chest need the same key and 
      // we will be stuck if use it here, skip it.
      chests.clear();
      chests.push_back(i);
      for (int j = 1; j <= N; j++) {
        if (opened[j]) continue;
        if (j == i) continue;
        if (ti[j] != ti[i]) continue;
        chests.push_back(j);
      }
      if (kc[ti[i]] < chests.size()) {
        // We can only open the current one if it has self keyinside
        bool hasselfinside = false;
        for (int k = 0; k < ki[i]; k++) {
          if (kit[i][k] == ti[i]) {
            hasselfinside = true; 
            break;
          }
        }
        if (!hasselfinside) continue;
      }
      openChest(i);
      openedNewChest = true;
      break;
    }
    if (!openedNewChest) {
      if (top == 0) {
        printf("Case #%d: IMPOSSIBLE\n", cn);
        return;
      } else {
        closeChest();
      }
    }
  }
  assert(false);
}


int main(int argc, char* argv[]) {
  test = false;
	// reopen("sample.in");
  reopen("D-small-attempt1.in");
  // reopen("C-large-1.in");
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
    scanf("%d %d", &K, &N);
    for(int i = 0; i < K; i++) {
      scanf("%d", &skeys[i]);
    }
    ti[0] = 0;
    ki[0] = 0;
    for(int i = 1; i <= N; i++) {
      scanf("%d %d", &ti[i], &ki[i]);
      for(int j = 0; j < ki[i]; j++) {
        scanf("%d", &kit[i][j]);
      }
    }
    showin(t);
    solve(t);
  }
 	return 0;
}