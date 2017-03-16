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
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
bool test = false;
const double pi=acos(-1.0);
const double eps=1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\DeceitfulWar";
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
double nb[1000];
double kb[1000];
vector<double> naomi;
vector<double> ken;

void showin() {
  if (!test) return;
  printf("%d\n", N);
  for (int i = 0; i < N; i++) {
    printf("%.5f ", nb[i]);
  }
  printf("\n");
  for (int i = 0; i < N; i++) {
    printf("%.5f ", kb[i]);
  }
  printf("\n");
}

int main() {
  // test = true;
  // reopen("sample.in");
  // reopen("D-small-attempt0.in");
  reopen("D-large.in");
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    naomi.clear();
    ken.clear();
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%lf", &nb[i]);
      naomi.push_back(nb[i]);
    }
    for (int i = 0; i < N; i++) {
      scanf("%lf", &kb[i]);
      ken.push_back(kb[i]);
    }
    showin();
    
    std::sort(naomi.begin(), naomi.end());
    std::sort(ken.begin(), ken.end());
    assert(naomi.size() == ken.size());
    int len = naomi.size();

    int in = len-1;  // decreasing index on naomi vector
    int ik = len-1;  // decreasing index on ken vector
    //       naomi ken
    //        186  215
    //        300  271
    //        389  341
    //        557  458
    //        832  520
    //        899  521
    // in --> 907  700
    //        959  728
    //        992  916 <-- ik
    int nwin = 0;
    while (in >= 0 && ik >= 0) {
      if (naomi[in] > ken[ik]) {
        nwin++;
        in--;
      } else {
        assert(naomi[in] < ken[ik]);
        in--;
        ik--;
      }
    }
    // walk through all naomi numbers in increasing order.
    // low and high are indexes on ken numbers.
    int low = 0;
    int high = len-1;
    int dwin = 0;
    // idx is increasing index on naomi
    for (int idx = 0; idx < len; idx++) {
      assert(low <= high);
      if (naomi[idx] < ken[low]) {
        // naomi lose due to smallest number but will cost 
        // ken's largest in deceitful war.
        high--;
      } else {
        // confirm all numbers are different.
        assert(naomi[idx] > ken[low]); 
        // naomi will deceitfully claim that the number is bigger 
        // then ken[high] so that ken will use ken[low] instead.
        dwin++;
        low++;
      }
    }
    assert(low == high + 1);
    printf("Case #%d: %d %d\n", t, dwin, nwin);
  }
  return 0;
}