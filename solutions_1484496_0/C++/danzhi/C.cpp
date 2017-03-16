#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cstring>
// #include <cmath>
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
// #include <math.h>
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

const char rootdir[] = "C:\\CodeJam\\Round1B2012C";
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
int N = 0;
vector<__int64> s;
hash_map<__int64, int> smap;

void showin() {
	if (!test) return;
	printf("%d ", N);
	for (int i = 0; i < N; i++) {
		printf("%ld ", s[i]);
	}
  printf("\n");
}

#define checkbit(k, d) ((k >> d) & 1)

void solve() {
  sort(s.begin(), s.end());
  showin();
  int M = 1 << N;
  for (int k = 1; k < M; k++) {
    __int64 sum = 0;
    for (int d = 0; d < N; d++) { if (checkbit(k, d)) sum += s[d]; }
    if (smap.find(sum) == smap.end()) {
      smap.insert(pair<__int64, int>(sum, k));
    } else {
      int m = smap.find(sum)->second;
      // m and k are same
      for (int d = 0; d < N; d++) { if (checkbit(m, d)) printf("%ld ", s[d]); }
      printf("\n");
      for (int d = 0; d < N; d++) { if (checkbit(k, d)) printf("%ld ", s[d]); }
      printf("\n");
      return;
    }
  }
  printf("Impossible\n");
}

int main(int argc, char* argv[]) {
	reopen("C-small-attempt1.in");
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
		scanf("%d", &N);
    s.clear();
    smap.clear();
		for(int i=0; i<N; i++) {
      __int64 num = 0;
			scanf(" %ld", &num);
      assert(num > 0);
      s.push_back(num);
		}
    showin();
    
    printf("Case #%d:\n", t);
    solve();
  }
 	return 0;
}