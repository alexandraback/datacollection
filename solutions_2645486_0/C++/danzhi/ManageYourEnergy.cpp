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

const char rootdir[] = "C:\\CodeJam\\ManageYourEnergy";
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

int T = 0;
int E = 0;
int R = 0;
int N = 0;
int v[10000 + 10];

typedef struct ITEM {
  int index;
  int value;
};
ITEM a[10000];
int s[10000 + 10];

void showin() {
	if (!test) return;
  printf("%d %d %d\n", E, R, N);
  for (int i = 0; i < N; i++) {
    printf("%d ", v[i]);
  }
  printf("\n\n");
}

int compareItem(const void* a, const void* b) {
  ITEM* pa = (ITEM *)a;
  ITEM* pb = (ITEM *)b;
  if (pa->value < pb->value) return 1;
  if (pa->value > pb->value) return -1;
  return (int)(pb->index - pa->index);
}

void solve(int cn) {
  __int64 m = 0;
  for (int i = 0; i < N; i++) {
    a[i].index = i;
    a[i].value = v[i];
  }
  qsort(a, N, sizeof(ITEM), compareItem);
  
  // descending order of value
  // assume we have E in each step
  for (int i = 0; i < N; i++) s[i] = E;
  if (test) {
    for (int i = 0; i < N; i++) {
      printf(" value:%d index:%d s:%d\n", a[i].value, a[i].index, s[i]);
    }
  }

  for (int i = 0; i < N; i++) {
    int k = a[i].index;
    // apply all reserve 
    m += s[k] * a[i].value;
    if (test) printf("  m += %d*%d = %lld\n", s[k], a[i].value, m);
    s[k] = 0;
    // forward correction
    for (int j = k + 1; j < N; j++) {
      if (s[j] == 0) break;
      int g = std::min(E, (j-k) * R);
      if (s[j] == g) break;
      s[j] = g;
      if (test) printf("  s[%d] = %d\n", j, s[j]);
    }
    // backward correction
    for (int j = k - 1; j >= 0; j--) {
      if (s[j] == 0) break;
      int g = std::min(E, (k-j) * R);
      if (s[j] == g) break;
      s[j] = g;
      if (test) printf("  s[%d] = %d\n", j, s[j]);
    }
    if (test) {
      printf("  s: ");
      for (int j = 0; j < N; j++) {
        printf("%d ", s[j]);
      }
      printf("\n");
    }
  }
  printf("Case #%d: %lld\n", cn, m);
}

int main(int argc, char* argv[]) {
  test = false;
	// reopen("sample.in");
  reopen("B-small-attempt1.in");
  // reopen("A-large.in");
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
    scanf("%d %d %d", &E, &R, &N);
    memset(v, 0, 1000 * sizeof(int));
    for (int i = 0; i < N; i++) {
      scanf("%d", &v[i]);
    }
    showin();
    solve(tc);
  }
 	return 0;
}