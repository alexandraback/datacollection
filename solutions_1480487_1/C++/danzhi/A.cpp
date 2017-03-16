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

const char rootdir[] = "C:\\CodeJam\\Round1B2012A";
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
int s[200+10];

void showin() {
	if (!test) return;
	printf("%d ", N);
	for (int i = 0; i < N; i++) {
		printf("%d ", s[i]);
	}
  printf("\n");
}

void solve() {
}

int main(int argc, char* argv[]) {
	reopen("A-large.in");
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			scanf("%d", &s[i]);
		}
    showin();
    printf("Case #%d: ", t);
    double x = 0;
    for(int i=0; i<N; i++) x += s[i];
    double p[200+10];
    for(int i=0; i < N; i++) p[i] = 2.0/N - s[i] / x;
    int m = 0;
    double y = 0;
    for(int i=0; i < N; i++) if (p[i] < eps) { m++; y += s[i]; }
    // exclude m persons
    double sum = 2 * x - y;
    double num = N - m;
    assert(num > 0);
    for(int i=0; i < N; i++) {
      double r = (p[i] < eps)? 0 : (sum / num - s[i]) / x;
      printf("%9.6f ", 100 * r);
    }
    printf("\n");
  }
 	return 0;
}