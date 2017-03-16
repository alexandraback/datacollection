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
bool test = false;
bool debug = false;
const double pi=acos(-1.0);
const double eps=1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\Round1C2012A";
void reopen(char* a) {
	char input[256], output[256];
	sprintf(input, "%s\\%s", rootdir, a);
	sprintf(output, "%s\\%s", rootdir, a);
	char *p = strstr(output, ".in");
	if (p) sprintf(p, ".out"); 
	else sprintf(&p[strlen(output)], ".out");
	freopen(input,"r",stdin);
	if (!test) freopen(output,"w",stdout);
}

int T = 0;
int N = 0;
int M[1000+1][10];
int mcnt[1000+1];

void showin() {
	if (!test) return;
	printf("%d\n", N);
	for (int i = 1; i <= N; i++) {
    printf("%d ", mcnt[i]);
    for(int j = 1; j <= mcnt[i]; j++) printf("%d ", M[i][j]);
    printf("\n");
	}
}

// reverse table
vector<int> rt[1000+1];

// distance table
int d[1000+1][1000+1];

void buildrt() {
  for (int i = 1; i <= N; i++) rt[i].clear();
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= mcnt[i]; j++) {
      // i -> M[i][j]
      assert(M[i][j] >= 0);
      rt[M[i][j]].push_back(i);
    }
  }
  return;
}

void initdt() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) d[i][j] = 0;
    for (int j = 1; j <= mcnt[i]; j++) {
      d[i][M[i][j]] = 1;
    }
  }
}

void showdt() {
  for (int i = 1; i <= N; i++) {
    printf("%4d: ", i);
    for (int j = 1; j <= N; j++) {
      if (d[i][j] == 0) printf("    ");
      else printf("%3d ", d[i][j]);
    }
    printf("\n");
  }
}

void solve(int cn) {
  buildrt();
  if (debug) for (int i = 0; i < N; i++) printf("i:%d rt_size:%d\n", i+1, rt[i].size());
  initdt();
  if (debug) showdt();
  bool diamond = false;
  // all distance 1 have been taken care of, loop through distance 2...N-1
  for (int dist = 1; dist < N; dist++) {
    bool progress = false;
    // walk through all links
    for (int i = 1; i <= N; i++) {
      if (rt[i].size() == 0) continue; // no one reaches i
      for (int j = 1; j <= mcnt[i]; j++) {
        int k = M[i][j];  // link (i, k)
        // for all (m, i) + (i, k) => (m, k)
        for (int mi = 0; mi < (int)rt[i].size(); mi++) {
          int m = rt[i][mi];
          assert(d[m][i] > 0);
          if (debug) printf("dist:%d consider d(%d, %d)=%d + (%d,%d)\n", dist, m, i, d[m][i], i, k);
          if (d[m][i] != dist) continue;
          if (d[m][k] > 0) {
            if (debug) printf("(%d, %d) is diamond\n", m, k);
            diamond = true;
            break;
          }
          d[m][k] = d[m][i] + 1;
          rt[k].push_back(m); // add to reach table
          progress = true;
        }
        if (diamond) break;
      }
      if (diamond) break;
    }
    if (debug) showdt();
    if (diamond || !progress) break;
  }
  if (diamond) printf("Case #%d: Yes\n", cn);
  else printf("Case #%d: No\n", cn);
}

int main(int argc, char* argv[]) {
	reopen("A-small-attempt0.in");
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
      scanf("%d", &mcnt[i]);
      for (int j = 1; j <= mcnt[i]; j++) {
        scanf("%d", &M[i][j]);
      }
    }
    // showin();
    solve(t);
  }
 	return 0;
}