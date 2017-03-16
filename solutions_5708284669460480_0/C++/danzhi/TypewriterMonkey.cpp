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
#include <fstream>
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

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

#define M_PI 3.14159265358979323846

bool test = false;
const double pi=acos(-1.0);
const double eps=1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\TypewriterMonkey";
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

int T;
int K;
int L;
int S;

char ka[128];  // keyboard letters total K
char la[128];  // target word with length L

int kc[26];

int getRepLen() {
  for (int i = 1; i <= L; i++) {
    if (memcmp(la, &la[i], L-i) == 0) return i;
  }
  return L;
}

int getMax() {
  for (int i = 0; i < 26; i++) kc[i] = 0;
  for (int i = 0; i < K; i++) kc[ka[i]-'A']++;
  for (int i = 0; i < L; i++) {
    if (kc[la[i]-'A'] == 0) return 0;
  }

  int rlen = getRepLen();
  return (S - (L - rlen))/rlen;
}

double countWord(char buf[], int s) {
  int output = 0;
  if (s == S) {
    char *p = buf;
    while (p < buf + s) {
      char *q = strstr(p, la);
      if (q == NULL) break;
      p = q + 1;
      output++;
    }
    return output;
  }
  // each position has K choices
  for (int j = 0; j < K; j++) {
    buf[s] = ka[j];
    output += countWord(buf, s+1);
  }
  return output;
}

double solveSmall() {
  int m = getMax();
  if (m == 0) return 0;
  char buf[256];
  memset(buf, 0, 256);
  int total = countWord(buf, 0);
  double exp = total;
  for (int i = 0; i < S; i++) exp /= K;
  double output = m;
  return output - exp;
}

int main() {
  test = false;
  reopen("sample.in");
  reopen("B-small-attempt0.in");
  // reopen("C-small-practice-2.in");
  // reopen("C-large-practice.in");
  scanf("%d", &T);
  for (int TC = 1; TC <= T; TC++) {
    scanf("%d %d %d", &K, &L, &S);
    scanf("%s", ka);
    scanf("%s", la);

    // K: [1,7] L/S:[1,7]
    if (test) {
      printf("%d %d %d\n", K, L, S);
      printf("%s\n", ka);
      printf("%s\n", la);
    }

    double output = solveSmall();
    printf("Case #%d: %10.7f\n", TC, output);
  }
  return 0;
}