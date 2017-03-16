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

const char rootdir[] = "C:\\CodeJam\\Osmos";
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
int A = 0;
int N = 0;
int m[100 + 10];

void showin() {
	if (!test) return;
  printf("%d %d\n", A, N);
  for (int i = 0; i < N; i++) {
    printf("%d ", m[i]);
  }
  printf("\n");
}

int compareInt(const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

// recursively get steps
int getSteps(int sum, int index) {
  if (sum == 1) return N - index;
  for (int i = index; i < N; i++) {
    if (sum > m[i]) {
      sum += m[i];
      continue;
    }
    int numDel = N - i;
    int numAdd = 0;
    int tmp = sum;
    while (true) {
      tmp = 2 *tmp-1;
      numAdd++;
      if (tmp > m[i]) break;
    }
    if (numAdd >= numDel) {
      return numDel;
    }
    sum = tmp + m[i];
    int step = numAdd + getSteps(sum, i + 1);
    return std::min(step, numDel);
  }
  return 0;
}

void solve(int cn) {
  qsort(m, N, sizeof(int), compareInt);
  // showin();
  int steps = getSteps(A, 0);
  printf("Case #%d: %d\n", cn, steps);
}

int main(int argc, char* argv[]) {
  test = false;
	// reopen("sample.in");
  reopen("A-small-attempt1.in");
  // reopen("A-large.in");
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
    scanf("%d %d", &A, &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &m[i]);
    }
    // showin();
    solve(tc);
  }
 	return 0;
}